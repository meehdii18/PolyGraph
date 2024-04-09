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

#include <iostream>
#include <string>

using namespace std;

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
	* CArc (interdit)
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Un arc est initialisé avec une origine et
	* une destination vide, ce constructeur donne un objet
	* non cohérent qui n'est pas à utiliser en l'état.
	* Il est donc interdit.
	******************************************************/
	CArc() = delete;

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
	CArc(const string &sOrigine, const string &sDestination);

	// MÉTHODES

	/******************************************************
	* ARCLireOrigine
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : sARCOrigine : string
	* Entraîne : Rien
	******************************************************/
	const string& ARCLireOrigine() const { return sARCOrigine; }

	/******************************************************
	* ARCLireDestination
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : sARCDestination : string
	* Entraîne : Rien
	******************************************************/
	const string& ARCLireDestination() const { return sARCDestination; }

	/******************************************************
	* ARCModifierOrigine
	*******************************************************
	* Entrée : sParam string, la nouvelle origine de l'arc
	* Nécessite : sParam appartient au graphe
	* Sortie : Rien
	* Entraîne : L'origine de l'arc est modifiée
	******************************************************/
	//inline void ARCModifierOrigine(const string& sParam);

	/******************************************************
	* ARCModifierDestination
	*******************************************************
	* Entrée : sParam string, la nouvelle destination 
	* de l'arc
	* Nécessite : sParam appartient au graphe
	* Sortie : Rien
	* Entraîne : La destination de l'arc est modifiée
	******************************************************/
	//inline void ARCModifierDestination(const string& sParam);

	/******************************************************
	* ARCInverser
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'origine et la destination de l'arc sont
	* inversées
	******************************************************/
	void ARCInverser(); // A DEPLACER DE CARC.h

	/******************************************************
	* operator==
	*******************************************************
	* Entrée : Deux arcs à comparer
	* Nécessite : Rien
	* Sortie : Vrai si les deux arcs ont les mêmes 
	* origines et destinations.
	* Entraîne : Rien
	******************************************************/
	bool operator==(const CArc& ARCArcAComparer) { return (ARCLireOrigine() == ARCArcAComparer.ARCLireOrigine() and ARCLireDestination() == ARCArcAComparer.ARCLireDestination()); }
};


