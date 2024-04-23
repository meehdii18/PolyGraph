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
#include <sstream>
#include <iostream>
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

	// MÉTHODES PRIVÉES

	/******************************************************
	* GPOTrouverSommet
	*******************************************************
	* Entrée : sIdentifiant l'identifiant du sommet cherché
	* Nécessite : Rien
	* Sortie : Un pointeur vers le sommet si il est dans le
	* graphe, nullptr sinon
	* Entraîne : Rien
	******************************************************/
	TSommet* GPOTrouverSommet(const string& sIdentifiant) const;

	/******************************************************
	* GPOTrouverArc
	*******************************************************
	* Entrée : sOrigine et sDestination l'origine et la
	* destination de l'arc cherché
	* Nécessite : Rien
	* Sortie : Un pointeur vers l'arc si il est dans le
	* graphe, nullptr sinon
	* Entraîne : Rien
	******************************************************/
	TArc* GPOTrouverArc(const string& sOrigine, const string& sDestination) const;

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
	~PGraphOrient() {} // A MODIFIER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// MÉTHODES

	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entraîne : Rien
	******************************************************/
	vector<vector<string>> GPOLireListeArcs() const;

	/******************************************************
	* GPOLireListeSommets
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les sommets du graphe
	* Entraîne : Rien
	******************************************************/
	vector<string> GPOLireListeSommets() const;

	/******************************************************
	* GPOLirePredecesseursSommets
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les sommets depuis
	* lesquels des arcs du graphe viennent au sommet
	* d'identifiant sIDSommet.
	* Entraîne : Rien
	******************************************************/
	vector<string> GPOLirePredecesseursSommet(const string& sIdSommet) const;

	/******************************************************
	* GPOLireSuccesseursSommets
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Le vecteur contenant les sommets vers
	* lesquels des arcs du graphe vont depuis le sommet
	* d'identifiant sIDSommet.
	* Entraîne : Rien
	******************************************************/
	vector<string> GPOLireSuccesseursSommet(const string& sIdSommet) const;

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
	* GPOSupprimerArc
	*******************************************************
	* Entrée : sOrigine et sDestination l'origine et la
	* destination de l'arc cà supprimer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La suppression de l'arc reliant les
	* sommets d'origine et de destination
	******************************************************/
	void GPOSupprimerArc(const string& sOrigine, const string& sDestination);

};

#include "CGraphOrient.th"