/*************************************************************************
                           TrajetDAO  -  Classe responsable de la sauvegarde et du chargement des objets Trajet
                             -------------------
    début                : 13/12/2016
    copyright            : (C) 2016 par Lucas POISSE
    e-mail               : poisse.lucas@gmail.com
*************************************************************************/

//---------- Interface de la classe <TrajetDAO> (fichier TrajetDAO.h) ----------------
#if ! defined ( TRAJETDAO_H )
#define TRAJETDAO_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <fstream>
#include "Catalogue.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetDAO>
//	Classe responsable de la sauvegarde et du chargement des objets Trajet
//
//------------------------------------------------------------------------

class TrajetDAO
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
void SerializeCatalogTrajetsComposes(Catalogue & catToSave);
// Sauvegarde les trajets composés du catalogue indiqué en paramètre
// dans le fichier de sauvegarde sous la forme d'une chaine de caractères
// Le format d'enregistrement est le suivant pour chaque Trajet du catalogue : <nbTrajetsSimples><CR><LF><villeDepart><CR><LF><villeArrivée><CR><LF> 
// + <indiceTransport> pour les TS OU <trajetsSimples> pour les TC + <CR><LF>

void SerializeCatalogTrajetsSimples(Catalogue & catToSave);
// Sauvegarde les trajets simples du catalogue indiqué en paramètre
// dans le fichier de sauvegarde sous la forme d'une chaine de caractères
// Le format d'enregistrement est le suivant pour chaque Trajet du catalogue : <nbTrajetsSimples><CR><LF><villeDepart><CR><LF><villeArrivée><CR><LF> 
// + <indiceTransport> pour les TS OU <trajetsSimples> pour les TC + <CR><LF>

void SerializeCatalogFromTo(Catalogue & catToSave,const char *depart,const char * arrivee);
// Sauvegarde les trajets du catalogue indiqué en paramètre allant de depart et allant vers arrivee
// dans le fichier de sauvegarde sous la forme d'une chaine de caractères
// Le format d'enregistrement est le suivant pour chaque Trajet du catalogue : <nbTrajetsSimples><CR><LF><villeDepart><CR><LF><villeArrivée><CR><LF> 
// + <indiceTransport> pour les TS OU <trajetsSimples> pour les TC + <CR><LF>


void SerializeCatalogIndex(Catalogue & catToSave,unsigned int min,unsigned int max);
// Sauvegarde les trajets situés entre l'indice min et max du catalogue indiqué en paramètre dans le fichier de sauvegarde 
//sous la forme d'une chaine de caractères. Les indices commencent à 0.
// Le format d'enregistrement est le suivant pour chaque Trajet du catalogue : <nbTrajetsSimples><CR><LF><villeDepart><CR><LF><villeArrivée><CR><LF> 
// + <indiceTransport> pour les TS OU <trajetsSimples> pour les TC + <CR><LF>

void SerializeAllCatalog(Catalogue & catToSave);
// Sauvegarde l'intégralité du catalogue indiqué en paramètre dans le fichier de sauvegarde sous la forme d'une chaine de caractères
// Le format d'enregistrement est le suivant pour chaque Trajet du catalogue : <nbTrajetsSimples><CR><LF><villeDepart><CR><LF><villeArrivée><CR><LF> 
// + <indiceTransport> pour les TS OU <trajetsSimples> pour les TC + <CR><LF>

void SerializeTrajet(Trajet* trajet);
// Sauvegarde le trajet indiqué en paramètre dans le fichier de sauvegarde sous la forme d'une chaine de caractères
// Le format d'enregistrement est le suivant : <nbTrajetsSimples><CR><LF><villeDepart><CR><LF><villeArrivée><CR><LF> 
// + <indiceTransport> pour les TS OU <trajetsSimples> pour les TC + <CR><LF>


void DeleteSaves();
//Supprime toutes les entrées de sauvegarde

int LoadAll(Catalogue & cat) ;
// Charge tous les éléments du fichier de sauvegarde en mémoire

int LoadSimple(Catalogue & cat) ;
// Charge tous les éléments de type 'trajet simple' en mémoire

int LoadComposes(Catalogue & cat) ;
// Charge tous les éléments de type 'trajet composé' en mémoire

int LoadVille(Catalogue & cat, const char* villeDep, const char* villeArr) ;
// Charge en mémoire tous les trajets dont la ville de départ et d'arrivée correspondent avec les paramètres indiqués

int LoadInterval(const int min, const int max, Catalogue & cat);
// Charge en mémoire tous les trajets sauvegardés dans l'intervalle donné (de min à max)
// Contrat : l'intervalle entré doit être valide (intervalle correct avec min <= max, et min>=0)
// Si la fonction reçoit un paramètre effectif max plus grand que le nombre de trajets enregistrés, elle se contentera de charger jusqu'au dernier trajet

//------------------------------------------------- Surcharge d'opérateurs
    
//Surcharge de l'affectation d'un TrajetDAO
 TrajetDAO & operator = ( const TrajetDAO & unTrajetDAO);

//-------------------------------------------- Constructeurs - destructeur
    TrajetDAO ( const TrajetDAO & unTrajetDAO);
    // Mode d'emploi (constructeur de copie) : effectue la construction de l'objet à partir du TrajetDAO passé en paramètre

    TrajetDAO(string filename = "save.txt");
    // Mode d'emploi : effectue la construction par défaut d'un objet TrajetDAO. 
    // Un autre paramètre correspondant au nom de fichier de sauvegarde peut être spécifié

    virtual ~TrajetDAO ( );
    // Mode d'emploi : Destruction du TrajetDAO

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	string filename;
	std::ifstream inputStream;
	std::ofstream outputStream;

//----------------------------------------------------- Attributs protégés


private:
	 void serialize(string stringToSave);
	 //Ecrit à la suite du fichier la chaine de caractere passée en paramétres
	 


	int instantiateTrajetSimple(Catalogue & cat);
	//Essaye d'instancier un trajet simple à partir de la position actuelle de lecture dans le fichier
	//Les 3 lignes suivantes du fichier sont interprétées comme la ville d'arrivée, de départ et le mode de transport du trajet simple
	//Une copie du trajet est ensuite ajoutée au catalogue. Renvoie 0 si l'instanciation a échoué (pas assez de lignes à lire)
	
	int instantiateTrajetCompose(Catalogue & cat, int nbTrajetsSimples);
	//Essaye d'instancier un trajet composé à partir de la position actuelle de lecture dans le fichier
	//Les (2+nbTrajetsSimples*4) lignes suivantes du fichier sont interprétées comme la ville d'arrivée, de départ et les différents trajets simples du TC
	//Une copie du trajet est ensuite ajoutée au catalogue. Renvoie 0 si l'instanciation a échoué (pas assez de lignes à lire)
	
};

//-------------------------------- Autres définitions dépendantes de <TrajetDAO>

#endif // TRAJETDAO_H

