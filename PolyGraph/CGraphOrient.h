#pragma once
/******************************************************
* CLASSE : CGraphOrient pour représenter un graphe 
* orienté
*******************************************************
* ROLE : Interface de la classe CGraphOrient permettant
* de créer des graphes orientés et d'effectuer des
* opérations sur celui-ci
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphaël AVELINE
* DATE : 19/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include "CArc.h"
#include "CSommet.h"

#include <vector>
using namespace std;

/* TYPES :
* Pas de type particulier déclaré
*/

/* VARIABLES:
*/
template<class TArc, class TSommet> class PGraphOrient
{
private:
	// ATTRIBUTS

	vector<TArc*> vGPOListeArcs;

	vector<TSommet*> vGPOListeSommets;

public:
	// CONSTRUCTEURS ET DESTRUCTEURS

	/******************************************************
	* PGraphOrient
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Un graphe vide est créé
	******************************************************/
	PGraphOrient();

	/******************************************************
	* PGraphOrient (Recopie)
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Un graphe copie de GPOParam est créé
	******************************************************/
	PGraphOrient(const PGraphOrient &GPOParam);

	/******************************************************
	* ~PGraphOrient
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Un graphe vide est créé
	******************************************************/
	~PGraphOrient();
};

