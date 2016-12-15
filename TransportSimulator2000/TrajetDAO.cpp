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

//------------------------------------------------------ Include personnel

#include "TrajetDAO.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

	void TrajetDAO::Serialize(string rawString)
	{
		if (outputStream)
		{
			const char *cstr = rawString.c_str();
			outputStream.write(cstr, sizeof(char)*rawString.size());
		}
		outputStream.flush();
	}		//--- Fin de Serialize
	
	
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
	}
	
	
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
			else {								//Chargement d'un trajet composé => ignoré
				for(int i=0;i<3;i++, getline(inputStream, str));		//Boucle for vide : ignore les TS
			}
		}
		return nbTrajets;
	}
	
	int TrajetDAO::LoadVille(Catalogue & cat, const char* villeDep, const char* villeArr) 
	{
		return 0;
	}
	
	int TrajetDAO::LoadInterval(const int min, const int max, Catalogue & cat) 
	{
		return 0;
	}
	
	int TrajetDAO::instantiateTrajetSimple(Catalogue & cat)
	{
		char* vDep;
		char* vArr;
		string vDepstr;
		if(!getline(inputStream, vDepstr))
			return 0;
		
		vDepstr.erase(vDepstr.size() - 1);							 
		vDep = new char[strlen(vDepstr.c_str()) + 1];				
		strcpy(vDep, vDepstr.c_str());
		
		string vArrstr;
		if(!getline(inputStream, vArrstr)){
			delete[] vDep;
			return 0;
		}
			
		vArrstr.erase(vArrstr.size() - 1);
		vArr = new char[strlen(vArrstr.c_str()) + 1];
		strcpy(vArr, vArrstr.c_str());
	
		string transpStr;
		getline(inputStream, transpStr);
		Transport t = static_cast<Transport>(atoi(transpStr.c_str()));
			
		Trajet* ts = new TrajetSimple(vDep, vArr, t);
		cat.AddTrajet(ts);
		delete ts;		
		delete[] vDep;
		delete[] vArr;

		return 1;
	}
	
	int TrajetDAO::instantiateTrajetCompose(Catalogue & cat, int nbTrajetsSimples)
	{
		char* vDep;
		char* vArr;
		string vDepstr;
		if(!getline(inputStream, vDepstr))
			return 0;		//Erreur de lecture
			
		vDepstr.erase(vDepstr.size() - 1);							 
		vDep = new char[strlen(vDepstr.c_str()) + 1];				
		strcpy(vDep, vDepstr.c_str());
			
		string vArrstr;
		if(!getline(inputStream, vArrstr)){
			delete[] vDep;
			return 0;			//Erreur de lecture
		}
			
		vArrstr.erase(vArrstr.size() - 1);
		vArr = new char[strlen(vArrstr.c_str()) + 1];
		strcpy(vArr, vArrstr.c_str());
		
		TrajetCompose* tc = new TrajetCompose();
		for(int i=0;i<nbTrajetsSimples;i++)			//Chargement de tous les TS
		{
			char* vDepSimple;
			char* vArrSimple;			
			
			string vDepstrSimple;
			getline(inputStream, vDepstrSimple);
			getline(inputStream, vDepstrSimple);				
			vDepstrSimple.erase(vDepstrSimple.size() - 1);							  
			vDepSimple = new char[strlen(vDepstrSimple.c_str()) + 1];				
			strcpy(vDepSimple, vDepstrSimple.c_str());
			
			string vArrstrSimple;
			getline(inputStream, vArrstrSimple);
			vArrstrSimple.erase(vArrstrSimple.size() - 1);
			vArrSimple = new char[strlen(vArrstrSimple.c_str()) + 1];
			strcpy(vArrSimple, vArrstrSimple.c_str());
			
			string transpStr;
			getline(inputStream, transpStr);
			Transport t = static_cast<Transport>(atoi(transpStr.c_str()));
			
			Trajet* ts = new TrajetSimple(vDepSimple, vArrSimple, t);
			tc->AddTrajet(ts);
			
			delete ts;
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
		
	/*	if(unTrajetDAO != *this)
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

