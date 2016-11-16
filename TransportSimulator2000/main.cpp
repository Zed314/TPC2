
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
	TrajetSimple *t1=new TrajetSimple("Lyon", "Paris", Transport::Automobile);
	t1->ToString();
	lt.AddT(t1);
	lt.ToString();
	
}


void testConstructeurDeCopie()
{
	TrajetSimple a("Lyon", "Paris", Transport::Automobile);
	a.ToString();
	{
	TrajetSimple b(a);
	b.ToString();
	}
	a.ToString();
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
	testListe();
	testConstructeurDeCopie();

	return 0;
}  //----- Fin du main
