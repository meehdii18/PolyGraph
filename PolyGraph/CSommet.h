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
	string SMTLireIdentifiant() const { return sSMTIdentifiant; };

	/******************************************************
	* SMTModifierIdentifiant
	*******************************************************
	* Entrée : sIdentifiant, string
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La modification de l'attribut identifiant
	* du sommet
	******************************************************/
	void SMTModifierIdentifiant(const string &sIdentifiant);

	/******************************************************
	* SMTLireArcsEntrants
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Liste des arcs entrants du sommet, vector<CArc*>
	* Entraîne : La lecture de l'attribut contenant la 
	* liste des arcs entrants
	******************************************************/
	vector<CArc*> SMTLireArcsEntrants() const { return vSMTArcsEntrants; };

	/******************************************************
	* SMTLireArcsSortants
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Liste des arcs sortants du sommet, vector<CArc*>
	* Entraîne : La lecture de l'attribut contenant la
	* liste des arcs sortants
	******************************************************/
	vector<CArc*> SMTLireArcsSortants() const { return vSMTArcsSortants; };

		/******************************************************
		* SMTAfficherArcsEntrants
		*******************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : Affichage des arcs entrants dans la console
		******************************************************/
		void SMTAfficherArcsEntrants(); // A DEPLACER DE CSOMMET.h

		/******************************************************
		* SMTAfficherArcsSortants
		*******************************************************
		* Entrée : Rien
		* Nécessite : Rien
		* Sortie : Rien
		* Entraîne : Affichage des arcs sortants dans la console
		******************************************************/
		void SMTAfficherArcsSortants(); // A DEPLACER DE CSOMMET.h

};

