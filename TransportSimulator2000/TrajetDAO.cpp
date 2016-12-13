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
#define MAP
#include "TrajetDAO.h"
#include "Catalogue.h"
#include "Trajet.h"

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
		
		
		while(getline(inputStream,str))
		{
			if(atoi(str.c_str()) == 0)
			{
				
				char* vDep;
				string vDepstr;
				getline(inputStream, vDepstr);
				vDepstr.erase(vDepstr.size() - 1);							//"Les retours chariot, c'est le cancer."   
				vDep = new char[strlen(vDepstr.c_str()) + 1];				//                      Abraham Lincoln
				strcpy(vDep, vDepstr.c_str());
				
				char* vArr;
				string vArrstr;
				getline(inputStream, vArrstr);
				vArrstr.erase(vArrstr.size() - 1);
				vArr = new char[strlen(vArrstr.c_str()) + 1];
				strcpy(vArr, vArrstr.c_str());
								
				string transpStr;
				getline(inputStream, transpStr);
				Transport t = static_cast<Transport>(atoi(transpStr.c_str()));

				
				Trajet* ts = new TrajetSimple(vDep, vArr, t);
				cat.AddTrajet(ts);
				nbTrajets++;
			}
		}
		
		return nbTrajets;
	}// -- Fin de LoadAll
	
	int TrajetDAO::LoadSimple(Catalogue & cat) 
	{
		return 0;
	}
	
	int TrajetDAO::LoadComposes(Catalogue & cat) 
	{
		return 0;
	}
	
	int TrajetDAO::LoadVille(Catalogue & cat, const char* villeDep, const char* villeArr) 
	{
		return 0;
	}
	
	int TrajetDAO::LoadInterval(const int min, const int max, Catalogue & cat) 
	{
		return 0;
	}


 //Surcharge de l'affectation d'un TrajetDAO
    TrajetDAO & TrajetDAO::operator = ( const TrajetDAO & unTrajetDAO)
    {
		#ifdef MAP
			cout << "Surcharge de l'affectation de <TrajetDAO>" << endl;
		#endif
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

