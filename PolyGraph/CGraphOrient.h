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
#include <functional>
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
	PGraphOrient() {}

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
	* Entraîne : Le graphe est détruit
	******************************************************/
	~PGraphOrient() {}

	// MÉTHODES

	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entraîne : Rien
	******************************************************/
	const vector<TArc*>& GPOLireListeArcs() const { return vGPOListeArcs; }

	/******************************************************
	* GPOLireListeSommets
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les sommets du graphe
	* Entraîne : Rien
	******************************************************/
	const vector<TSommet*>& GPOLireListeSommets() const { return vGPOListeSommets; }

	/******************************************************
	* GPOAjouterSommet
	*******************************************************
	* Entrée : sIdentifiant l'identifiant du sommet à créer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La création d'un sommet d'identifiant 
	* sIdentifiant, puis l'ajout de ce sommet dans 
	* vGPOListeSommets.
	******************************************************/
	void GPOAjouterSommet(const string& sIdentifiant);

	/******************************************************
	* GPOSupprimerSommet
	*******************************************************
	* Entrée : sIdentifiant l'identifiant du sommet à 
	* supprimer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La suppression du sommet d'identifiant
	* sIdentifiant du graphe
	******************************************************/
	void GPOSupprimerSommet(const string& sIdentifiant);

	/******************************************************
	* GPOTrouverSommet
	*******************************************************
	* Entrée : sIdentifiant l'identifiant du sommet cherché
	* Nécessite : Rien
	* Sortie : Un pointeur vers le sommet si il est dans le
	* graphe, nullptr sinon
	* Entraîne : Rien
	******************************************************/
	TSommet* GPOTrouverSommet(const string& sIdentifiant);

	/******************************************************
	* GPOModifierIdentifiantSommet
	*******************************************************
	* Entrée : sIdentifiant, string, identifiant à modifier
	* sNouvelIdenfiant, string, le nouvel identifiant du
	* sommet
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La modification de l'attribut identifiant
	* du sommet
	******************************************************/
	void GPOModifierIdentifiantSommet(const string& sIdentifiant, const string& sNouvelIdentifiant);

	/******************************************************
	* GPOAjouterArc
	*******************************************************
	* Entrée : sOrigine et sDestination l'origine et la
	* destination de l'arc à créer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La création d'un arc reliant les sommets
	* d'origine et de destination, si ceux-si existent et
	* si l'arc n'existe pas.
	******************************************************/
	void GPOAjouterArc(const string& sOrigine, const string& sDestination);

	/******************************************************
	* GPOTrouverArc
	*******************************************************
	* Entrée : sOrigine et sDestination l'origine et la
	* destination de l'arc cherché
	* Nécessite : Rien
	* Sortie : Un pointeur vers le'arc si il est dans le
	* graphe, nullptr sinon
	* Entraîne : Rien
	******************************************************/
	TArc* GPOTrouverArc(const string& sOrigine, const string& sDestination);
};

#include "CGraphOrient.th"