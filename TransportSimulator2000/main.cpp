
/*************************************************************************
                           TrajetSimulator2000  
                             -------------------
    début                : 15/11/2016
    copyright            : (C) 2016 par Lucas POISSE & Ziggy VERGNE
    e-mail               : lucas.poisse@insa-lyon.fr / ziggy.vergne@insa-lyon.fr
	
							***	INSA LYON - Projet de 3IF ***
     
	 Application permettant de gérer, ajouter et rechercher des trajets entre plusieurs villes.
*************************************************************************/
//#define MAP
#define MAX_LENGTH 100					//Nombre maximal de caractères significatifs dans une ville

#include <iostream>
#include <cstring>
//#include <string>  //Inclusion non nécessaire, seulement utile pour déboguer l'interface

#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeTrajets.h"
#include "TrajetDAO.h"

using namespace std;

static TrajetSimple * createTrajetSimple();


//Fonction de recherche d'un parcours complexe
static void loadFindHCIComplexe(Catalogue & cat)
{
	
	char* depart = new char[MAX_LENGTH +1];
	char* arrivee = new char[MAX_LENGTH +1];
	
	cout << endl << "Entrer le nom de la ville de départ. " << endl << endl;
	cin >> depart;
	
	cout << endl << "Entrer le nom de la ville d'arrivée." << endl;
	cin >> arrivee;
	int nbTrajets;
	if((nbTrajets = cat.CheckTrajetComplexe(depart, arrivee)) == 0)
	{
		cout << endl << "La recherche complexe de parcours de la ville " << depart << " à la ville " << arrivee << " n'a donné aucun résultat " <<endl << endl;
	}	
	else {
		cout << endl << "La recherche complexe a retourné " << nbTrajets << " résultat" << (nbTrajets>1?"s":"") << "."<< endl;
	}
	
	delete[] depart;
	delete[] arrivee;
		
}

//Fonction de recherche d'un parcours simple
static void loadFindHCISimple(Catalogue & cat)
{
	
	char* depart = new char[MAX_LENGTH +1];
	char* arrivee = new char[MAX_LENGTH +1];
	
	cout << endl << "Entrer le nom de la ville de départ. " << endl << endl;
	cin >> depart;
	
	cout << endl << "Entrer le nom de la ville d'arrivée." << endl;
	cin >> arrivee;
	int nbTrajets;
	if((nbTrajets = cat.CheckTrajetSimple(depart, arrivee)) == 0)
	{
		cout << endl << "La recherche simple de parcours de la ville " << depart << " à la ville " << arrivee << " n'a donné aucun résultat " <<endl << endl;
	}	
	else {
		cout << endl << "La recherche simple a retourné " << nbTrajets << " résultat" << (nbTrajets>1?"s":"") << "."<< endl;
	}
	
	delete[] depart;
	delete[] arrivee;
		
}

