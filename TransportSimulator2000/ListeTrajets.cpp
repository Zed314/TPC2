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
#include "TrajetCompose.h"

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
bool ListeTrajets::CheckTrajet(const char* const ville1, const char* ville2)
{
	bool trajetTrouve = false;
	if(this->EstVide())
	{
		return false;
	}
	else
	{
		ElementListeTrajet * elementEnCours=this->ptrDebut;
	
		while(elementEnCours!=nullptr)
		{
			if(elementEnCours->TrajetEnCours->CheckIfGoesFromTo(ville1,ville2))
			{
				elementEnCours->TrajetEnCours->ToString();
				trajetTrouve = true;
			}
		
			elementEnCours=elementEnCours->ElementTrajetSuivant;
		
		}
		
	}
	return trajetTrouve;

}

void ListeTrajets::AddT(const Trajet * trajetAAjouter)
{
	Trajet * trajetAAjouterALaListe=trajetAAjouter->Clone();
	this->AddTInterne(trajetAAjouterALaListe);
}

void ListeTrajets::AddT(const Trajet & trajetAAjouter)
{
	Trajet * trajetAAjouterListe=trajetAAjouter.Clone();
	this->AddTInterne(trajetAAjouterListe);
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
ListeTrajets::ListeTrajets ( const ListeTrajets & uneListe ):ptrDebut(nullptr),ptrFin(nullptr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeTrajets>" << endl;
#endif

	if(uneListe.EstVide())
	{
		//Il n'y a rien à faire 
	}
	else
	{
		ElementListeTrajet * elementEnCours=uneListe.ptrDebut;
		//Trajet * trajetAAjouter;
		while(elementEnCours!=nullptr)
		{
			
		//	trajetAAjouter=elementEnCours->TrajetEnCours->Clone();
		
			this->AddTInterne(elementEnCours->TrajetEnCours->Clone());
		
			elementEnCours=elementEnCours->ElementTrajetSuivant;

		}
		
	}
	
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
void ListeTrajets::AddTInterne(Trajet * trajetAAjouter)
{
	
	
	
	if(this->EstVide())
	{
		this->ptrDebut = new ElementListeTrajet;
		this->ptrDebut->TrajetEnCours=trajetAAjouter;
		this->ptrDebut->ElementTrajetSuivant=nullptr;
		this->ptrFin=this->ptrDebut;

	}
	else
	{		
			
		this->ptrFin->ElementTrajetSuivant=new ElementListeTrajet;
		this->ptrFin->ElementTrajetSuivant->TrajetEnCours=trajetAAjouter;
		this->ptrFin->ElementTrajetSuivant->ElementTrajetSuivant=nullptr;
		this->ptrFin=this->ptrFin->ElementTrajetSuivant;
	
	}

}
//------------------------------------------------------- Méthodes privées