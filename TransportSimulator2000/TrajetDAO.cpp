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

//------------------------------------------------------ Include personnel
#include "TrajetDAO.h"
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

	void TrajetDAO::serialize(string rawString, bool append) const
	{
		
		
	}
	
	
	int TrajetDAO::loadAll(Catalogue & cat) const
	{
		return 0;
	}
	
	int TrajetDAO::loadSimple(Catalogue & cat) const
	{
		return 0;
	}
	
	int TrajetDAO::loadComposes(Catalogue & cat) const
	{
		return 0;
	}
	
	int TrajetDAO::loadVille(Catalogue & cat, const char* villeDep, const char* villeArr) const
	{
		return 0;
	}
	
	int TrajetDAO::loadInterval(const int min, const int max, Catalogue & cat) const
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
		outputStream.open(filename);
	}
		
// Constructeur par défaut
TrajetDAO::TrajetDAO (string filename)
{
	#ifdef MAP
		cout << "Appel au constructeur de <TrajetDAO>" << endl;
	#endif
	this->filename = filename;
	inputStream.open(filename);
	outputStream.open(filename);
	
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

