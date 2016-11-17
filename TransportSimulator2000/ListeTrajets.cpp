/*************************************************************************
                           ListeTrajets  -  classe représentant une liste de trajets (liste chaînée)
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
     
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void ListeTrajets::ToString() const
{
	if(this->EstVide())
	{
		cout<<"La liste de trajets est vide!"<<endl;
	}
	else
	{
		ElementListeTrajet * elementEnCours=this->ptrDebut;
	
		while(elementEnCours!=nullptr)
		{
			elementEnCours->TrajetEnCours->ToString();
		
			elementEnCours=elementEnCours->ElementTrajetSuivant;
			if (elementEnCours!=nullptr)
			{
				cout<<", ";
			}
		}
		cout<<endl;
	}
	
}

void ListeTrajets::AddT(Trajet * trajetAAjouter)//Pas judicieux de faire une fonction où on ajoute des pointeurs
//alors que cette fonction est publique et que elle ne fait pas de copie en profondeur...
//A revoir entièrement
{
	if(this->EstVide())
	{
		this->ptrDebut = new ElementListeTrajet;
		this->ptrDebut->TrajetEnCours=trajetAAjouter;
		this->ptrDebut->ElementTrajetSuivant=nullptr;
		this->ptrFin=ptrDebut;
	}
	else
	{
		this->ptrFin->ElementTrajetSuivant=new ElementListeTrajet;
		this->ptrFin->ElementTrajetSuivant->TrajetEnCours=trajetAAjouter;
		this->ptrFin->ElementTrajetSuivant->ElementTrajetSuivant=nullptr;
		this->ptrFin=this->ptrFin->ElementTrajetSuivant;
	}
}

bool ListeTrajets::EstVide() const
{
	if(this->ptrDebut==nullptr || this->ptrFin==nullptr)
	{
		return true;
	}
	return false;	
}

//-------------------------------------------- Constructeurs - destructeur
ListeTrajets::ListeTrajets ( const ListeTrajets & uneListe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeTrajets>" << endl;
#endif
//TODO
//Après avoir fait le constructeur de copie de trajet

//Pour que ça fonctionne, il faudrait peut être passer par deux fonctions annexes renvoyant un pointeur sur Trajet
//Pour pouvoir l'ajouter à la liste
/*if(uneListe.EstVide())
	{
		this->ptrDebut=nullptr;
		this->ptrFin=nullptr;
	}
	else
	{
		ElementListeTrajet * elementEnCours=uneListe.ptrDebut;
	
		while(elementEnCours!=nullptr)
		{
			Trajet *elementAAjouter= new Trajet(elementEnCours->TrajetEnCours);
			this->AddT(elementAAjouter);
		
			elementEnCours=elementEnCours->ElementTrajetSuivant;

		}
		
	}*/
	
} //----- Fin de ListeTrajets::ListeTrajets (constructeur de copie)


ListeTrajets::ListeTrajets ( ): ptrDebut(nullptr),ptrFin(nullptr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif

} //----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif
	ElementListeTrajet * elementEnCours=this->ptrDebut;
	ElementListeTrajet * elementTemporaire;
		while(elementEnCours!=nullptr)
		{
			elementTemporaire=elementEnCours->ElementTrajetSuivant;
			delete elementEnCours->TrajetEnCours;
			delete elementEnCours;
			elementEnCours=elementTemporaire;
		}

} //----- Fin de ~ListeTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées