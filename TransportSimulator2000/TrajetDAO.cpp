/*************************************************************************
                           TrajetDAO  -  Classe responsable de la sauvegarde et du chargement des objets Trajet
                             -------------------
    début                : 13/12/2016
    copyright            : (C) 2016 par Lucas POISSE (le seul, l'unique)
    e-mail               : poisse.lucas@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <TrajetDAO> (fichier TrajetDAO.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <assert.h>				//Include assertions

//------------------------------------------------------ Include personnel

#include "TrajetDAO.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

	void TrajetDAO::SerializeCatalogIndex(Catalogue & catToSave,unsigned int min,unsigned int max)
	{
		serialize(catToSave.PrintRaw(min,max));
	}//--- Fin de SerializeCatalogIndex
	void TrajetDAO::SerializeCatalogTrajetsComposes(Catalogue & catToSave)
	{
		serialize(catToSave.PrintRawComposes());
		
	}		//--- Fin de SerializeCatalogTrajetsSimples
	
	void TrajetDAO::SerializeCatalogTrajetsSimples(Catalogue & catToSave)
	{
		serialize(catToSave.PrintRawSimples());
		
	}		//--- Fin de SerializeCatalogTrajetsSimples
	
	void TrajetDAO::SerializeCatalogFromTo(Catalogue & catToSave,const char *depart,const char * arrivee)
	{
		serialize(catToSave.PrintRawFromTo(depart, arrivee));
		
	}		//--- Fin de SerializeCatalogFromTo


	void TrajetDAO::SerializeAllCatalog(Catalogue & catToSave)
	{
		serialize(catToSave.PrintRaw());

	}		//--- Fin de SerializeAllCatalog

	void TrajetDAO::SerializeTrajet(Trajet * trajet)
	{
		
		serialize(trajet->PrintRaw());
	}		

	
	void TrajetDAO::DeleteSaves()
	{
		if(outputStream)
		{
			outputStream.close();
			outputStream.open(filename, std::ofstream::out | std::ofstream::trunc);
			outputStream.close();
			outputStream.open(filename, ios_base::app);
		}
	}  // ---Fin de DeleteSaves
	
	
	int TrajetDAO::LoadAll(Catalogue & cat) 
	{
		int nbTrajets = 0;
		string str;
		inputStream.clear();
		inputStream.seekg(0, ios::beg);
		
		while(getline(inputStream,str))
		{
			int nbTrajetsSimples = atoi(str.c_str());
			if(nbTrajetsSimples==0)
			{								
				if(!instantiateTrajetSimple(cat))
					break;
			}
			else {
				if(!instantiateTrajetCompose(cat, nbTrajetsSimples))
					break;
			}
			nbTrajets++;
		}
		return nbTrajets;
	}  // -- Fin de LoadAll
	
	int TrajetDAO::LoadSimple(Catalogue & cat) 
	{
		inputStream.clear();
		inputStream.seekg(0, ios::beg);
		
		int nbTrajets = 0;
		string str;
		while(getline(inputStream,str))
		{
			int nbTrajetsSimples = atoi(str.c_str());
			if(nbTrajetsSimples == 0)				//Chargement d'un trajet Simple => OK	
			{
				if(!instantiateTrajetSimple(cat))
					break;
				nbTrajets++;
			}
			else {								//Chargement d'un trajet composé => ignoré
				for(int i=0;i< (4*nbTrajetsSimples)+2;i++, getline(inputStream, str));		//Boucle for vide : ignore les TC
			}
		}
		return nbTrajets;
	} //---- Fin de LoadSimple
	
	
	int TrajetDAO::LoadComposes(Catalogue & cat) 
	{
		inputStream.clear();
		inputStream.seekg(0, ios::beg);
		
		int nbTrajets = 0;
		string str;
		while(getline(inputStream,str))
		{
			int nbTrajetsSimples = atoi(str.c_str());
			if(nbTrajetsSimples != 0)				//Chargement d'un trajet composé => OK	
			{
				if(!instantiateTrajetCompose(cat, nbTrajetsSimples))
					break;
				nbTrajets++;
				
			}
			else {								//Chargement d'un trajet simple => ignoré
				for(int i=0;i<3;i++, getline(inputStream, str));		//Boucle for vide : ignore les TS
			}
		}
		return nbTrajets;
	} // ----- Fin de LoadComposes
	
	int TrajetDAO::LoadVille(Catalogue & cat,const char* villeDep,const char* villeArr) 
	{
		int nbTrajets = 0;
		string str;
		inputStream.clear();
		inputStream.seekg(0, ios::beg);
		
		while(getline(inputStream,str))
		{
			int nbTrajetsSimples = atoi(str.c_str());
			
			int codeInstantiate;
			if(nbTrajetsSimples==0)
			{								
				if(!(codeInstantiate = instantiateTrajetSimple(cat, villeDep, villeArr)))
					break;
			}
			else {
				if(!(codeInstantiate = instantiateTrajetCompose(cat, nbTrajetsSimples, villeDep, villeArr)))
					break;
			}
			if(codeInstantiate != -1)				//Trajet non conforme à la condition de ville
				nbTrajets++;
		}
		return nbTrajets;
	}
	
	int TrajetDAO::LoadInterval(const int min, const int max, Catalogue & cat) 
	{
		int nbTrajets = 0;
		string str;
		inputStream.clear();
		inputStream.seekg(0, ios::beg);
		int nbTrajetsSimples;
		 int i;
		for(i=0;i<min;i++)						//Passe les min premiers trajets
		{
			getline(inputStream,str);
			nbTrajetsSimples = atoi(str.c_str());
			if(nbTrajetsSimples == 0)
			{
				for(int j=0;j<3;j++, getline(inputStream, str));		//Boucle for vide : passe un TS
			}
			else
			{
				for(int j=0;j< (4*nbTrajetsSimples)+2;j++, getline(inputStream, str));	//Boucle for vide : passe un TC
			}
		}
		for(i=min;i<=max;i++)						//Chargement des Trajets dans l'intervalle [min;max]
		{
			if(!getline(inputStream,str))
				break;
			
			nbTrajetsSimples = atoi(str.c_str());
			if(nbTrajetsSimples == 0)
			{
				if(!instantiateTrajetSimple(cat))
					break;
				nbTrajets++;
			}
			else 
			{
				if(!instantiateTrajetCompose(cat, nbTrajetsSimples))
					break;
				nbTrajets++;
			}
		}
		assert(nbTrajets <= (max-min)+1);
		return nbTrajets;
	}
	
	int TrajetDAO::instantiateTrajetSimple(Catalogue & cat, const char* villeDep, const char* villeArr)
	{
		char* vDep;
		char* vArr;
		int i;
		string vDepstr;
		if(!getline(inputStream, vDepstr))
			return 0;
		
		vDepstr.erase(vDepstr.size() - 1);							 
		vDep = new char[strlen(vDepstr.c_str()) + 1];				
		strcpy(vDep, vDepstr.c_str());
		if(villeDep!=nullptr && strcmp(vDep, villeDep))
		{
			delete[] vDep;
			for(i=0;i<2;i++, getline(inputStream, vDepstr));	//On passe les lignes inutiles
			return -1;		//-1 : le TS ne répond pas à la condition de ville
		}
		string vArrstr;
		if(!getline(inputStream, vArrstr)){
			delete[] vDep;
			return 0;
		}
			
		vArrstr.erase(vArrstr.size() - 1);
		vArr = new char[strlen(vArrstr.c_str()) + 1];
		strcpy(vArr, vArrstr.c_str());
		if(villeArr!=nullptr && strcmp(vArr, villeArr))
		{
			delete[] vDep;
			delete[] vArr;
			getline(inputStream, vArrstr);		
			return -1;		
		}
		string transpStr;
		if(!getline(inputStream, transpStr))
		{
			delete[] vDep;
			delete[] vArr;
			return 0;
		}
		int numTransport=atoi(transpStr.c_str());
		if(numTransport>7)
		{
			numTransport=7;
		}
		Transport t = static_cast<Transport>(numTransport);
		Trajet* ts = new TrajetSimple(vDep, vArr, t);
		cat.AddTrajet(ts);
		delete ts;		
		delete[] vDep;
		delete[] vArr;

		return 1;
	}
	
	int TrajetDAO::instantiateTrajetCompose(Catalogue & cat, int nbTrajetsSimples, const char* villeDep, const char* villeArr)
	{
		char* vDep;
		char* vArr;
		int i;
		string vDepstr;
		if(!getline(inputStream, vDepstr))
			return 0;		//Erreur de lecture
			
		vDepstr.erase(vDepstr.size() - 1);							 
		vDep = new char[strlen(vDepstr.c_str()) + 1];				
		strcpy(vDep, vDepstr.c_str());
			
		
		if(villeDep!=nullptr && strcmp(vDep, villeDep))
		{
			delete[] vDep;
			for(i=0;i<4*nbTrajetsSimples+1;i++, getline(inputStream, vDepstr));		//Passage des trajets inutiles
			return -1;		//-1 : le TC ne répond pas à la condition de ville
		}
		
		string vArrstr;
		if(!getline(inputStream, vArrstr)){
			delete[] vDep;
			return 0;			//Erreur de lecture
		}
			
		vArrstr.erase(vArrstr.size() - 1);
		vArr = new char[strlen(vArrstr.c_str()) + 1];
		strcpy(vArr, vArrstr.c_str());
	
		if(villeArr!=nullptr && strcmp(vArr, villeArr))
		{
			delete[] vDep;
			delete[] vArr;
			for(i=0;i<4*nbTrajetsSimples;i++, getline(inputStream, vDepstr));			//Passage des trajets inutiles
			return -1;				
		}
		
		TrajetCompose* tc = new TrajetCompose();
		for(int i=0;i<nbTrajetsSimples;i++)			//Chargement de tous les TS
		{
			char* vDepSimple;
			char* vArrSimple;			
			
			string vDepstrSimple;
			for(int j=0;j<2;j++)
			{
				if(!getline(inputStream, vDepstrSimple))
				{
					delete[] vDep;
					delete[] vArr;
					delete tc;				//Erreur de lecture
					return 0;
				}
			}
							
			vDepstrSimple.erase(vDepstrSimple.size() - 1);							  
			vDepSimple = new char[strlen(vDepstrSimple.c_str()) + 1];				
			strcpy(vDepSimple, vDepstrSimple.c_str());
			
			string vArrstrSimple;
			
			if(!getline(inputStream, vArrstrSimple))
			{
				delete[] vDep;
				delete[] vArr;						//Erreur de lecture
				delete tc;
				delete[] vDepSimple;
				return 0;
			}
			
			vArrstrSimple.erase(vArrstrSimple.size() - 1);
			vArrSimple = new char[strlen(vArrstrSimple.c_str()) + 1];
			strcpy(vArrSimple, vArrstrSimple.c_str());
			
			string transpStr;
			if(!getline(inputStream, transpStr))
			{
				delete[] vDep;
				delete[] vArr;
				delete tc;								//Erreur de lecture
				delete[] vDepSimple;
				delete[] vArrSimple;
				return 0;
			}
			int numTransport=atoi(transpStr.c_str());
			if(numTransport>7)
			{
				numTransport=7;
			}
			Transport t = static_cast<Transport>(numTransport);
		//	Transport t = static_cast<Transport>(atoi(transpStr.c_str()));
			
			Trajet* ts = new TrajetSimple(vDepSimple, vArrSimple, t);
			tc->AddTrajet(ts);
			
			delete ts;						//Le TS est supprimé car TrajetCompose::AddTrajet ajoute une copie de celui-ci
			delete[] vDepSimple;
			delete[] vArrSimple;
		}
		
		cat.AddTrajet(tc);				//Ajout du TC
		delete tc;
		delete[] vDep;
		delete[] vArr;
		
		return 1;
	}


 //Surcharge de l'affectation d'un TrajetDAO
    TrajetDAO & TrajetDAO::operator = ( const TrajetDAO & unTrajetDAO)
    {
		#ifdef MAP
			cout << "Surcharge de l'affectation de <TrajetDAO>" << endl;
		#endif
	/*	
		if(unTrajetDAO != *this)
		{
			this->filename = unTrajetDAO.filename;
			inputStream.open(filename);
			outputStream.open(filename);
		}*/
		
		return (*this);
	}					

