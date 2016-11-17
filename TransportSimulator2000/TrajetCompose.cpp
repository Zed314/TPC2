
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


  void TrajetCompose::AddTrajet(const TrajetSimple  & trajetSimpleToAdd)
  {

	//Pas conçu pour la suppression
	if(this->PeutServirDeBaseA(trajetSimpleToAdd)||listeDesTrajets.EstVide())
		{
		this->MaJArrivee(trajetSimpleToAdd);
		TrajetSimple * pointeurVersNouveauTrajet=new TrajetSimple(trajetSimpleToAdd);
	  	listeDesTrajets.AddT(pointeurVersNouveauTrajet);
	  }
	  else
	
		{
			cout<<"Ajout impossible! La fin du trajet actuel ne coïncide pas avec le début du trajet que l'on souhaite ajouter!"<<endl;
		}
	  //listeDesTrajets.AddT(trajetToAdd);
  }   // --- Fin de AddTrajet
	

    void TrajetCompose::ToString() const
	{
		cout<<"Trajet composé part de "<<villeDepart<<" et va à "<<villeArrivee<<" suivant ce chemin: "<<endl;
		
		listeDesTrajets.ToString();
		
	}  // --- Fin de ToString

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose ):Trajet(unTrajetCompose)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
this->listeDesTrajets=ListeTrajets(unTrajetCompose.listeDesTrajets);
} //----- Fin de TrajetCompose::TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose (const char* villeDep, const char* villeArr,Transport transportUtilise):Trajet(villeDep,villeArr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur paramétré de <TrajetCompose>" << endl;
#endif
TrajetSimple trajetAAjouter(villeDep,villeArr,transportUtilise);
AddTrajet(trajetAAjouter);

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose (const TrajetSimple &unTrajetSimple):Trajet(unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur paramétré avec un TrajetSimple de <TrajetCompose>" << endl;
#endif

AddTrajet(unTrajetSimple);

} //----- Fin de TrajetCompose




TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

