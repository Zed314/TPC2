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
bool ListeTrajets::villeEstPresente(char * ville)
{
	ElementListeTrajet* elt = this->ptrDebut;
	bool laVilleEstPresente=false;
	
	while(elt != nullptr&&!laVilleEstPresente)
	{
		if(elt->TrajetEnCours->CheckIfGoesFrom(ville)||elt->TrajetEnCours->CheckIfGoesFrom(ville))
		{
			laVilleEstPresente=true;
		}
		elt = elt->ElementTrajetSuivant;
		
		
	}
	return laVilleEstPresente;
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
/*
int ListeTrajets::indexOf(const char* ville, char** tab) const
{
	int i;
	for( i=0;strcmp(tab[i], ville)!=0;i++)
	{	
		//for vide
	}
	return i;
}*/

int ListeTrajets::findTrajetComplexeRec( const char * villeEnCours, const char * villeArrivee,ListeTrajets &Parcours,Trajet ** ensembleDesTrajets,int nbParcoursComplets) const
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
		int nbTrajets=this->nbElements();
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
						nbParcoursComplets=findTrajetComplexeRec(nouvelleVilleEnCours,villeArrivee,Parcours,ensembleDesTrajets,nbParcoursComplets);
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
					nbParcoursComplets=findTrajetComplexeRec(nouvelleVilleEnCours,villeArrivee,Parcours,ensembleDesTrajets,nbParcoursComplets);
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
{
	int nbTrajets=this->nbElements();
	ListeTrajets parcours;
	
	Trajet * tableauDesTrajets[nbTrajets];
	int compteurTrajets=0;
	ElementListeTrajet* cur = this->ptrDebut;
	while(cur != nullptr)
	{
		tableauDesTrajets[compteurTrajets]=cur->TrajetEnCours->Clone();
		compteurTrajets++;
		cur = cur->ElementTrajetSuivant;
	}
	int nbTrajetsAffiches=findTrajetComplexeRec(depart,arrivee,parcours,tableauDesTrajets,0);
	
	
	
	for(int i=0;i<nbTrajets;i++)
	{
		delete tableauDesTrajets[i];
	}
	
	//delete[] tableauDeListes;
	return nbTrajetsAffiches;


}


/**
 * PARAM ensembleDesTrajets : ensemble des trajets existants
 * PARAM villeEnCours : la ville en cours de traitement
 * PARAM  villeArrivee : la ville d'arrivée finale
 * PARAM parcours : matrice des parcours trouvés (pointeurs sur trajet)
 * PARAM nbParcoursTrouves : le numéro de la ligne en cours sur parcours
 * PARAM nbTrajetsParcours : le nombre de trajets déjà parcourus au cours du parcours
 * PARAM nbTrajets : le nombre maximal de trajets 
 * PARAM tabCorrespondance : le tableau permettant de convertir une ville en nombre
 * PARAM tabVillesPrises : tableau de booléen permettant de savoir quelles villes sont prises
 * 
 * */
 
/* 
int ListeTrajets::findTrajetComplexeRec(  char  * villeEnCours, const char  *villeArrivee, Trajet** ensembleDesTrajets , Trajet* parcours[][], int nbParcoursTrouves , int nbTrajetsParcours,int nbTrajetsTotal,  char** tabCorrespondance, bool* tabVillesPrises) const
{
	
	if(strcmp(villeEnCours, villeArrivee))
	{
		if(nbParcoursTrouves<nbTrajetsTotal-1)
		{
			for(int i=0;i<nbTrajetsParcours-1;i++)
			{
				parcours[nbParcoursTrouves+1][i]=parcours[nbParcoursTrouves][i];
			}
		}
	
		//parcours[nbParcoursTrouves][nbVillesParcourues] = villeEnCours;
		return nbParcoursTrouves+1;
	}	
	
	else
	{
		char * villeAAjouter;
		int indiceVilleAAjouter;
		for(int i=0;i<nbTrajetsTotal;i++)
		{
			if(nbTrajetsParcours==0)
			{
				if(ensembleDesTrajets[i]->CheckIfGoesFrom(villeEnCours))
				{
					parcours[nbParcoursTrouves][nbTrajetsParcours]=ensembleDesTrajets[i];
					villeAAjouter=ensembleDesTrajets[i]->getCpyArr();
				
					tabVillesPrises[indexOf(villeAAjouter,tabCorrespondance)]=true;
				
					nbParcoursTrouves=findTrajetComplexeRec(villeAAjouter,villeArrivee,ensembleDesTrajets,parcours,nbParcoursTrouves,nbTrajetsParcours+1,nbTrajetsTotal,tabCorrespondance,tabVillesPrises);
					delete[] villeAAjouter;
					tabVillesPrises[indiceVilleAAjouter]=false;
					
				}
				else
				{
					
				}
			}
			else if(parcours[nbParcoursTrouves][nbTrajetsParcours-1]->PeutServirDeBaseA(ensembleDesTrajets[i]))
			{
					villeAAjouter = ensembleDesTrajets[i]->getCpyArr();
					indiceVilleAAjouter=indexOf(villeAAjouter,tabCorrespondance);
					
					if(!tabVillesPrises[indiceVilleAAjouter])
					{
						tabVillesPrises[indiceVilleAAjouter]=true;
						nbParcoursTrouves=findTrajetComplexeRec(villeAAjouter,villeArrivee,ensembleDesTrajets,parcours,nbParcoursTrouves,nbTrajetsParcours+1,nbTrajetsTotal,tabCorrespondance,tabVillesPrises);
						tabVillesPrises[indiceVilleAAjouter]=false;
						
					}
					else
					{
						
					}
				delete[] villeAAjouter;

			}
		}
	}
	return nbParcoursTrouves;
	
	
	
}



int ListeTrajets::afficheTrajetsRechercheComplexe(const char* depart, const char* arrivee) const 
{
	char* tab[this->nbElements()*2];

	int identifier = 0;
	Trajet * tableauDesTrajets[this->nbElements()];
	int compteurTrajets=0;
	ElementListeTrajet* cur = this->ptrDebut;
	while(cur != nullptr)
	{
		tableauDesTrajets[compteurTrajets]=cur->TrajetEnCours;
		compteurTrajets++;
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
	bool visited[identifier];
	//todo mettre depart a true
	for(int i=0;i<identifier;visited[i++]=false){
		//for vide => initialisation du  tableau des visités
	} 
	visited[indexOf(depart,tab)]=true;
	Trajet* parcours[compteurTrajets][compteurTrajets];
	
	
	
	
	
	for(int i =0 ;i <identifier;i++)
	{
		for(int j=0;j<identifier;j++)
		{
			cout<<matriceAdj[i][j]<<",";
		}
		cout<<endl;
	}
	
	
	//findTrajetComplexeRec(depart, arrivee, tableauDesTrajets ,  parcours, 0 ,0,compteurTrajets, tab, visited);
	
	
	
	
	//TODO : désallouer les chaines de tab
	//TODO: return value
	return findTrajetComplexeRec(depart, arrivee, tableauDesTrajets ,  parcours, 0 ,0,compteurTrajets, tab, visited);
}
//*/

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
