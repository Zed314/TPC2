/*************************************************************************
                           TrajetCompose.h  -  description
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
    
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "ListeTrajets.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//	Un trajet composé de plusieurs trajets simples via une liste chaînée d'objets en mémoire
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool AddTrajet(const Trajet  * trajetToAdd);
    // Mode d'emploi :Ajoute un trajet à la fin du TrajetComposé appellant si la fin de celui-ci
    //correspond au début du trajet donné en paramètre
    //Change la ville de d'arrivée du TrajetComposé appelant et de départ si besoin 
    // Contrat : le pointeur pointe vers une zone mémoire valide
    
    bool AddTrajet(const Trajet  &trajetToAdd);
    // Mode d'emploi :Ajoute un trajet simple à la fin du TrajetComposé appellant si la fin de celui-ci
    //correspond au début du trajet simple donné en paramètre
  
	
	 Trajet * Clone() const;
	//Mode d'emploi : Renvoie un pointeur de Trajet vers une copie de l'élément appelant
	//Contrat : L'utilisateur doit supprimer la zone pointée par le pointeur retourné
	//quand il n'en a plus l'utilité
  
	bool EstVide() const;
	//Mode d'emploi : Renvoie vrai si la liste du trajet composé est vide
	
    void ToString() const;
	//Mode d'emploi : Permet d'afficher le trajet composé
		 

//-------------------------------------------- Constructeurs - destructeur

	 TrajetCompose ();
    // Mode d'emploi : constructeur par défaut d'un trajet

    TrajetCompose (const char* villeDep, const char* villeArr, const Transport transp );
    // Mode d'emploi : constructeur d'un trajet (paramétré)
    //Construit un trajet composé à partir des données passées en paramétre, données décrivant les informations
		//que l'on peut retrouver dans un trajet simple
    
    TrajetCompose (const TrajetSimple & unTrajetSimple);
    // Mode d'emploi: Construit un TrajetComposé sur le modèle d'un TrajetSimple

    
    

    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) : créé un nouvel objet TrajetComposé
    //en effectuant une copie en profondeur du trajet passé en paramétre
    // Contrat :
    //


    virtual ~TrajetCompose ( );
    // Mode d'emploi : Detruit le TrajetComposé
    //
  

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:

//------------------------------------------------------- Attributs privés
ListeTrajets * listeDesTrajets;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

