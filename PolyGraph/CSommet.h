#pragma once
/******************************************************
* CLASSE : CSommet
*******************************************************
* ROLE : Interface de la classe CSommet repr�sentant
* les sommets d'un graphe
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
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
* Pas de type particulier d�clar�
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
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le sommet est initialis� avec une cha�ne
	* vide, cel� n'est pas vraiment utile
	* Il est donc interdit
	******************************************************/
	CSommet() = delete;


	/******************************************************
	* CSommet
	*******************************************************
	* Entr�e : sParam string, l'identifiant avec lequel est
	* initialis� le sommet
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le sommet est initialis� avec 
	* l'identifiant en param�tre
	******************************************************/
	CSommet(const string& sParam) : sSMTIdentifiant(sParam) {}

	/******************************************************
	* ~CSommet
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le sommet est d�truit ainsi que les 
	* potentiels arcs qui lui sont associ�s
	******************************************************/
	~CSommet();


	// M�THODES

	/******************************************************
	* SMTLireIdentifiant
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : L'identifiant du sommet, string
	* Entra�ne : La lecture de l'attribut identifiant du 
	* sommet
	******************************************************/
	const string& SMTLireIdentifiant() const { return sSMTIdentifiant; };

	/******************************************************
	* SMTLireArcsEntrants
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Liste des arcs entrants du sommet, vector<CArc*>
	* Entra�ne : La lecture de l'attribut contenant la 
	* liste des arcs entrants
	******************************************************/
	vector<CArc*> SMTLireArcsEntrants() const { return vSMTArcsEntrants; };

	/******************************************************
	* SMTAjouterArcEntrant
	*******************************************************
	* Entr�e : Un arc rentrant dans le sommet
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'arc est ajout� dans la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTAjouterArcEntrant(CArc* ARCArcEntrant);

	/******************************************************
	* SMTSupprimerArcEntrant
	*******************************************************
	* Entr�e : Un arc rentrant dans le sommet
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'arc est supprim� de la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTSupprimerArcEntrant(CArc* ARCArcEntrant);

	/******************************************************
	* SMTLireArcsSortants
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Liste des arcs sortants du sommet, vector<CArc*>
	* Entra�ne : La lecture de l'attribut contenant la
	* liste des arcs sortants
	******************************************************/
	vector<CArc*> SMTLireArcsSortants() const { return vSMTArcsSortants; };

	/******************************************************
	* SMTAjouterArcSortant
	*******************************************************
	* Entr�e : Un arc sortant du sommet
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'arc est ajout� dans la liste des arcs
	* sortant du sommet
	******************************************************/
	void SMTAjouterArcSortant(CArc* ARCArcSortant);

	/******************************************************
	* SMTSupprimerArcSortant
	*******************************************************
	* Entr�e : Un arc rentrant dans le sommet
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'arc est supprim� de la liste des arcs
	* entrant dans le sommet
	******************************************************/
	void SMTSupprimerArcSortant(CArc* ARCArcSortant);

	/******************************************************
	* operator==
	*******************************************************
	* Entr�e : Deux sommets � comparer
	* N�cessite : Rien
	* Sortie : Vrai si les deux sommets ont le m�me
	* identifiant
	* Entra�ne : Rien
	******************************************************/
	bool operator==(const CSommet& SMTSommetAComparer) { 
		return (SMTLireIdentifiant() == SMTSommetAComparer.SMTLireIdentifiant()); }
};

