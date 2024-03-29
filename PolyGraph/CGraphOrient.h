#pragma once
/******************************************************
* CLASSE : CGraphOrient pour repr�senter un graphe 
* orient�
*******************************************************
* ROLE : Interface de la classe CGraphOrient permettant
* de cr�er des graphes orient�s et d'effectuer des
* op�rations sur celui-ci
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
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
* Pas de type particulier d�clar�
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
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Un graphe vide est cr��
	******************************************************/
	PGraphOrient();

	/******************************************************
	* PGraphOrient (Recopie)
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Un graphe copie de GPOParam est cr��
	******************************************************/
	PGraphOrient(const PGraphOrient &GPOParam);

	/******************************************************
	* ~PGraphOrient
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Un graphe vide est cr��
	******************************************************/
	~PGraphOrient();

	// M�THODES

	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entra�ne : Rien
	******************************************************/
	vector<TArc*> GPOLireListeArcs() { return vGPOListeArcs; }

	/******************************************************
	* GPOLireListeSommets
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les sommets du graphe
	* Entra�ne : Rien
	******************************************************/
	vector<TSommet*> GPOLireListeSommets() { return vGPOListeSommets; }

	/******************************************************
	* GPOAjouterSommet
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La cr�ation d'un sommet d'identifiant sIdentifiant,
	* puis l'ajout de ce sommet dans vGPOListeSommets
	******************************************************/
	void GPOAjouterSommet(const string& sIdentifiant);

	/******************************************************
	* GPOTrouverSommet
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Un pointeur vers le sommet si il est dans le
	* graphe, nullptr sinon
	* Entra�ne : Rien
	******************************************************/
	TSommet* GPOTrouverSommet(const string& sIdentifiant);
};

#include "CGraphOrient.th"