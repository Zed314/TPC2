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

//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum Transport { Avion, Automobile, Tank, Canard_geant, Tramway, Bateau, DosDeMathieuMaranzana };
//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    //Méthode vérifiant si le trajet mène de la ville 1 à la ville 2
    bool checkIfGoesTo(const char* ville1, const char* ville2);
    
     //Méthode abstraite d'affichage des trajets
    virtual void toString() = 0;
    
//-------------------------------------------- Constructeurs - destructeur
   
    Trajet();

    Trajet (const char* villeDep, const char* villeArr, const Transport transp );
    // Mode d'emploi : constructeur d'un trajet (paramétré)

    virtual ~Trajet ( );
 


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

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
