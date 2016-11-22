/*************************************************************************
                           Trajet.h  -  description
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
    
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H
#define MAP
//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//	Un trajet abstrait, reliant deux villes (départ et arrivée) entre elles.
//------------------------------------------------------------------------
enum Transport { Avion, Automobile, Tank, Canard_geant, Tramway, Bateau, DosDeMathieuMaranzana,Inconnu };

class Trajet
{
//----------------------------------------------------------------- PUBLIC


public:
//----------------------------------------------------- Méthodes publiques

	//Renvoie une copie profonde de la ville de départ
	char* getCpyDep() const;
	
	//Renvoie une copie profonde de la ville d'arrivée
	char* getCpyArr() const;
	
	
	//Méthode vérifiant si le trajet appellant peut être ajouté à la suite du Trajet en parametre
	 bool PeutServirDeBaseA(const Trajet * TrajetAAjouter);
	
	
	//Méthode vérifiant si le trajet appellant peut être ajouté à la suite du Trajet en parametre
	 bool PeutServirDeBaseA(const Trajet &TrajetAAgrandir);

    //Méthode vérifiant si le trajet mène de la ville 1 à la ville 2
    bool CheckIfGoesFromTo(const char* ville1, const char* ville2) const;
    
    //Méthode permettant de savoir si le trajet part de ville
    bool CheckIfGoesFrom(const char* ville) const;
    
    //Méthode permettant de savoir si le trajet arrive à ville
    bool CheckIfGoesTo(const char* ville)const;
    
    //Méthode abstraite d'affichage des trajets
    virtual void ToString() const = 0;
    
    //Méthode abstraite permettant la copie d'un trajets
    virtual Trajet * Clone() const = 0;
//-------------------------------------------- Constructeurs - destructeur
   
   Trajet();
	//Constructeur non paramétré
	//Génére un trajet partant de INCONNU vers INCONNU
	
	Trajet(const char* villeDep, const char* villeArr);
   // Mode d'emploi : constructeur d'un trajet (paramétré)
   
	Trajet(const Trajet & unTrajet);
	//Constructeur par copie
    

    virtual ~Trajet ( );
    //Destructeur
 


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	void MaJArrivee(const Trajet &TrajetSource);
	//Mode d'emploi
	//Change la valeur de la ville d'arrivée par celle de TrajetSource
	//Utilisée dans Trajet Composé
	
	void MaJDepart(const Trajet &TrajetSource);
	//Mode d'emploi
	//Change la valeur de ville de Départ par celle de TrajetSource
	//Utilisée dans Trajet Composé
	
	
private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

	char* villeDepart;		//Chaine représentant la ville de départ
	char* villeArrivee;		//Chaine représentant la ville d'arrivée
	
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Trajet>

#endif // TRAJET_H