//Fonction d'interface de l'ajout de trajet
static void loadAddHCI(Catalogue & cat)
{
	int response = 0;
	while(response != -1)
	{
		cout << endl << "Choisir un mode d'ajout (1 = simple, 2 = compose, -1 = quitter)." << endl << endl;
		cin >> response;
		
		if(!cin){
			cout << endl << "Merci d'entrer un nombre valide."<< endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
		else {
		
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
					cout << endl << "Commande non reconnue.  Merci d'entrer un transport valide."<<endl;
					break;
		
				}
				
				break;
			}
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
		bool shouldContinue = true;
		
		do{
			int indxEnum;
			
			cout << "Entrer la ville de depart : " << endl;
			cin >> depart;
			cout << endl << "Entrer la ville d'arrivee" << endl;
			cin >> arrivee;
			cout << "Choisir un mode de transport : " <<endl;
			
			cout << "1. Avion" << endl;
			cout << "2. Automobile"<< endl;
			cout << "3. Train" << endl;
			cout << "4. Canard geant" << endl;
			cout << "5. Tramway" << endl;
			cout << "6. Bateau" << endl;
			cout << "7. Missile nord-coreen" << endl;
			
			cin >> indxEnum;
			if(!cin){
				cout << endl << "Merci d'entrer un nombre valide."<< endl;
				cin.clear();
				cin.ignore(256,'\n');
			}
			else {
				shouldContinue = false;
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
		} while(shouldContinue);
		
		return nullptr;
}
static void loadFromTo(Catalogue & catToSave,TrajetDAO & tdao)
{
	string depart;
	string arrivee;
	cout<<"Veuillez entrer la ville de départ"<<endl;
	cin>>depart;
	cout<<"Veuillez entrer la ville d'arrivée"<<endl;
	cin>>arrivee;
	const char * departChar;
	const char * arriveeChar;
	departChar=depart.c_str();
	arriveeChar=arrivee.c_str();
	
	int nbTrajetsLoaded=tdao.LoadVille(catToSave,departChar,arriveeChar);
	if(nbTrajetsLoaded>0)
	{
		 cout<<nbTrajetsLoaded<<" trajet"<<(nbTrajetsLoaded>1?"s":"")<<" chargé"<<(nbTrajetsLoaded>1?"s":"")<<" en mémoire"<<endl;
	}
	else
	{
		cout<<"Aucun trajet n'a été chargé en mémoire"<<endl;
	}

}
static void loadInterval(Catalogue & cat,TrajetDAO & tdao)
{
	int borneInf=0;
	int borneSup=0;
	cout<<"Veuillez entrer le numéro de trajet du début."<<endl;
	cout<<"Les indices commencent à 0"<<endl;
	cout<<"Entrez un nombre négatif pour quitter"<<endl;
 	cin >> borneInf;
	while(!cin){
			cout << endl << "Merci d'entrer un nombre valide."<< endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> borneInf;
	}
	if(borneInf>=0){
					cin >> borneSup;
				while(!cin){
					cout << endl << "Merci d'entrer un nombre valide."<< endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> borneSup;
					}
				if(borneSup>=0){				
					if(borneInf>borneSup){
						int temp=borneSup;
						borneSup=borneInf;
						borneInf=temp;
					}
					int nbTrajetsLoaded=tdao.LoadInterval(borneInf,borneSup,cat);
					if(nbTrajetsLoaded>0)
					{
						 cout<<nbTrajetsLoaded<<" trajet"<<(nbTrajetsLoaded>1?"s":"")<<" chargé"<<(nbTrajetsLoaded>1?"s":"")<<" en mémoire"<<endl;
					}
					else
					{
						cout<<"Aucun trajet n'a été chargé en mémoire"<<endl;
					}
				
				}
		
	}
	
}


static void loadFromBackup(Catalogue & cat)
{
	string fileName;
	cout<<"Veuillez rentrer le nom du fichier depuis lequel vous souhaitez charger les données"<<endl;
	cin>>fileName;
	TrajetDAO tdao(fileName);
	int response=0;
	int nbTrajetsLoaded;
	while(response != -1)
	{
		cout << endl << "Voulez vous :"<< endl;
		cout << "1. Effacer tous les trajets de la sauvegarde" << endl;
		cout << "2. Charger tous les trajets du fichier"<< endl;
		cout << "3. Charger un intervalle de trajets" << endl;
		cout << "4. Charger que les trajets simples" << endl;
		cout << "5. Charger que les trajets composés" << endl;
		cout << "6. Charger que les trajets partant d'une ville et allant à une autre" << endl;
		cout << "-1 Retourner au menu principal"<<endl;
		
		cin >> response;
		if(!cin){
			cout << endl << "Merci d'entrer un nombre valide."<< endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
		else {
		
			switch(response)
			{
				case 1 : 
				{
					tdao.DeleteSaves();

					break;
				}
				case 2 : 
				{
					nbTrajetsLoaded=tdao.LoadAll(cat);
					if(nbTrajetsLoaded>0)
					{
						 cout<<nbTrajetsLoaded<<" trajet"<<(nbTrajetsLoaded>1?"s":"")<<" chargé"<<(nbTrajetsLoaded>1?"s":"")<<" en mémoire"<<endl;
					}
					else
					{
						cout<<"Aucun trajet n'a été chargé en mémoire"<<endl;
					}
					break;
				}
				case 3 : 
				{
					
					loadInterval(cat,tdao);
			
					 break;
				}
				
				case 4: 
				{
					nbTrajetsLoaded=tdao.LoadSimple(cat);
								if(nbTrajetsLoaded>0)
					{
						 cout<<nbTrajetsLoaded<<" trajet"<<(nbTrajetsLoaded>1?"s":"")<<" chargé"<<(nbTrajetsLoaded>1?"s":"")<<" en mémoire"<<endl;
					}
					else
					{
						cout<<"Aucun trajet n'a été chargé en mémoire"<<endl;
					}
					break;
				}
				case 5: 
				{
					nbTrajetsLoaded=tdao.LoadComposes(cat);
						if(nbTrajetsLoaded>0)
					{
						 cout<<nbTrajetsLoaded<<" trajet"<<(nbTrajetsLoaded>1?"s":"")<<" chargé"<<(nbTrajetsLoaded>1?"s":"")<<" en mémoire"<<endl;
					}
					else
					{
						cout<<"Aucun trajet n'a été chargé en mémoire"<<endl;
					}
					break;
				}
				case 6: 
				{
					loadFromTo(cat,tdao);
				
					break;
				}
				
				case -1 : break;
				
				default : 
				{
					cout << "Commande non reconnue."<<endl;
					break;
				}		
			}
			cout << endl;
			}
	}
}

static void saveFromTo(Catalogue & catToSave,TrajetDAO & tdao)
{
	string depart;
	string arrivee;
	cout<<"Veuillez entrer la ville de départ"<<endl;
	cin>>depart;
	cout<<"Veuillez entrer la ville d'arrivée"<<endl;
	cin>>arrivee;
	const char * departChar;
	const char * arriveeChar;
	departChar=depart.c_str();
	arriveeChar=arrivee.c_str();
	tdao.SerializeCatalogFromTo(catToSave,departChar,arriveeChar);

}
static void saveIndex(Catalogue & catToSave,TrajetDAO & tdao)
{
	int borneInf=0;
	int borneSup=0;
	cout<<"Veuillez entrer le numéro de trajet du début."<<endl;
	cout<<"Les indices commencent à 0"<<endl;
	cout<<"Entrez un nombre négatif pour quitter"<<endl;
 	cin >> borneInf;
	while(!cin){
			cout << endl << "Merci d'entrer un nombre valide."<< endl;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> borneInf;
	}
	if(borneInf>=0){
		cin >> borneSup;
		while(!cin){
					cout << endl << "Merci d'entrer un nombre valide."<< endl;
					cin.clear();
					cin.ignore(256,'\n');
					cin >> borneSup;
		}
		if(borneSup>=0){				
				  tdao.SerializeCatalogIndex(catToSave,borneInf,borneSup);
		}
	}
				
}
//Gére la sauvegarde vers un fichier
static void saveToBackup(Catalogue & catToSave)
{
	string fileName;
	cout<<"Veuillez rentrer le nom du fichier vers lequel vous souhaitez effectuer la sauvegarde"<<endl;
	cin>>fileName;
	TrajetDAO tdao(fileName);
	int response=0;
	while(response != -1)
	{
	cout << endl << "Voulez vous :"<< endl;
	cout << "1. Effacer tous les trajets de la sauvegarde" << endl;
	cout << "2. Sauvegarder tout le catalogue"<< endl;
	cout << "3. Sauvegarder un intervalle de trajets" << endl;
	cout << "4. Sauvegarder que les trajets simples" << endl;
	cout << "5. Sauvegarder que les trajets composés" << endl;
	cout << "6. Sauvegarder que les trajets partant d'une ville et allant à une autre" << endl;
	cout << "-1 Retourner au menu principal"<<endl;
		cin >> response;
		if(!cin){
			cout << endl << "Merci d'entrer un nombre valide."<< endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
		else {
		
			switch(response)
			{
				case 1 : 
				{
					tdao.DeleteSaves();
					break;
				}
				case 2 : 
				{
					tdao.SerializeAllCatalog(catToSave);				
					break;
				}
				case 3 : 
				{
					saveIndex(catToSave,tdao);
					 break;
				}
				
				case 4: 
				{
					tdao.SerializeCatalogTrajetsSimples(catToSave);
					break;
				}
				case 5: 
				{
					tdao.SerializeCatalogTrajetsComposes(catToSave);
					break;
				}
				case 6: 
				{
					saveFromTo(catToSave,tdao);
				
					break;
				}
				
				case -1 : break;
				
				default : 
				{
					cout << "Commande non reconnue."<<endl;
					break;
				}		
			}
			cout << endl;
			}
	}


}
//Fonction locale de chargement de l'interface
static void loadHCI()
{
cout<<"                                                         ___________________ "<<endl;  	
cout<<"                    /\\      _____          _____        |   |     |    | |  \\"<<endl;  
cout<<"     ,-----,       /  \\____/__|__\\_    ___/__|__\\___    |___|_____|____|_|___\\ "<<endl;  
cout<<"  ,--'---:---`--, /  |  _     |     `| |      |      `| |              | |   °|"<<endl;  
cout<<" ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------(o)--| "<<endl;  

	cout <<"\t\t\t*** TRAJET SIMULATOR 2000 ***"<<endl;                                                                       
    int response = 0;

    
	Catalogue c;
	while(response != -1)
	{
		
		cout << endl << "Selectionner un mode. Entrer -1 pour quitter." << endl << endl;
		cout<< "1. Ajouter un trajet au catalogue." << endl;
		cout << "2. Afficher le catalogue."<< endl;
		cout << "3. Recherche simple de parcours" << endl;
		cout << "4. Recherche complexe de parcours" << endl;
		cout << "5. Chargement de données depuis une sauvegarde" << endl;
		cout << "6. Sauvegarde des données" << endl;
		cin >> response;
		if(!cin){
			cout << endl << "Merci d'entrer un nombre valide."<< endl;
			cin.clear();
			cin.ignore(256,'\n');
		}
		else {
		
			switch(response)
			{
				case 1 : 
				{
					loadAddHCI(c); break;
				}
				case 2 : 
				{
					
					cout << endl << "\t\t\t*** Contenu du catalogue : ***"<<endl; 
					c.ToString();
					cout << "\t\t\t*** Fin du catalogue ***"<< endl;
					break;
				}
				case 3 : 
				{
					 
					 loadFindHCISimple(c);
					 break;
				}
				
				case 4: 
				{
					loadFindHCIComplexe(c);
					break;
				}
				case 5: 
				{
					loadFromBackup(c);
					break;
				}
				case 6: 
				{
					saveToBackup(c);
					break;
				}
				
				case -1 : break;
				
				default : 
				{
					cout << "Commande non reconnue."<<endl;
					break;
				}		
			}
			cout << endl;
		}

	}
}

void testSaveData(TrajetDAO & tdao)
{
	Trajet* ts2 = new TrajetSimple("Lyon", "Dijon", static_cast<Transport>(2));
	tdao.SerializeTrajet(ts2);
	
	TrajetCompose tc("Paris", "Toulouse", static_cast<Transport>(5));
	Trajet* ts = new TrajetSimple("Toulouse", "Bordeaux", static_cast<Transport>(3));
	tc.AddTrajet(ts);
	tdao.SerializeTrajet(&tc);
	
	Trajet* ts3 = new TrajetSimple("Macon", "Auxerre", static_cast<Transport>(1));
	tdao.SerializeTrajet(ts3);

	delete ts;
	delete ts2;
	delete ts3;
}

void testLoadTypeTrajet()
{
	TrajetDAO tdao("saveFile.txt");
	tdao.DeleteSaves();
	testSaveData(tdao);
	
	Catalogue cat;
	cout << "Un total de " << tdao.LoadSimple(cat) << " trajets simples ont été chargés depuis la sauvegarde" << endl;
	cout << "Un total de " << tdao.LoadComposes(cat) << " trajets composés ont été chargés depuis la sauvegarde" << endl;
	
	cat.ToString();
}


void testLoadTrajetCompose()
{
	TrajetDAO tdao("saveFile.txt");
	tdao.DeleteSaves();
	testSaveData(tdao);
	
	Catalogue cat;
	cout << "Un total de " << tdao.LoadAll(cat) << " trajets ont été chargés depuis la sauvegarde" << endl;
	cat.ToString();
}

void testLoadTrajetInterval()
{
	TrajetDAO tdao("saveFile.txt");
	tdao.DeleteSaves();
	testSaveData(tdao);
	Catalogue cat;
	
	int min, max;
	cout << "Min : ";
	cin >> min;
	cout << "Max : ";
	cin >> max;
	cout << "Un total de " << tdao.LoadInterval(min, max, cat) << " trajets ont été chargés depuis la sauvegarde (intervalle : [" << min << ", " << max << "])."<<endl; 
	cat.ToString();
}


/*
void testLoadTrajetSimple()
{
	TrajetDAO tdao("saveFile.txt");
	tdao.DeleteSaves();
	
	Trajet* ts = new TrajetSimple("Lyon", "Marseille", static_cast<Transport>(1));
	tdao.Serialize(ts->PrintRaw());
	delete ts;
	
	Catalogue cat;
	tdao.LoadAll(cat);
	cat.ToString();
	
}


void testSaveFile()
{
	
	TrajetDAO tdao("saveFile.txt");
	string data = "ceci est un test";
	tdao.Serialize(data);
	tdao.DeleteSaves();			//Suppression des données
	
	Trajet* ts = new TrajetSimple("Lyon", "Marseille", static_cast<Transport>(1));
	tdao.Serialize(ts->PrintRaw());
	
	TrajetCompose tc("Paris", "Toulouse", static_cast<Transport>(5));
	Trajet* ts3 = new TrajetSimple("Toulouse", "Bordeaux", static_cast<Transport>(3));
	tc.AddTrajet(ts3);
	
	tdao.Serialize(tc.PrintRaw());
	
	delete ts;
	
	
}*/

/*

	Méthode principale appelante de la classe
	argc désigne le nombre d'éventuels arguments à fournir au programme
    argv se comporte comme un tableau de chaînes de caractères contenant ces arguments
*/
void testSaveAllCatalog()
{
	Catalogue cat;
	TrajetDAO tdao("saveFileBis.txt");
	tdao.DeleteSaves();
	TrajetSimple a;

	TrajetSimple b("Paris","Lyon",static_cast<Transport>(3));
	TrajetCompose c("Paris","Lyon",static_cast<Transport>(3));
	TrajetSimple d("Lyon","Orsay",static_cast<Transport>(2));
	c.AddTrajet(d);
	cat.AddTrajet(a);
	cat.AddTrajet(b);
		cat.AddTrajet(c);
	tdao.SerializeAllCatalog(cat);
	
	
}
void testSaveTrajetFromTo()
{
	Catalogue cat;
	TrajetDAO tdao("saveFileBis.txt");
	tdao.DeleteSaves();
	TrajetSimple a;
	TrajetSimple b("Paris","Lyon",static_cast<Transport>(3));
	TrajetCompose c("Paris","Lyon",static_cast<Transport>(3));
	TrajetSimple d("Lyon","Orsay",static_cast<Transport>(2));
	c.AddTrajet(d);
	cat.AddTrajet(a);
	cat.AddTrajet(b);
		cat.AddTrajet(c);
	tdao.SerializeCatalogFromTo(cat,"Paris","Orsay");
	
}
void testSaveTrajetsSimples()
{
		Catalogue cat;
	TrajetDAO tdao("saveFileBis.txt");
	tdao.DeleteSaves();
	TrajetSimple a;
	TrajetSimple b("Paris","Lyon",static_cast<Transport>(3));
	TrajetCompose c("Paris","Lyon",static_cast<Transport>(3));
	TrajetSimple d("Lyon","Orsay",static_cast<Transport>(2));
	c.AddTrajet(d);
	cat.AddTrajet(a);
	cat.AddTrajet(b);
		cat.AddTrajet(c);
	tdao.SerializeCatalogTrajetsSimples(cat);
}
void testSaveTrajetsComposes()
{
		Catalogue cat;
	TrajetDAO tdao("saveFileBis.txt");
	tdao.DeleteSaves();
	TrajetSimple a;
	TrajetSimple b("Paris","Lyon",static_cast<Transport>(3));
	TrajetCompose c("Paris","Lyon",static_cast<Transport>(3));
	TrajetSimple d("Lyon","Orsay",static_cast<Transport>(2));
	c.AddTrajet(d);
	cat.AddTrajet(a);
	cat.AddTrajet(b);
		cat.AddTrajet(c);
	tdao.SerializeCatalogTrajetsComposes(cat);
}
void testSaveTrajetsIndices()
{
		Catalogue cat;
	TrajetDAO tdao("saveFileBis.txt");
	tdao.DeleteSaves();
	TrajetSimple a;
	TrajetSimple b("Paris","Lyon",static_cast<Transport>(3));
	TrajetCompose c("Paris","Lyon",static_cast<Transport>(3));
	TrajetSimple d("Lyon","Orsay",static_cast<Transport>(2));
	c.AddTrajet(d);
	cat.AddTrajet(a);
	cat.AddTrajet(b);
		cat.AddTrajet(c);
	tdao.SerializeCatalogIndex(cat,2,1);
}
int main(int argc, char** argv)
{

	loadHCI();
	//testSaveFile();
	//testLoadTrajetSimple();
	//testLoadTrajetCompose();
	//testLoadTypeTrajet();
	//testLoadTrajetInterval();
	//testSaveTrajetFromTo();
	//testSaveAllCatalog();
	//testSaveTrajetsSimples();
	//testSaveTrajetsComposes();
	//testSaveTrajetsIndices();
	return 0;
}  //----- Fin du main
