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
#include <algorithm>
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

	// MÉTHODES

	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entraîne : Rien
	******************************************************/
	vector<TArc*> GPOLireListeArcs() { return vGPOListeArcs; }

	/******************************************************
	* GPOLireListeSommets
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les sommets du graphe
	* Entraîne : Rien
	******************************************************/
	vector<TSommet*> GPOLireListeSommets() { return vGPOListeSommets; }

	/******************************************************
	* GPOAjouterSommet
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La création d'un sommet d'identifiant sIdentifiant,
	* puis l'ajout de ce sommet dans vGPOListeSommets
	******************************************************/
	void GPOAjouterSommet(const string& sIdentifiant);

	/******************************************************
	* GPOTrouverSommet
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Un pointeur vers le sommet si il est dans le
	* graphe, nullptr sinon
	* Entraîne : Rien
	******************************************************/
	TSommet* GPOTrouverSommet(const string& sIdentifiant);
};

#include "CGraphOrient.th"