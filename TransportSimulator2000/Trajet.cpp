
/*************************************************************************
                           Trajet  -  classe représentant un trajet abstrait
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
     
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#define MAP
#include <iostream>
#include <cstring>


//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

bool Trajet::CheckIfGoesFrom(const char* ville)const
{
return true;
}

 bool Trajet::CheckIfGoesTo(const char* ville)const
 {
 	return false;
 }

 bool Trajet::CheckIfGoesFromTo(const char* ville1, const char* ville2) const
 {
	 return true;
	 
 }  // ------ Fin de checkIfGoesTo
    
	
	
//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
	this->villeDepart = new char[strlen(unTrajet.villeDepart) + 1];
	strcpy(this->villeDepart, unTrajet.villeDepart);
	
	this->villeArrivee = new char[strlen(unTrajet.villeArrivee) + 1];
	strcpy(this->villeArrivee, unTrajet.villeArrivee);
	
} //----- Fin de Trajet::Trajet (constructeur de copie)


Trajet::Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur sans paramètres de <Trajet>" << endl;
#endif
this->villeDepart=new char[strlen("INCONNNU") + 1];
strcpy(this->villeDepart, "INCONNNU");
this->villeArrivee=new char[strlen("INCONNU") + 1];
strcpy(this->villeArrivee, "INCONNU");
} //----- Fin de Trajet

Trajet::Trajet(const char* villeDep, const char* villeArr)
{
	#ifdef MAP
    cout << "Appel au constructeur paramétré de <Trajet>" << endl;
	#endif
	this->villeDepart = new char[strlen(villeDep) + 1];
	strcpy(this->villeDepart, villeDep);
	
	this->villeArrivee = new char[strlen(villeArr) + 1];
	strcpy(this->villeArrivee, villeArr);
	
	
}  //-- Fin du constructeur paramétré



Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
	
	delete[] this->villeDepart;
	delete[] this->villeArrivee;

} //----- Fin de ~Trajet



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

