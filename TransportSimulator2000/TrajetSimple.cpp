
/*************************************************************************
                           TrajetSimple  -  classe représentant un TrajetSimple
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
     
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#define MAP
#include <iostream>
#include <cstring>
#include <sstream>
//------------------------------------------------------ Include personnel


#include "TrajetSimple.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


std::string itos(int i);

string TrajetSimple::PrintRaw()const
{
	string strToReturn="0\r\n";
	strToReturn+=villeDepart;
	strToReturn+="\r\n";
	strToReturn+=villeArrivee;
	strToReturn+="\r\n";
	strToReturn+=itos(static_cast<int>(this->transportUtilise));
	return strToReturn;
	
}

Trajet * TrajetSimple::Clone() const
 {
 	#ifdef MAP

    	cout << "Appel à la méthode Clone() de <TrajetSimple>" << endl;

	#endif

return new TrajetSimple(*this);
 }
 
 
void TrajetSimple::transportToString() const
{
	switch(this->transportUtilise)
	{
		case(Avion):
		cout<<"Avion";
		break;
		case(Automobile):
		cout<<"Automobile";
		break;
		case(Train):
		cout<<"Train";
		break;
		case(Canard_geant):
		cout<<"Canard geant";
		break;
		case(Tramway):
		cout<<"Tramway";
		break;
		case(Bateau):
		cout<<"Bateau";
		break;
		case(Missile):
		cout<<"Missile Nord Coreen";
		break;
		case(Inconnu):
		cout<<"Inconnu";
		break;
	}
}

void TrajetSimple::ToString() const
{

	cout<<"Transport simple de "<<villeDepart<<" a "<<villeArrivee<<" en ";
	this->transportToString();
	

}  // --- Fin de ToString


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ):Trajet(unTrajetSimple)
// Algorithme :
//
{
#ifdef MAP

    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;

#endif

this->transportUtilise=unTrajetSimple.transportUtilise;

} //----- Fin de TrajetSimple::TrajetSimple (constructeur de copie)


//Constructeur paramétré
 TrajetSimple::TrajetSimple(const char* villeDep, const char* villeArr, const Transport transp ): Trajet (villeDep,villeArr),transportUtilise(transp) 
 {
	
	 #ifdef MAP
		cout << "Appel au constructeur paramétré de <TrajetSimple>" << endl;
	#endif
 
	
	 
 }  //--- Fin du constructeur
 
 
TrajetSimple::TrajetSimple ( ):Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur sans paramètres de <TrajetSimple>" << endl;
#endif
this->transportUtilise=Inconnu;
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

//--------------- Fonctions globales	
std::string itos(int i){
    std::stringstream ss;
    ss<<i;
    return ss.str();
}