
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
unsigned int TrajetCompose::nbTrajetsCoutenus() const
{
	if(listeDesTrajets!=nullptr)
	{
		return listeDesTrajets->nbTrajets();
	}
	return 0;
}


Trajet * TrajetCompose::Clone() const
 {
 	 #ifdef MAP
    	cout << "Appel de la méthode Clone() de <TrajetCompose>" << endl;
	#endif
 	
 return new TrajetCompose(*this);
 }// --- Fin de Clone
 
bool TrajetCompose::AddTrajet(const Trajet  * trajetToAdd)
//Algorithme : Ajoute le trajet à la fin et modifie si besoin la ville de départ et d'arrivée du trajet appelant
//en utilisant les méthodes MaJDepart et MaJArrivee
//On vérifie si on peut bien ajouter le trajet en utilisant la méthode PeutServirDeBaseA
  {

	
		if(this->listeDesTrajets->EstVide())
		{
			this->MaJDepart(*trajetToAdd);
		}
		if(this->PeutServirDeBaseA(*trajetToAdd)||this->listeDesTrajets->EstVide())
		{
		this->MaJArrivee(*trajetToAdd);
	  	listeDesTrajets->AddT(trajetToAdd);
		return true;
	  }
	  else
	
		{
			cout<<"Ajout impossible! La fin du trajet actuel ne coïncide pas avec le début du trajet que l'on souhaite ajouter!"<<endl;
			return false;
		}

  }   // --- Fin de AddTrajet
bool TrajetCompose::AddTrajet(const Trajet  & trajetToAdd)
  {

	//Pas conçu pour la suppression
		if(this->listeDesTrajets->EstVide())
		{
			this->MaJDepart(trajetToAdd);
		}
		if(this->PeutServirDeBaseA(trajetToAdd)||this->listeDesTrajets->EstVide())
		{
		this->MaJArrivee(trajetToAdd);
	  	listeDesTrajets->AddT(trajetToAdd);
		return true;
	  }
	  else
	
		{
			cout<<"Ajout impossible! La fin du trajet actuel ne coïncide pas avec le début du trajet que l'on souhaite ajouter!"<<endl;
			return false;
		}

  }   // --- Fin de AddTrajet
  
	bool TrajetCompose::EstVide() const
  {
	return listeDesTrajets->EstVide();
  }   // --- Fin de estVide

    void TrajetCompose::ToString() const
	{
		cout<<endl;
		cout<<"Trajet composé part de "<<villeDepart<<" et va à "<<villeArrivee<<" suivant ce chemin: "<<endl<<"\t";	
		listeDesTrajets->ToString();
		
	}  // --- Fin de ToString

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose ):Trajet(unTrajetCompose)
// Algorithme : Fait appel au constructeur de copie de ListeTrajets et à un contructeur parametre de Trajet
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
this->listeDesTrajets= new ListeTrajets(*(unTrajetCompose.listeDesTrajets));
} //----- Fin de TrajetCompose::TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose ():Trajet()
// Algorithme : Fait appel au constructeur par défaut de Trajet et à celui de ListeTrajets
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <TrajetCompose>" << endl;
#endif

listeDesTrajets=new ListeTrajets();

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose (const char* villeDep, const char* villeArr,Transport transportUtilise):Trajet(villeDep,villeArr)
// Algorithme :Fait appel à un constructeur de Trajet et au contructeur de ListeTrajets
{
#ifdef MAP
    cout << "Appel au constructeur paramétré de <TrajetCompose>" << endl;
#endif
TrajetSimple trajetAAjouter(villeDep,villeArr,transportUtilise);
listeDesTrajets=new ListeTrajets();
AddTrajet(trajetAAjouter);

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose (const TrajetSimple &unTrajetSimple):Trajet(unTrajetSimple)
// Algorithme : Fait appel à un constructeur de copie Trajet et au contructeur de ListeTrajets
{
#ifdef MAP
    cout << "Appel au constructeur paramétré avec un TrajetSimple de <TrajetCompose>" << endl;
#endif
listeDesTrajets=new ListeTrajets();
AddTrajet(unTrajetSimple);

} //----- Fin de TrajetCompose




TrajetCompose::~TrajetCompose ( )
// Algorithme : Détruit le trajet composé en faisant appel au destructeur de liste
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

