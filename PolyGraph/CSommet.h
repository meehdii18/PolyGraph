#pragma once
/******************************************************
* CLASSE : CSommet
*******************************************************
* ROLE : Interface de la classe CSommet representant
* les sommets d'un graphe
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
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
* Pas de type particulier declare
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
	* CSommet (delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Le sommet est initialise avec une chaine
	* vide, cela  n'est pas vraiment utile
	* Il est donc interdit
	******************************************************/
	CSommet() = delete;

	/******************************************************
	* CSommet (recopie : delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un identifiant de sommet est unique au
	* sein d'un graphe
	* Il est donc interdit
	******************************************************/
	CSommet(const CSommet& SMTParam) = delete;

	/******************************************************
	* CSommet (confort)
	*******************************************************
	* Entree : sParam string, l'identifiant avec lequel est
	* initialise le sommet
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Le sommet est initialise avec 
	* l'identifiant en parametre
	******************************************************/
	CSommet(const string& sParam) : sSMTIdentifiant(sParam) {}

	/******************************************************
	* ~CSommet (default)
	*******************************************************
	* Entree : Rien
	* Necessite : Les arcs pointés dans vSMTArcsEntrants
	* et vSMTArcSortants ne sont pas détruits ici et cela
	* doit donc etre gere avant l'appel au destructeur
	* Sortie : Rien
	* Entraine : Le sommet est detruit
	******************************************************/
	~CSommet() = default;


	// METHODES

	/******************************************************
	* SMTLireIdentifiant
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : sSMTIdentifiant l'identifiant du sommet
	* Entraine : Rien
	******************************************************/
	const string& SMTLireIdentifiant() const { return sSMTIdentifiant; }

	/******************************************************
	* SMTModifierIdentifiant
	*******************************************************
	* Entree : sNouvelIdentifiant, le nouvel identifiant du
	* sommet
	* Necessite : sNouvelIdentifiant ne doit pas etre 
	* l'identifiant d'un autre sommet du graphe
	* Sortie : Rien
	* Entraine : sNouvelIdentifiant devient le nouvel
	* identifiant du sommet
	******************************************************/
	void SMTModifierIdentifiant(const string& sNouvelIdentifiant) { sSMTIdentifiant = sNouvelIdentifiant; }

	/******************************************************
	* SMTLireArcsEntrants
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : La liste des arcs entrant dans le sommet
	* Entraine : Rien
	******************************************************/
	const vector<CArc*>& SMTLireArcsEntrants() const { return vSMTArcsEntrants; }

	/******************************************************
	* SMTAjouterArcEntrant
	*******************************************************
	* Entree : Un arc rentrant dans le sommet
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'arc est ajoute dans la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTAjouterArcEntrant(CArc* ARCArcEntrant);

	/******************************************************
	* SMTSupprimerArcEntrant
	*******************************************************
	* Entree : Un arc rentrant dans le sommet
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'arc est supprime de la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTSupprimerArcEntrant(CArc* ARCArcEntrant);

	/******************************************************
	* SMTLireArcsSortants
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Liste des arcs sortant du sommet
	* Entraine : Rien
	******************************************************/
	vector<CArc*> SMTLireArcsSortants() const { return vSMTArcsSortants; }

	/******************************************************
	* SMTAjouterArcSortant
	*******************************************************
	* Entree : Un arc sortant du sommet
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'arc est ajoute dans la liste des arcs
	* sortant du sommet
	******************************************************/
	void SMTAjouterArcSortant(CArc* ARCArcSortant);

	/******************************************************
	* SMTSupprimerArcSortant
	*******************************************************
	* Entree : Un arc rentrant dans le sommet
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'arc est supprime de la liste des arcs
	* sortants du sommet
	******************************************************/
	void SMTSupprimerArcSortant(CArc* ARCArcSortant);

	/******************************************************
	* operator==
	*******************************************************
	* Entree : Deux sommets a comparer
	* Necessite : Rien
	* Sortie : Vrai si les deux sommets ont le meme
	* identifiant
	* Entraine : Rien
	******************************************************/
	bool operator==(const CSommet& SMTSommetAComparer) { 
		return (SMTLireIdentifiant() == SMTSommetAComparer.SMTLireIdentifiant()); }
};

