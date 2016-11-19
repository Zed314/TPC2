
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

#include <iostream>
#include <cstring>

#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeTrajets.h"


using namespace std;

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
	
	TrajetSimple c("Paris", "Lyon", Transport::DosDeMathieuMaranzana);
	TrajetSimple d("Paris", "Lyon", Transport::DosDeMathieuMaranzana);
	b.AddTrajet(c);

	b.AddTrajet(d);
	b.ToString();
	TrajetCompose e;
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
	testTrajetCompose();
	//testCatalogue();

	return 0;
}  //----- Fin du main
