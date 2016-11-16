
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

 // Mode d'emploi : Affiche le trajet simple
    void ToString() const;



//-------------------------------------------- Constructeurs - destructeur


	//Constructeur de copie d'un trajet simple
    TrajetSimple ( const TrajetSimple & unTrajet );

	//Constructeur par défaut d'un trajet simple
   // TrajetSimple ( );
	
	//Constructeur paramétré
    TrajetSimple (const char* villeDep, const char* villeArr, const Transport transp );
    // Mode d'emploi : constructeur d'un trajet (paramétré)


	//Destructeur d'un trajet simple
    virtual ~TrajetSimple ( );


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
Transport transportUtilise;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <TrajetSimple>

#endif // TRAJETSIMPLE_H

