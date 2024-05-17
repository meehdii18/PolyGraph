#pragma once
/******************************************************
* CLASSE : CGraph
*******************************************************
* ROLE : Interface de la classe CGraph permettant de 
* creer des graphes et d'effectuer des operations de
* base dessus
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
* DATE : 19/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include "PGraphOrient.h"

/* TYPES :
* Pas de type particulier declare
*/

/* VARIABLES:
*/

template<class TArc, class TSommet> class PGraph : public PGraphOrient<TArc, TSommet>
{
public :
	/******************************************************
	* PGraph (default)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un graphe vide est cree
	******************************************************/
	PGraph() = default;

	//METHODES

	/******************************************************
	* GPOAjouterArc
	*******************************************************
	* Entree : sOrigine et sDestination l'origine et la
	* destination de l'arc a creer
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La creation de deux arcs qui joignent les
	* deux sommets sOrigine et sDestination dans les deux
	* sens
	******************************************************/
	void GPOAjouterArc(const string& sOrigine, const string& sDestination);

	/******************************************************
	* GPOSupprimerArc
	*******************************************************
	* Entree : sOrigine et sDestination l'origine et la
	* destination de l'arc a supprimer
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La suppression des arcs reliant les
	* sommets d'origine et de destination
	******************************************************/
	void GPOSupprimerArc(const string& sOrigine, const string& sDestination);
};

#include "PGraph.th"
#include "CCreateurGraphe.h"