//-------------------------------------------- Constructeurs - destructeur
		
	//Construction par copie d'un TrajetDAO
	TrajetDAO::TrajetDAO ( const TrajetDAO & unTrajetDAO) : filename(unTrajetDAO.filename)
	{
		#ifdef MAP
			cout << "Construction par copie d'un <TrajetDAO>" << endl;
		#endif
		inputStream.open(filename);
		outputStream.open(filename, ios_base::app);
	}
		
// Constructeur par défaut
TrajetDAO::TrajetDAO (string filename)
{
	#ifdef MAP
		cout << "Appel au constructeur de <TrajetDAO>" << endl;
	#endif
	this->filename = filename;
	inputStream.open(filename);
	outputStream.open(filename, ios_base::app);
	
} //----- Fin de TrajetDAO



//Destructeur de la classe
TrajetDAO::~TrajetDAO ()
{
	#ifdef MAP
		cout << "Appel au destructeur de <TrajetDAO>" << endl;
	#endif
	inputStream.close();
	outputStream.close();
} //----- Fin de ~TrajetDAO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
	void TrajetDAO::serialize(string stringToSave)
	{
		if (outputStream)
		{
			const char *cstr = stringToSave.c_str();
			outputStream.write(cstr, sizeof(char)*stringToSave.size());
		}
		outputStream.flush();
		
	}//--- Fin de SerializeTrajet
