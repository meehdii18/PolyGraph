#pragma once
/******************************************************
* CLASSE : CArcPondere
*******************************************************
* ROLE : Interface de la classe CArcPondere représentant
* des arcs mais ayant un poids
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
* DATE : 7/05/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include "CArc.h"

using namespace std;

/* TYPES :
* Pas de type particulier declare
*/

/* VARIABLES:
*/

class CArcPondere : public CArc
{
	// ATTRIBUTS
private:
	float uiPoids;

	// CONSTRUCTEURS ET DESTRUCTEURS
public:

	/******************************************************
	* CArcPondere (delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un arc est initialise avec une origine et
	* une destination vide ainsi que sans poids ce 
	* constructeur donne un objet non coherent qui n'est
	* pas a utiliser en l'etat.
	* Il est donc interdit.
	******************************************************/
	CArcPondere() = delete;

	/******************************************************
	* CArcPondere (recopie : delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un arc est unique au sein d'un graphe.
	* Il est donc interdit.
	******************************************************/
	CArcPondere(const CArcPondere& APRParam) = delete;

	/******************************************************
	* CArcPondere
	*******************************************************
	* Entree : sOrigine string, l'origine de l'arc
	* sDestination string, la destination de l'arc
	* uiPoids float, le poids de l'arc
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Un arc allant de sOrigine vers
	* sDestination est initialise avec un poids
	******************************************************/
	CArcPondere(const string& sOrigine, const string& sDestination, const float uiPoids);

	/******************************************************
	* ~CArcPondere (default)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'arc ponderé est détruit
	******************************************************/
	~CArcPondere() = default;

	// METHODES

	/******************************************************
	* ARPLirePoids
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Renvoie le poids de l'arc
	* Entraine : Rien
	******************************************************/
	const float& APRLirePoids() const { return uiPoids; };

	/******************************************************
	* ARPModifierPoids
	*******************************************************
	* Entree : uiParam float, le nouveau poids de l'arc
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Le poids de l'arc est modifie
	******************************************************/
	void APRMoidifierPoids(const float& uiParam) { uiPoids = uiParam; }
};

