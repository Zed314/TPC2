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
#include "TrajetSimple.h"
class TrajetCompose;

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


	bool afficheTrajetsRechercheSimple(const char* depart, const char* arrivee) const;
	
	int afficheTrajetsRechercheComplexe(const char* depart, const char* arrivee) const ;
	
	int nbElements() const;

	int CheckTrajet(const char* const ville1, const char* ville2) const;
    // Méthode vérifiant si un trajet reliant une ville à une autre existe dans la liste
    // Affiche les Trajets en question si il en existe au moins un
    // Renvoie true si un Trajet a été trouvé, false sinon
    
    
   void AddT(const Trajet & trajetAAjouter);
    // Mode d'emploi :Ajoute un trajet a la liste des trajets
   // L'ajout est effectué à la fin de la liste 
   // Le trajet est copié.
   
   void AddT(const Trajet * trajetAAjouter);
   // Mode d'emploi :Ajoute un trajet a la liste des trajets
   // L'ajout est effectué à la fin de la liste 
   // Le trajet pointé par le paramétre est copié.
	

    bool EstVide() const;
    // Renvoie true si la file est vide
    //
    // Contrat :
    //
    void ToString() const;
     // Affiche les éléments de la liste de trajets
    

    
	

//-------------------------------------------- Constructeurs - destructeur
    ListeTrajets ( const ListeTrajets & uneListe );
    // Mode d'emploi (constructeur de copie) :
    //Effectue une copie en profondeur de la liste
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
    void AddTInterne(Trajet * trajetAAjouter);
    // Mode d'emploi :Ajoute un pointeur sur trajet à la liste des trajets
    // L'ajout est fait en queue de liste chaînée
	
    // Contrat : Le pointeur passé en paramètre n'est pas NULL
private:
	
//------------------------------------------------------- Méthodes privées
	bool shouldAddCity(char* ville, int & identifier, char** tab) const;
	int indexOf(char* ville, char** tab) const;


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

