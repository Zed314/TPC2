
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

void TrajetSimple::ToString() const
{

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


//Constructeur paramétré
 TrajetSimple::TrajetSimple(const char* villeDep, const char* villeArr, const Transport transp ): Trajet (villeDep,villeArr),transportUtilise(transp) 
 {
	 
	 #ifdef MAP
		cout << "Appel au constructeur paramétré de <TrajetSimple>" << endl;
	#endif
	 
 }  //--- Fin du constructeur
 
 /*
TrajetSimple::TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple
*/

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

