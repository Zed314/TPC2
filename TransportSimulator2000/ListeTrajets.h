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

	unsigned int NbTrajets() const;
	//Retourne le nombres de trajets dans la liste

	bool villeEstPresente(char * ville);
	//Renvoie true si la ville passee en parametre est presente dans la liste
	
	Trajet * getCopyOfLast();
	//Renvoie une copie du dernier trajet de la liste
	//Si la liste est vide, renvoie nullptr
	//Contrat:Libérer la zone renvoyée par la méthode à la fin de son utilisation
	
	char * getCopyOfLastArr();
	//Méthode renvoyant une copie de la ville d'arrivée du dernier élément de la liste
	//Si la liste est vide, renvoit nullptr
	//Contrat:Libérer la zone renvoyée par la méthode à la fin de son utilisation

	int afficheTrajetsRechercheSimple(const char* depart, const char* arrivee) const;
	 // Méthode vérifiant si un trajet reliant une ville à une autre existe dans la liste
    // Affiche les Trajets en question si il en existe au moins un
    // Renvoie le nombre de trajets trouvés
    
	int afficheTrajetsRechercheComplexe(const char* depart, const char* arrivee) const ;
	 // Méthode vérifiant si une combinaison de trajets reliant une ville à une autre existe dans la liste
    // Affiche les Trajets en question si il en existe au moins un
    // Renvoie le nombre de trajets trouvés
    
	int nbElements() const;
  // Renvoie le nombre d'éléments de la liste

    
    
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
    // Renvoie false sinon

   
    void ToString() const;
     // Affiche les éléments de la liste de trajets
    

    
	

//-------------------------------------------- Constructeurs - destructeur
    ListeTrajets ( const ListeTrajets & uneListe );
    // Mode d'emploi (constructeur de copie) :
    // Effectue une copie en profondeur de la liste
    // Contrat :
    //

    ListeTrajets ( );
    // Mode d'emploi : Génére une liste vide
    //
    // Contrat :
    //

    virtual ~ListeTrajets ( );
    // Mode d'emploi : Supprimer la liste et ses éléments en profondeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
	
//------------------------------------------------------- Méthodes privées
	void AddTInterne(Trajet * trajetAAjouter);
   // Mode d'emploi :Ajoute un pointeur sur trajet à la liste des trajets
   // N'effectue pas de copie en profondeur de trajetAAjouter, cette tache étant
   // gérée par les méthodes publiques AddT() qu'il convient d'appeler si on désire
   // ajouter un trajet à la liste
   // L'ajout est fait en queue de liste chaînée
   // Contrat : Le pointeur passé en paramètre n'est pas nullptr et doit correspondre à une zone
   // mémoire qui exclusive à l'objet
    
	int findTrajetComplexeRec( const char * villeEnCours,const char * villeArrivee,
	ListeTrajets &Parcours,Trajet ** ensembleDesTrajets,int nbTrajets,int nbParcoursComplets) const;
	//Methode récursive utilisée dans  afficheTrajetsRechercheComplexe
	//Affiche sur la sortie standard les combinaisons de trajet allant de la villeEnCours à la villeArrivee
	//Parametres:
	//villeEnCours contient le nom de la ville de départ
	//villeArrivee contient le nom de la ville d'arrivee
	//Parcours est une référence vers une liste de trajets désignant le chemin qu'on a parcouru précédemment
	//ensembleDesTrajets est un tableau de pointeurs sur Trajets désignant le contenu de la liste appelante
	//nbTrajet est un entier désignant le nombre de pointeurs sur Trajets dans le tableau ensembleDesTrajets
	//nbParcoursComplets désigne le nombre de parcours allant de la ville de départ à la ville d'arrivée précédemment trouvés
	//Contrat : le tableau ensembleDesTrajets contient bien les Trajets de la liste sous la forme d'un tableau
	
	bool removeLast();
	//Retire le dernier element de la liste
	//Renvoie true si la suppression a pû être effectuée et false si la liste est vide

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

