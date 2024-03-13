#pragma once
/******************************************************
* CLASSE : CArc
*******************************************************
* ROLE : Interface de la classe Carc repr�sentant
* les arcs d'un graphe
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
* DATE : 13/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include "CSommet.h"

/* TYPES :
* Pas de type particulier d�clar�
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
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Un arc est initialis� avec une origine et
	* une destination vide, ce constructeur donne un objet
	* non coh�rent qui n'est pas � utiliser en l'�tat.
	******************************************************/
	CArc();

	/******************************************************
	* CArc
	*******************************************************
	* Entr�e : sOrigine string, l'origine de l'arc
	* sDestination string, la destination de l'arc
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Un arc reliant origine vers destination
	* est initialis�
	******************************************************/
	CArc(string sOrigine, string sDestination);

	/******************************************************
	* ~CArc
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'arc est d�truit
	******************************************************/
	~CArc();

	// M�THODES

	/******************************************************
	* ARCLireOrigine
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : sARCOrigine : string
	* Entra�ne : Rien
	******************************************************/
	string ARCLireOrigine() const { return sARCOrigine; };

	/******************************************************
	* ARCLireDestination
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : sARCDestination : string
	* Entra�ne : Rien
	******************************************************/
	string ARCLireOrigine() const { return sARCDestination; };

	/******************************************************
	* ARCModifierOrigine
	*******************************************************
	* Entr�e : sParam string, la nouvelle origine de l'arc
	* N�cessite : sParam appartient au graphe
	* Sortie : Rien
	* Entra�ne : L'origine de l'arc est modifi�e
	******************************************************/
	string ARCLireOrigine() const { return sARCOrigine; };

};


