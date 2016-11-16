
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
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple::ToString() const
{
	//enum Transport { Avion, Automobile, Tank, Canard_geant, Tramway, Bateau, DosDeMathieuMaranzana };
	cout<<"de "<<villeDepart<<" à "<<villeArrivee<<" en ";
	this->transportToString(transportUtilise);
	cout<<endl;
	
}  // --- Fin de ToString


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple::TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple (const char* villeDep, const char* villeArr,Transport transportDuTrajet) : Trajet (villeDep,villeArr),transportUtilise(transportDuTrajet) 
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

