
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


void Trajet::transportToString( const Transport transportAAfficher) const
{
	switch(transportAAfficher)
	{
		case(Avion):
		cout<<"Avion";
		break;
		case(Automobile):
		cout<<"Automobile";
		break;
		case(Tank):
		cout<<"Tank";
		break;
		case(Canard_geant):
		cout<<"Canard géant";
		break;
		case(Tramway):
		cout<<"Tramway";
		break;
		case(Bateau):
		cout<<"Bateau";
		break;
		case(DosDeMathieuMaranzana):
		cout<<"Missile Nord Coréen";
		break;
	}
}
 bool Trajet::CheckIfGoesTo(const char* ville1, const char* ville2)
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
} //----- Fin de Trajet::Trajet (constructeur de copie)


Trajet::Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
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

