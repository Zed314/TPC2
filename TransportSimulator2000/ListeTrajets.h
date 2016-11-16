/*************************************************************************
                           ListeTrajets.h  -  description
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
    
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTETRAJETS_H )
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Elt{
	Trajet * TrajetEnCours;
	Elt * ElementTrajetSuivant;

} ElementListeTrajet;
//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//	
//	Liste contenant des pointeurs vers des éléments de type Trajet
//------------------------------------------------------------------------

class ListeTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void AddT(Trajet * trajetAAjouter);
    // Mode d'emploi :Ajoute un pointeur sur trajet à la liste des trajets
    // L'ajout est fait en queue de liste chaînée
	
    // Contrat : Le pointeur passé en paramètre n'est pas NULL
    //
    void Affichage() const;
    // Affiche les éléments de la liste de trajets

    bool EstVide() const;
    // Renvoie true si la file est vide

    
	


//-------------------------------------------- Constructeurs - destructeur
    ListeTrajets ( const ListeTrajets & uneListe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
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
ElementListeTrajet * ptrDebut;
ElementListeTrajet * ptrFin;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <ListeTrajets>

#endif // LISTETRAJETS_H

