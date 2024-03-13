#pragma once
/******************************************************
* CLASSE : CArc
*******************************************************
* ROLE : Interface de la classe Carc représentant
* les arcs d'un graphe
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphaël AVELINE
* DATE : 13/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include "CSommet.h"

/* TYPES :
* Pas de type particulier déclaré
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
	* CArc
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Un arc est initialisé avec une origine et
	* une destination vide, ce constructeur donne un objet
	* non cohérent qui n'est pas à utiliser en l'état.
	******************************************************/
	CArc();

	/******************************************************
	* CArc
	*******************************************************
	* Entrée : sOrigine string, l'origine de l'arc
	* sDestination string, la destination de l'arc
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Un arc reliant origine vers destination
	* est initialisé
	******************************************************/
	CArc(string sOrigine, string sDestination);

	/******************************************************
	* ~CArc
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'arc est détruit
	******************************************************/
	~CArc();

	// MÉTHODES

	/******************************************************
	* ARCLireOrigine
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : sARCOrigine : string
	* Entraîne : Rien
	******************************************************/
	string ARCLireOrigine() const { return sARCOrigine; };

	/******************************************************
	* ARCLireDestination
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : sARCDestination : string
	* Entraîne : Rien
	******************************************************/
	string ARCLireOrigine() const { return sARCDestination; };

	/******************************************************
	* ARCModifierOrigine
	*******************************************************
	* Entrée : sParam string, la nouvelle origine de l'arc
	* Nécessite : sParam appartient au graphe
	* Sortie : Rien
	* Entraîne : L'origine de l'arc est modifiée
	******************************************************/
	string ARCLireOrigine() const { return sARCOrigine; };

};


