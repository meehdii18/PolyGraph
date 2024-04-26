#pragma once
/******************************************************
* CLASSE : CGraphOrient
*******************************************************
* ROLE : Interface de la classe CGraphOrient permettant
* de creer des graphes orientes et d'effectuer des
* operations de base dessus
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
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
* Pas de type particulier declare
*/

/* VARIABLES:
*/

template<class TArc, class TSommet> class PGraphOrient
{
private:
	// ATTRIBUTS

	vector<TArc*> vGPOListeArcs;

	vector<TSommet*> vGPOListeSommets;

	// METHODES PRIVEES

	/******************************************************
	* GPOTrouverSommet
	*******************************************************
	* Entree : sIdentifiant l'identifiant du sommet cherche
	* Necessite : Rien
	* Sortie : Un pointeur vers le sommet si il est dans le
	* graphe, nullptr sinon
	* Entraine : Rien
	******************************************************/
	TSommet* GPOTrouverSommet(const string& sIdentifiant) const;

	/******************************************************
	* GPOTrouverArc
	*******************************************************
	* Entree : sOrigine et sDestination l'origine et la
	* destination de l'arc cherche
	* Necessite : Rien
	* Sortie : Un pointeur vers l'arc si il est dans le
	* graphe, nullptr sinon
	* Entraine : Rien
	******************************************************/
	TArc* GPOTrouverArc(const string& sOrigine, const string& sDestination) const;

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* PGraphOrient (default)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un graphe vide est cree
	******************************************************/
	PGraphOrient() = default;

	/******************************************************
	* PGraphOrient (Recopie)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un graphe copie de GPOParam est cree
	******************************************************/
	PGraphOrient(const PGraphOrient &GPOParam);

	/******************************************************
	* PGraphOrient (Confort)
	*******************************************************
	* Entree : sFichier le chemin d'acces au fichier
	* contenant les donnees avec lesquelles initialiser le
	* graphe oriente nouvellement cree
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un graphe contenant les donnees de 
	* sFichier
	******************************************************/
	PGraphOrient(const string& sFichier);

	/******************************************************
	* ~PGraphOrient
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Le graphe est detruit, avec les sommets et
	* les arcs le composant
	******************************************************/
	~PGraphOrient();

	// METHODES

	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entraine : Rien
	******************************************************/
	vector<vector<string>> GPOLireListeArcs() const;

	/******************************************************
	* GPOLireListeSommets
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Le vecteur contenant les identifiants des 
	* sommets du graphe
	* Entraine : Rien
	******************************************************/
	vector<string> GPOLireListeSommets() const;

	/******************************************************
	* GPOLirePredecesseursSommets
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Le vecteur contenant les identifiants des 
	* sommets depuis lesquels des arcs du graphe viennent 
	* au sommet d'identifiant sIDSommet
	* Entraine : Rien
	******************************************************/
	vector<string> GPOLirePredecesseursSommet(const string& sIdSommet) const;

	/******************************************************
	* GPOLireSuccesseursSommets
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Le vecteur contenant les identifiants des 
	* sommets vers lesquels des arcs du graphe vont depuis 
	* le sommet d'identifiant sIDSommet
	* Entraine : Rien
	******************************************************/
	vector<string> GPOLireSuccesseursSommet(const string& sIdSommet) const;

	/******************************************************
	* GPOAjouterSommet
	*******************************************************
	* Entree : sIdentifiant l'identifiant du sommet a creer
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La creation d'un sommet d'identifiant 
	* sIdentifiant, puis l'ajout de ce sommet dans 
	* vGPOListeSommets.
	******************************************************/
	void GPOAjouterSommet(const string& sIdentifiant);

	/******************************************************
	* GPOSupprimerSommet
	*******************************************************
	* Entree : sIdentifiant l'identifiant du sommet a 
	* supprimer
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La suppression du sommet d'identifiant
	* sIdentifiant du graphe
	******************************************************/
	void GPOSupprimerSommet(const string& sIdentifiant);

	/******************************************************
	* GPOModifierIdentifiantSommet
	*******************************************************
	* Entree : sIdentifiant l'identifiant a modifier
	* sNouvelIdenfiant le nouvel identifiant du sommet
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La modification de l' identifiant du 
	* sommet
	******************************************************/
	void GPOModifierIdentifiantSommet(const string& sIdentifiant, const string& sNouvelIdentifiant);

	/******************************************************
	* GPOAjouterArc
	*******************************************************
	* Entree : sOrigine et sDestination l'origine et la
	* destination de l'arc a creer
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La creation d'un arc reliant les sommets
	* d'origine et de destination, si ceux-ci existent et
	* si l'arc n'existe pas.
	******************************************************/
	virtual void GPOAjouterArc(const string& sOrigine, const string& sDestination);

	/******************************************************
	* GPOSupprimerArc
	*******************************************************
	* Entree : sOrigine et sDestination l'origine et la
	* destination de l'arc a supprimer
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La suppression de l'arc reliant les
	* sommets d'origine et de destination
	******************************************************/
	virtual void GPOSupprimerArc(const string& sOrigine, const string& sDestination);

};

#include "PGraphOrient.th"
