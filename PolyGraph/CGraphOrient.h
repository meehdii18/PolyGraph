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
};

