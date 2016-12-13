/*************************************************************************
                           TrajetDAO  -  Classe responsable de la sauvegarde et du chargement des objets Trajet
                             -------------------
    début                : 13/12/2016
    copyright            : (C) 2016 par Lucas POISSE
    e-mail               : poisse.lucas@gmail.com
*************************************************************************/

//---------- Interface de la classe <TrajetDAO> (fichier TrajetDAO.h) ----------------
#if ! defined ( TRAJETDAO_H )
#define TRAJETDAO_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <fstream>
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetDAO>
//	Classe responsable de la sauvegarde et du chargement des objets Trajet
//
//------------------------------------------------------------------------

class TrajetDAO
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


void Serialize(string rawString, bool append=true) ;
// Sauvegarde la chaîne de caractères correspondant aux caractéristiques du trajet dans le fichier de sauvegarde

int LoadAll(Catalogue & cat) ;
// Charge tous les éléments du fichier de sauvegarde en mémoire

int LoadSimple(Catalogue & cat) ;
// Charge tous les éléments de type 'trajet simple' en mémoire

int LoadComposes(Catalogue & cat) ;
// Charge tous les éléments de type 'trajet composé' en mémoire

int LoadVille(Catalogue & cat, const char* villeDep, const char* villeArr) ;
// Charge en mémoire tous les trajets dont la ville de départ et d'arrivée correspondent avec les paramètres indiqués

int LoadInterval(const int min, const int max, Catalogue & cat);
// Charge en mémoire tous les trajets sauvegardés dans l'intervalle donné

//------------------------------------------------- Surcharge d'opérateurs
    
    //Surcharge de l'affectation d'un TrajetDAO
    TrajetDAO & operator = ( const TrajetDAO & unTrajetDAO);

//-------------------------------------------- Constructeurs - destructeur
    TrajetDAO ( const TrajetDAO & unTrajetDAO);
    // Mode d'emploi (constructeur de copie) : effectue la construction de l'objet à partir du TrajetDAO passé en paramètre

    TrajetDAO(string filename = "save.txt");
    // Mode d'emploi : effectue la construction par défaut d'un objet TrajetDAO. 
    // Un autre paramètre correspondant au nom de fichier de sauvegarde peut être spécifié

    virtual ~TrajetDAO ( );
    // Mode d'emploi : Destruction du TrajetDAO

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	string filename;
	std::ifstream inputStream;
	std::ofstream outputStream;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TrajetDAO>

#endif // TRAJETDAO_H

