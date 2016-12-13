
/*************************************************************************
                           TrajetSimple.h  -  description
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
    
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//  Un Trajet simple, d'une ville A à une ville B, caractérisé par un moyen de transport (énumération)
//------------------------------------------------------------------------


class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	unsigned int nbTrajetsCoutenus() const
	{
		return 0;
	}
	//Mode d'emploi : retourne 0
		
    void ToString() const;
     // Mode d'emploi : Affiche le trajet simple
     
     
    void transportToString()const;  
 	//Mode d'emploi :  Affiche l'énumération Transport correspondante au trajet simple

	 Trajet * Clone() const;
	//Mode d'emploi : Renvoie un pointeur vers une copie de l'élément appelant

//-------------------------------------------- Constructeurs - destructeur


	
    TrajetSimple ( const TrajetSimple & unTrajet );
//Constructeur de copie d'un trajet simple


    TrajetSimple ( );
    	//Mode d'emploi : Constructeur par défaut d'un trajet simple
    	//Génére un trajet simple allant de INCONNU à INCONNU en moyen de transport inconnu
	
	
    TrajetSimple (const char* villeDep, const char* villeArr, const Transport transp );
    // Mode d'emploi : Constructeur d'un trajet simple à partir des villes de départ et d’arrivée, et du mode de transport


	
    virtual ~TrajetSimple ( );
    //Mode d'emploi : Destructeur d'un trajet simple


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
Transport transportUtilise;			//Mode de transport utilisé

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <TrajetSimple>

#endif // TRAJETSIMPLE_H

