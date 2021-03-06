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

	void AddTrajet(const Trajet * unTrajet);
 	// Méthode ajoutant un trajet à la liste des trajets
 	
 	void AddTrajet(const Trajet &unTrajet);
 	// Méthode ajoutant un trajet simple à la liste des trajets
 
    
	void ToString() const;
	//Méthode affichant l'ensemble du catalogue
	
    int CheckTrajetSimple(const char* const ville1, const char* ville2) const;

    // Méthode vérifiant si un trajet reliant une ville à une autre existe dans le catalogue
    // Affiche le Trajet en question si il en existe au moins un
    // Affiche un message d'erreur sinon
    // Renvoie le nombre de trajets trouvés
    
    int CheckTrajetComplexe(const char* ville1, const char* ville2) const;
    // Méthode vérifiant si une combinaison de trajets reliant une ville à une autre existe dans le catalogue
    // Affiche les combinaisons en question si il en existe
    // Affiche un message d'erreur sinon
    // Renvoie le nombre de combinaisons de trajets trouvés
    
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

	ListeTrajets * listeTrajets;		//Liste des trajets

//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Catalogue>

#endif // CATALOGUE_H

