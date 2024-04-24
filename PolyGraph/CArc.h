#pragma once
/******************************************************
* CLASSE : CArc
*******************************************************
* ROLE : Interface de la classe Carc representant les 
* arcs d'un graphe
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
* DATE : 13/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include <iostream>
#include <string>

using namespace std;

/* TYPES :
* Pas de type particulier declare
*/

/* VARIABLES:
*/

class CArc
{
private:
	// ATTRIBUTS

	string sARCOrigine;
	string sARCDestination;

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* CArc (delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un arc est initialise avec une origine et
	* une destination vide, ce constructeur donne un objet
	* non coherent qui n'est pas a utiliser en l'etat.
	* Il est donc interdit.
	******************************************************/
	CArc() = delete;

	/******************************************************
	* CArc
	*******************************************************
	* Entree : sOrigine string, l'origine de l'arc
	* sDestination string, la destination de l'arc
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un arc allant de sOrigine vers 
	* sDestination est initialise
	******************************************************/
	CArc(const string& sOrigine, const string& sDestination) : sARCOrigine(sOrigine), sARCDestination(sDestination) {}

	/******************************************************
	* ~CArc (default)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'arc est détruit
	******************************************************/
	~CArc() = default;

	// METHODES

	/******************************************************
	* ARCLireOrigine
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : sARCOrigine l'origine de l'arc
	* Entraine : Rien
	******************************************************/
	const string& ARCLireOrigine() const { return sARCOrigine; }

	/******************************************************
	* ARCLireDestination
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : sARCDestination la destination de l'arc
	* Entraine : Rien
	******************************************************/
	const string& ARCLireDestination() const { return sARCDestination; }

	/******************************************************
	* ARCModifierOrigine
	*******************************************************
	* Entree : sParam string, la nouvelle origine de l'arc
	* Necessite : le sommet d'identifiant sParam appartient 
	* au graphe
	* Sortie : Rien
	* Entraine : L'origine de l'arc est modifiee
	******************************************************/
	void ARCModifierOrigine(const string& sParam) { sARCOrigine = sParam; }

	/******************************************************
	* ARCModifierDestination
	*******************************************************
	* Entree : sParam string, la nouvelle destination 
	* de l'arc
	* Necessite : le sommet d'identifiant sParam appartient 
	* au graphe
	* Sortie : Rien
	* Entraine : La destination de l'arc est modifiee
	******************************************************/
	void ARCModifierDestination(const string& sParam) { sARCDestination = sParam; }

	/******************************************************
	* operator==
	*******************************************************
	* Entree : Deux arcs a comparer
	* Necessite : Rien
	* Sortie : Vrai si les deux arcs ont les memes 
	* origines et destinations.
	* Entraine : Rien
	******************************************************/
	bool operator==(const CArc& ARCArcAComparer) { return (ARCLireOrigine() == ARCArcAComparer.ARCLireOrigine() and ARCLireDestination() == ARCArcAComparer.ARCLireDestination()); }
};


