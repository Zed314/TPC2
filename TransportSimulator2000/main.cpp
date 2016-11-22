
/*************************************************************************
                           TrajetSimulator2000  
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
	
							***	INSA LYON - Projet de 3IF ***
     
	 Application permettant de gérer, ajouter et rechercher des trajets entre plusieurs villes.
*************************************************************************/
#define MAP
#define MAX_LENGTH 100

#include <iostream>
#include <cstring>

#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeTrajets.h"


using namespace std;

static TrajetSimple * createTrajetSimple();

//Fonction d'interface de l'ajout de trajet
static void loadAddHCI(Catalogue & cat)
{
	int response = 0;
	while(response != -1)
	{
		cout << endl << "Choisir un mode d'ajout (1 = simple, 2 = compose, -1 = quitter)." << endl << endl;
		
		cin >> response;
		switch(response)
		{
			case 1 : 
			{
				TrajetSimple* trajetSimple = createTrajetSimple();
				if(trajetSimple != nullptr)
				{
					cat.AddTrajet(*trajetSimple);
					cout << "Trajet simple ajoute : ";
					trajetSimple->ToString();					//Ajout simple
					cout << endl;
					delete trajetSimple;
					response = -1;
				}
				else {
					cout << "Erreur : mode de transport incorrect." << endl;
					response = -1;
				}
				break;
			}
			case 2 : 
			{
				TrajetCompose tc;
				int response2 = 0;
				do{
					cout << "Creation d'un trajet compose. Veuillez entrer un trajet." << endl;
					TrajetSimple* trajetSimple = createTrajetSimple();
					if(trajetSimple != nullptr)
					{
						
						if(tc.AddTrajet(*trajetSimple))
						{
							cout << "Trajet simple ajoute : ";
							trajetSimple->ToString();					//Ajout simple
						}
						cout << endl;
						delete trajetSimple;
						
					} 
					else {
						cout << "Erreur : mode de transport incorrect. " << endl;
					}
										
					cout << "Entrer -1 pour arreter d'entrer de nouveaux trajets simples ou toute autre valeur pour continuer.";
					cin >> response2;
				} while (response2 != -1);
				
				if (!tc.EstVide())
				{
					cat.AddTrajet(tc);				//Ajout seulement si le trajet composé n'est pas vide !
				}
			}
			
			case -1 : break;
			default : 
			{
				cout << "Commande non reconnue.  Merci d'entrer un transport valide."<<endl;
				response = 0;
	
			}
			
			break;
		}
			
		cout << endl;
		}
	
	}


//Crée un trajet simple et le renvoie
//Renvoie un pointeur null si l'utilisateur entre un moyen de transport erroné
static TrajetSimple * createTrajetSimple()
{
		char* depart = new char[MAX_LENGTH + 1];
		char* arrivee = new char[MAX_LENGTH + 1];
		int indxEnum;
		
		cout << "Entrer la ville de depart : " << endl;
		cin >> depart;
		cout << endl << "Entrer la ville d'arrivee" << endl;
		cin >> arrivee;
		cout << "Choisir un mode de transport : " <<endl;
		
		cout << "1. Avion" << endl;
		cout << "2. Automobile"<< endl;
		cout << "3. Tank" << endl;
		cout << "4. Canard geant" << endl;
		cout << "5. Tramway" << endl;
		cout << "6. Bateau" << endl;
		cout << "7. Missile nord-coreen" << endl;
		
		cin >> indxEnum;
		if(indxEnum >= 1 and indxEnum <=7)
		{
			Transport t = static_cast<Transport>(indxEnum-1);			//On suppose l'ordre des enumérations inchangé 
			TrajetSimple* ts = new TrajetSimple (depart, arrivee, t);
			delete[] depart;
			delete[] arrivee;
			return ts;
		}
		else {
			delete[] depart;
			delete[] arrivee;
			return nullptr;
		}
}

//Fonction locale de chargement de l'interface
static void loadHCI()
{
	cout <<"                  *** TRAJET SIMULATOR 2000 ***"<<endl;                                                                       
    int response = 0;
	Catalogue c;
	while(response != -1)
	{
		
		cout << endl << "Selectionner un mode. Entrer -1 pour quitter." << endl << endl;
		cout<< "1. Ajouter un trajet au catalogue." << endl;
		cout << "2. Afficher le catalogue."<< endl;
		cout << "3. Rechercher un parcours" << endl;
		
		cin >> response;
		switch(response)
		{
			case 1 : 
			{
				loadAddHCI(c); break;
			}
			case 2 : 
			{
				
				cout << endl << "*** Contenu du catalogue : ***"<<endl; 
				c.ToString();
				cout << "*** Fin du catalogue ***"<< endl;
				break;
			}
			case 3 : 
			{
				cout << "TODO : fonction de recherche"<<endl; break;
			}
			default : 
			{
				if(response != -1)
				{
					cout << "Commande non reconnue."<<endl;
					response = 0;
				}
				break;
			}		
		}
		cout << endl;

	}
}





