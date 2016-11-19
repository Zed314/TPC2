
/*************************************************************************
                           TrajetCompose  -  classe représentant un TrajetCompose 
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
     
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#define MAP
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "ListeTrajets.h"
#include "Trajet.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
Trajet * TrajetCompose::Clone() const
 {
 	 	#ifdef MAP

    cout << "Appel au Clone() de TrajetCompose." << endl;

	#endif
 	
 return new TrajetCompose(*this);
 }// --- Fin de Clone

void TrajetCompose::AddTrajet(const TrajetSimple  & trajetSimpleToAdd)
  {

	//Pas conçu pour la suppression
	if(this->PeutServirDeBaseA(trajetSimpleToAdd)||listeDesTrajets->EstVide())
		{
		this->MaJArrivee(trajetSimpleToAdd);
	  	listeDesTrajets->AddT(trajetSimpleToAdd);
	  }
	  else
	
		{
			cout<<"Ajout impossible! La fin du trajet actuel ne coïncide pas avec le début du trajet que l'on souhaite ajouter!"<<endl;
		}

  }   // --- Fin de AddTrajet
	

    void TrajetCompose::ToString() const
	{
		cout<<"Trajet composé part de "<<villeDepart<<" et va à "<<villeArrivee<<" suivant ce chemin: "<<endl;
		
		listeDesTrajets->ToString();
		
	}  // --- Fin de ToString

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose ):Trajet(unTrajetCompose)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
this->listeDesTrajets= new ListeTrajets(*(unTrajetCompose.listeDesTrajets));
} //----- Fin de TrajetCompose::TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose (const char* villeDep, const char* villeArr,Transport transportUtilise):Trajet(villeDep,villeArr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur paramétré de <TrajetCompose>" << endl;
#endif
TrajetSimple trajetAAjouter(villeDep,villeArr,transportUtilise);
listeDesTrajets=new ListeTrajets();
AddTrajet(trajetAAjouter);

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose (const TrajetSimple &unTrajetSimple):Trajet(unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur paramétré avec un TrajetSimple de <TrajetCompose>" << endl;
#endif
listeDesTrajets=new ListeTrajets();
AddTrajet(unTrajetSimple);

} //----- Fin de TrajetCompose




TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
delete listeDesTrajets;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

