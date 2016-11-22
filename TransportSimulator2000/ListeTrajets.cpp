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
#include <cstring>

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


int ListeTrajets::nbElements() const
{
	ElementListeTrajet* elt = this->ptrDebut;
	int nb = 0;
	
	while(elt != nullptr)
	{
		elt = elt->ElementTrajetSuivant;
		nb++;
		
	}
	return nb;
	
}

int ListeTrajets::indexOf(char* ville, char** tab) const
{
	int i;
	for( i=0;strcmp(tab[i], ville)!=0;i++)
	{	
		//for vide
	}
	return i;
}

/**
 * PARAM ensembleDesTrajets : ensemble des trajets existants
 * PARAM villeEnCours : la ville en cours de traitement
 * PARAM  villeArrivee : la ville d'arrivée finale
 * PARAM ensembleTrajets : l'ensemble total de tous les trajets de la liste
 * PARAM parcours : matrice des parcours trouvés (pointeurs sur trajet)
 * PARAM nbParcoursTrouves : le numéro de la ligne en cours sur parcours
 * PARAM nbTrajetsParcours : le nombre de trajets déjà parcourus au cours du parcours
 * PARAM nbTrajets : le nombre maximal de trajets 
 * PARAM tabCorrespondance : le tableau permettant de convertir une ville en nombre
 * PARAM tabVillesPrises : un tableau d'entiers
 * 
 * */
int findTrajetComplexeRec(int villeEnCours, int villeArrivee, Trajet** ensembleDesTrajets , Trajet*** parcours, int nbParcoursTrouves , int nbTrajetsParcours,int nbTrajetsTotal, char** tabCorrespondance, int* tabVillesPrises) const
{
	if(villeEnCours == villeArrivee)
	{
		parcours[nbParcoursTrouves][nbVillesParcourues] = villeEnCours;
		return nbParcoursTrouves+1;
	}	
}



int ListeTrajets::afficheTrajetsRechercheComplexe(const char* depart, const char* arrivee) const 
{
	char* tab[this->nbElements()*2];
	for(int j=0;j<this->nbElements()*2;visited[j++] = false)
	{}			//for vide => initialisation du  tableau des visités
	int identifier = 0;
	ElementListeTrajet* cur = this->ptrDebut;
	while(cur != nullptr)
	{
		char* villeDep = cur->TrajetEnCours->getCpyDep();
		char* villeArr = cur->TrajetEnCours->getCpyArr();
		if(shouldAddCity(villeDep, identifier, tab))
		{
			tab[identifier] =  villeDep;
			identifier++;
		}
		else 
		{
			delete[] villeDep;
		}
		if(shouldAddCity(villeArr, identifier, tab))
		{
			tab[identifier] =  villeArr;
			identifier++;
		}
		else 
		{
			delete[] villeArr;
		}
		cur = cur->ElementTrajetSuivant;
	}
	bool matriceAdj[identifier][identifier];
	for(int i=0;i<identifier;i++)
	{
		for(int j=0;j<identifier;j++)
		{
			matriceAdj[i][j] = false;
		}
	}
	cur = this->ptrDebut;
	while(cur != nullptr)
	{
		char* villeDep = cur->TrajetEnCours->getCpyDep();
		char* villeArr = cur->TrajetEnCours->getCpyArr();
		
		matriceAdj[indexOf(villeDep,tab)][indexOf(villeArr,tab)]=true;
		delete[] villeArr;
		delete[] villeDep;
		cur = cur->ElementTrajetSuivant;
	}
	bool visited[identifier];
	for(int i=0;i<identifier;visited[identifier]=false){} //for vide
	
	
	/*
	for(int i =0 ;i <identifier;i++)
	{
		for(int j=0;j<identifier;j++)
		{
			cout<<matriceAdj[i][j]<<",";
		}
		cout<<endl;
	}
	//*/
	
	
	
	//TODO : désallouer les chaines de tab
	//TODO: return value
	return 0;
}


bool ListeTrajets::shouldAddCity(char* ville, int & identifier, char** tab) const
{
		bool trouve = false;
		for(int j=0;(j<identifier && !trouve);j++)
		{
			if(strcmp(tab[j], ville) == 0)
			{
				trouve = true;
			}
			
		}
		return !trouve;
}

bool ListeTrajets::afficheTrajetsRechercheSimple(const char* depart, const char* arrivee) const
{
	unsigned int comptNbTrajets = 0;
	ElementListeTrajet* cur = this->ptrDebut;
	while(nullptr!=cur)
	{
		if(cur->TrajetEnCours->CheckIfGoesFromTo(depart, arrivee))
		{
			cur->TrajetEnCours->ToString() ;
			cout << endl;
			comptNbTrajets++;
		}
		cur = cur->ElementTrajetSuivant;
	}
	
	return comptNbTrajets > 0;
}			// --- Fin de afficheTrajetsRechercheSimple

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
int ListeTrajets::CheckTrajet(const char* const ville1, const char* ville2) const
{
	int nbTrajets = 0;

	ElementListeTrajet * elementEnCours=this->ptrDebut;
	
	while(elementEnCours!=nullptr)
	{
		if(elementEnCours->TrajetEnCours->CheckIfGoesFromTo(ville1,ville2))
		{
			elementEnCours->TrajetEnCours->ToString();
			 nbTrajets++;
		}
		
		elementEnCours=elementEnCours->ElementTrajetSuivant;
		
	}
		
	
	return nbTrajets;

}

void ListeTrajets::AddT(const Trajet * trajetAAjouter)
{

	this->AddTInterne(trajetAAjouter->Clone());
}

void ListeTrajets::AddT(const Trajet & trajetAAjouter)
{

	this->AddTInterne(trajetAAjouter.Clone());
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
// Algorithme :Copie en profondeur, élément par élément, trajets par trajets, de la liste passée en paramètre
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
		
		while(elementEnCours!=nullptr)
		{

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
