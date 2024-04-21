#pragma once
/******************************************************
* CLASSE : CSommet
*******************************************************
* ROLE : Interface de la classe CSommet représentant
* les sommets d'un graphe
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphaël AVELINE
* DATE : 13/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include "CArc.h"
#include <iostream>
#include <string>
#include <vector>
#include<sstream>
using namespace std;

/* TYPES :
* Pas de type particulier déclaré
*/

/* VARIABLES:
*/
class CSommet
{
private:
	// ATTRIBUTS
	string sSMTIdentifiant;
	
	vector<CArc*> vSMTArcsEntrants;

	vector<CArc*> vSMTArcsSortants;


public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* CSommet (interdit)
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Le sommet est initialisé avec une chaîne
	* vide, celà n'est pas vraiment utile
	* Il est donc interdit
	******************************************************/
	CSommet() = delete;


	/******************************************************
	* CSommet
	*******************************************************
	* Entrée : sParam string, l'identifiant avec lequel est
	* initialisé le sommet
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Le sommet est initialisé avec 
	* l'identifiant en paramètre
	******************************************************/
	CSommet(const string& sParam) : sSMTIdentifiant(sParam) {}

	/******************************************************
	* ~CSommet
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Le sommet est détruit ainsi que les 
	* potentiels arcs qui lui sont associés
	******************************************************/
	~CSommet();


	// MÉTHODES

	/******************************************************
	* SMTLireIdentifiant
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : L'identifiant du sommet, string
	* Entraîne : La lecture de l'attribut identifiant du 
	* sommet
	******************************************************/
	const string& SMTLireIdentifiant() const { return sSMTIdentifiant; }

	/******************************************************
	* SMTModifierIdentifiant
	*******************************************************
	* Entr�e : sNouvelIdentifiant, un string
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : sNouveauIdentifiant devient le nouvel
	* identifiant du sommet
	******************************************************/
	void SMTModifierIdentifiant(const string& sNouvelIdentifiant) { sSMTIdentifiant = sNouvelIdentifiant; }

	/******************************************************
	* SMTLireArcsEntrants
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Liste des arcs entrants du sommet, vector<CArc*>
	* Entraîne : La lecture de l'attribut contenant la 
	* liste des arcs entrants
	******************************************************/
	const vector<CArc*>& SMTLireArcsEntrants() const { return vSMTArcsEntrants; }

	/******************************************************
	* SMTAjouterArcEntrant
	*******************************************************
	* Entrée : Un arc rentrant dans le sommet
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'arc est ajouté dans la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTAjouterArcEntrant(CArc* ARCArcEntrant);

	/******************************************************
	* SMTSupprimerArcEntrant
	*******************************************************
	* Entrée : Un arc rentrant dans le sommet
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'arc est supprimé de la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTSupprimerArcEntrant(CArc* ARCArcEntrant);

	/******************************************************
	* SMTLireArcsSortants
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Liste des arcs sortants du sommet, vector<CArc*>
	* Entraîne : La lecture de l'attribut contenant la
	* liste des arcs sortants
	******************************************************/
	vector<CArc*> SMTLireArcsSortants() const { return vSMTArcsSortants; }

	/******************************************************
	* SMTAjouterArcSortant
	*******************************************************
	* Entrée : Un arc sortant du sommet
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'arc est ajouté dans la liste des arcs
	* sortant du sommet
	******************************************************/
	void SMTAjouterArcSortant(CArc* ARCArcSortant);

	/******************************************************
	* SMTSupprimerArcSortant
	*******************************************************
	* Entrée : Un arc rentrant dans le sommet
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'arc est supprimé de la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTSupprimerArcSortant(CArc* ARCArcSortant);

	/******************************************************
	* operator==
	*******************************************************
	* Entrée : Deux sommets à comparer
	* Nécessite : Rien
	* Sortie : Vrai si les deux sommets ont le même
	* identifiant
	* Entraîne : Rien
	******************************************************/
	bool operator==(const CSommet& SMTSommetAComparer) { 
		return (SMTLireIdentifiant() == SMTSommetAComparer.SMTLireIdentifiant()); }
};

