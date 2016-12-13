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
#include <string>
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
string ListeTrajets::PrintRaw() const
{
	return "";
}

unsigned int ListeTrajets::NbTrajets() const
{
	ElementListeTrajet* elt = this->ptrDebut;
	unsigned int nbVilles=0;
	
	while(elt != nullptr)
	{
		nbVilles++;
		elt = elt->ElementTrajetSuivant;
		
		
	}
	return nbVilles;
}
bool ListeTrajets::villeEstPresente(char * ville)
{
	ElementListeTrajet* elt = this->ptrDebut;
	bool laVilleEstPresente=false;
	
	while(elt != nullptr&&!laVilleEstPresente)
	{
		if(elt->TrajetEnCours->CheckIfGoesFrom(ville)||elt->TrajetEnCours->CheckIfGoesTo(ville))
		{
			laVilleEstPresente=true;
		}
		elt = elt->ElementTrajetSuivant;
		
		
	}
	return laVilleEstPresente;
}

char * ListeTrajets::getCopyOfLastArr()
{
	if(this->EstVide())
	{
		return nullptr;
	}
	else
	{
		return this->ptrFin->TrajetEnCours->getCpyArr();
	}
	
}
Trajet * ListeTrajets::getCopyOfLast()
{
	if(this->EstVide())
	{
		return nullptr;
	}
	else
	{
	
		return this->ptrFin->TrajetEnCours->Clone();
	}
	
}
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


int ListeTrajets::findTrajetComplexeRec( const char * villeEnCours, const char * villeArrivee,ListeTrajets &Parcours,Trajet ** ensembleDesTrajets,int nbTrajets,int nbParcoursComplets) const
{
	char * lecture;
	lecture=Parcours.getCopyOfLastArr();
	if(lecture!=nullptr && strcmp(lecture,villeArrivee)==0)
	{
		delete[] lecture;
		cout<<endl<<"Trajet numéro "<<nbParcoursComplets<<endl;
		Parcours.ToString();
		cout<<endl;
		return nbParcoursComplets+1;
	}
	else
	{
		delete[] lecture;
		Trajet * dernierElementDuParcours=Parcours.getCopyOfLast();
		//int nbTrajets=this->nbElements();
		for(int i=0;i<nbTrajets;i++)
		{
			if(dernierElementDuParcours!=nullptr)
			{	
				if(dernierElementDuParcours->PeutServirDeBaseA(ensembleDesTrajets[i]))
				{
					lecture=ensembleDesTrajets[i]->getCpyArr();
					if(!Parcours.villeEstPresente(lecture))
					{
						Parcours.AddT(ensembleDesTrajets[i]);
						char * nouvelleVilleEnCours=Parcours.getCopyOfLastArr();
						nbParcoursComplets=findTrajetComplexeRec(nouvelleVilleEnCours,villeArrivee,Parcours,ensembleDesTrajets,nbTrajets,nbParcoursComplets);
						delete[] nouvelleVilleEnCours;
						Parcours.removeLast();
					}
					delete[]lecture;
				}
			
			}
			else
			{
				if(ensembleDesTrajets[i]->CheckIfGoesFrom(villeEnCours))
				{
					Parcours.AddT(ensembleDesTrajets[i]);
					char * nouvelleVilleEnCours=Parcours.getCopyOfLastArr();
					nbParcoursComplets=findTrajetComplexeRec(nouvelleVilleEnCours,villeArrivee,Parcours,ensembleDesTrajets,nbTrajets,nbParcoursComplets);
					delete[] nouvelleVilleEnCours;
					Parcours.removeLast();
					
				}
				else
				{
					
				}
			}
	
		}
	delete dernierElementDuParcours;	
		
	}
	
	return nbParcoursComplets;
	
}

int ListeTrajets::afficheTrajetsRechercheComplexe(const char* depart, const char* arrivee) const 
//Algorithme : Stocke le contenu de la liste appelante dans un tableau et l'envoie à une fonction
//récursive avec d'autres paramètres dans le but d'effectuer un backtracking et d'afficher sur la 
//sortie standard les combinaisons de trajet partant de depart et allant à arrivee
{
	int nbTrajets=this->nbElements();
	ListeTrajets parcours;
	
	Trajet * tableauDesTrajets[nbTrajets];
	int compteurTrajets=0;
	ElementListeTrajet* cur = this->ptrDebut;
	//On met les Trajets contenus dans la liste dans un tableau pour faciliter la recherche
	while(cur != nullptr)
	{
		tableauDesTrajets[compteurTrajets]=cur->TrajetEnCours->Clone();
		compteurTrajets++;
		cur = cur->ElementTrajetSuivant;
	}
	int nbTrajetsAffiches=findTrajetComplexeRec(depart,arrivee,parcours,tableauDesTrajets,nbTrajets,0);
	
	
	
	for(int i=0;i<nbTrajets;i++)
	{
		delete tableauDesTrajets[i];
	}
	
	
	return nbTrajetsAffiches;


}

int ListeTrajets::afficheTrajetsRechercheSimple(const char* depart, const char* arrivee) const
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
	
	return comptNbTrajets;
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
	
}//Fin de ToString


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
// Algorithme : Désalloue les éléments de la liste ainsi que les Trajets associés en partant du début
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
bool ListeTrajets::removeLast()
{
	if(this->EstVide())
	{
		return false;
	}
	ElementListeTrajet* elt = this->ptrDebut;
	if(this->ptrFin==this->ptrDebut)
	{
		delete this->ptrDebut->TrajetEnCours;
		delete this->ptrDebut;
		this->ptrDebut=nullptr;
		this->ptrFin=nullptr;
		return true;
		
	}
	
	while(elt->ElementTrajetSuivant!=this->ptrFin)
	{
		elt = elt->ElementTrajetSuivant;
		
	}
	delete this->ptrFin->TrajetEnCours;
	delete this->ptrFin;
	elt->ElementTrajetSuivant=nullptr;
	this->ptrFin=elt;
	
	
	return true;
	
}
