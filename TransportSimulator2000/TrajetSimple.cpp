
/*************************************************************************
                           TrajetSimple  -  classe représentant un TrajetSimple
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
     
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#define MAP
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel

#include "TrajetSimple.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::ToString()
{
	cout << "Trajet reliant la ville " << villeDepart<< " a la ville " << villeArrivee << endl;
}  // --- Fin de ToString


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple::TrajetSimple (constructeur de copie)

//Constructeur paramétré
 TrajetSimple::TrajetSimple(const char* villeDep, const char* villeArr, const Transport transp )
 {
	 
	 #ifdef MAP
		cout << "Appel au constructeur paramétré de <TrajetSimple>" << endl;
	#endif

	 this->villeDepart = new char[strlen(villeDep) + 1];
	 strcpy(this->villeDepart, villeDep);
	 
	 this->villeArrivee = new char[strlen(villeArr) + 1];
	 strcpy(this->villeArrivee, villeArr);
	 
	 this->transportUtilise = transp;
	 
 }  //--- Fin du constructeur
 
 
TrajetSimple::TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

