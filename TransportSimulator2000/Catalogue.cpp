
/*************************************************************************
                           Trajet  -  classe représentant un Catalogue
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
     
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#define MAP
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Catalogue::ToString() const
{
	this->listeTrajets->ToString();
}
 void Catalogue::AddTrajet(const Trajet* unTrajet)
 {
	 this->listeTrajets->AddT(unTrajet);
 } //----- Fin de addTrajet
 
 void Catalogue::AddTrajet(const Trajet & unTrajet)
 {
	 this->listeTrajets->AddT(unTrajet);
 } //----- Fin de addTrajet
 

 int Catalogue::CheckTrajet(const char* const ville1, const char* ville2) const
 {
	 return listeTrajets->CheckTrajet(ville1,ville2);
 } //----- Fin de checkTrajet
 
 int Catalogue::CheckTrajetComplexe(const char* ville1, const char* ville2) const
 {
	 return listeTrajets->afficheTrajetsRechercheComplexe(ville1, ville2);
 }
 
//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
this->listeTrajets= new ListeTrajets(*(unCatalogue.listeTrajets));
} //----- Fin de Catalogue::Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
listeTrajets = new ListeTrajets();
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete listeTrajets;
} //----- Fin de ~Catalogue




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

