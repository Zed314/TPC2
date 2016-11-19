
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
	t1.ToString();
	lt.AddT(t1);
	lt.ToString();
	TrajetSimple *t2=new TrajetSimple();
	t2->ToString();
	delete t2;
	
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
	
	
}
void testCatalogue()
{
	Catalogue catalogue;
	TrajetSimple a("Lyon", "Paris", Transport::Automobile);
	TrajetSimple b("Paris", "Dourdan", Transport::Avion);
	TrajetCompose tc(a);

	tc.AddTrajet(b);
	catalogue.AddTrajet(a);
	catalogue.AddTrajet(b);
	catalogue.AddTrajet(tc);
	catalogue.ToString();
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
	//testConstructeurDeCopie();
	//testConstructeurDeCopieListe();
	//testTrajetCompose();
	testCatalogue();

	return 0;
}  //----- Fin du main
