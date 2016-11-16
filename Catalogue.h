/*************************************************************************
                           Catalogue.h  -  description
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
    
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//	
//	"Catalogue" contenant une liste d'objets de type Trajet, sous forme de liste chaînée.
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Méthode ajoutant un trajet à la liste des trajets
    void addTrajet(const Trajet* unTrajet);
    
    // Méthode vérifiant si un trajet reliant une ville à une autre existe dans la liste
    bool checkTrajet(const char* const ville1, const char* ville2);
    
//-------------------------------------------- Constructeurs - destructeur

	//Constructeur par copie
	 Catalogue(const Catalogue & unCatalogue);
	 
	 
	 // Mode d'emploi : Constructeur sans paramètre
     Catalogue ( );				

    //Destructeur de la classe
    virtual ~Catalogue ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:

//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:

	ListeTrajets listeTrajets;		//Liste des trajets

//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Catalogue>

#endif // CATALOGUE_H