//Methode de test de la liste
static void testListe()

{
	ListeTrajets lt;
	lt.ToString();
	TrajetSimple t1("Lyon", "Paris", Transport::Automobile);
	TrajetSimple t2("Paris","Buccarache",Transport::Avion);
	TrajetCompose t3(t1);
	t3.AddTrajet(t2);	
	lt.AddT(t1);
	lt.AddT(t2);
	lt.AddT(t3);
	lt.ToString();
	
}


void testConstructeurDeCopie()
{
	TrajetSimple a("Lyon", "Paris", Transport::Automobile);
	a.ToString();
cout<<endl;
	{
		TrajetSimple b(a);
		b.ToString();
		cout<<endl;
	}
	a.ToString();
	cout<<endl;
	TrajetCompose c(a);
	{
		TrajetCompose d(c);
	}
	c.ToString();
}

void testConstructeurDeCopieListe()
{
	ListeTrajets a;
	TrajetSimple c("Paris", "Lyon", Transport::DosDeMathieuMaranzana);
	TrajetSimple d("Lyon", "Villeurbanne",Transport::Tank);

	TrajetCompose e(c);
	e.ToString();
	{
		TrajetCompose t(e);
		t.ToString();
	}
	a.ToString();
	a.AddT(c);
	a.AddT(d);
	e.AddTrajet(d);
	a.ToString();
	{
		ListeTrajets z(a);
		z.ToString();
		z.AddT(e);
		z.ToString();
	}
	a.ToString();
	e.ToString();

}
void testTrajetCompose()
{
	TrajetSimple a("Lyon", "Paris", Transport::Automobile);

	TrajetCompose b(a);
	b.ToString();
	
	TrajetSimple c("Paris", "Lyon", Transport::DosDeMathieuMaranzana);
	TrajetSimple d("Paris", "Lyon", Transport::DosDeMathieuMaranzana);
	b.AddTrajet(c);

	b.AddTrajet(d);
	b.ToString();
	TrajetCompose e;
	e.ToString();
	e.AddTrajet(&c);
	e.ToString();
	{
		TrajetSimple f("Lyon", "Berlin", Transport::Avion);
		e.AddTrajet(&f);
		
	}
	e.ToString();
	
}
void testCatalogue()
{
	Catalogue catalogue;
	TrajetSimple a("Lyon", "Paris", Transport::Automobile);
	TrajetSimple b("Paris", "Dourdan", Transport::Avion);
	TrajetSimple c("Dourdan", "Bréthencourt", Transport::Tank);
	TrajetCompose tc(a);

	tc.AddTrajet(b);
	catalogue.AddTrajet(a);
	catalogue.AddTrajet(b);
	catalogue.AddTrajet(c);
	catalogue.AddTrajet(tc);
	catalogue.ToString();
	if(catalogue.CheckTrajet("Paris","Dourdan"))
	{
		cout<<endl;	
		cout<<"Il existe bien un trajet partant de Paris et allant à Dourdan!"<<endl;
	}
	else
	{
		cout<<"Il n'existe pas de trajets partant de Paris et allant à Dourdan!"<<endl;
	}
	if(catalogue.CheckTrajet("Dourdan","Paris"))
	{
		cout<<endl;	
		cout<<"Il existe bien un trajet partant de Dourdan et allant à Paris!"<<endl;
	}
	else
	{
		cout<<"Il n'existe pas de trajets partant de Dourdan et allant à Paris!"<<endl;
	}
	if(catalogue.CheckTrajet("Lyon","Dourdan"))
	{
		cout<<endl;	
		cout<<"Il existe bien un trajet partant de Lyon et allant à Dourdan!"<<endl;
	}
	else
	{
		cout<<"Il n'existe pas de trajets partant de Lyon et allant à Dourdan!"<<endl;
	}
	if(catalogue.CheckTrajet("Lyon","Bréthencourt"))
	{
		cout<<endl;	
		cout<<"Il existe bien un trajet partant de Lyon et allant à Bréthencourt!"<<endl;
	}
	else
	{
		cout<<"Il n'existe pas de trajets partant de Lyon et allant à Bréthencourt!"<<endl;
	}
	
	
}
/*

	Méthode principale appelante de la classe
	argc désigne le nombre d'éventuels arguments à fournir au programme
    argv se comporte comme un tableau de chaînes de caractères contenant ces arguments
*/

int main(int argc, char** argv)
{


	//test1();
	//testListe();
	//testListe();
	////testConstructeurDeCopie();
	//testConstructeurDeCopieListe();
	//testTrajetCompose();
	//testCatalogue();
	loadHCI();
	return 0;
}  //----- Fin du main
