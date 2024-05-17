#pragma once
/******************************************************
* CLASSE : COperationsSurGraphe
*******************************************************
* ROLE : Classe permettant d'effectuer des
* operations plus avancees sur les graphes
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
* DATE : 19/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include "PGraphOrient.h"

#include <iostream>

using namespace std;

/* TYPES :
* Pas de type particulier declare
*/

/* VARIABLES:
*/

class COperationsSurGraphe
{
private:
	//ATTRIBUTS

	// Aucun attribut dans cette classe car ça n'aurait pas de sens d'en ajouter

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* COperationsSurGraphe (delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Il ne fait pas vraiment sens d'instancier
	* un objet de la classe COperationsSurGraphe donc le
	* constructeur est interdit
	******************************************************/
	COperationsSurGraphe() = delete;

	// METHODES

	/******************************************************
	* OSGInverserArcs
	*******************************************************
	* Entree : GPOParam un graphe oriente
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Inverse le sens de tous les arcs du graphe
	******************************************************/
	template <template<class, class> class PGraphOrient, class TArc, class TSommet> void static OSGInverserArcs(PGraphOrient<TArc, TSommet>& GPOParam);

	/******************************************************
	* OSGInverserArcs (ponderes)
	*******************************************************
	* Entree : GOPParam un graphe oriente
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Inverse le sens de tous les arcs du graphe
	******************************************************/
	template <template<class CArcPondere, class> class PGraphOrient, class TSommet> void static OSGInverserArcs(PGraphOrient<CArcPondere, TSommet>& GOPParam);

	/******************************************************
	* OSGVerifierGrapheComplet
	*******************************************************
	* Entree : GPOParam un graphe oriente
	* Necessite : Rien
	* Sortie : Vrai si le graphe est complet, faux sinon
	* Entraine : Rien
	******************************************************/
	template <template<class, class> class PGraphOrient, class TArc, class TSommet> bool static OSGVerifierGrapheComplet(const PGraphOrient<TArc, TSommet>& GPOParam);

	/******************************************************
	* OSGCycleHamiltonienInsertionMinMax
	*******************************************************
	* Entree : GPOParam un graphe oriente
	* Necessite : Rien
	* Sortie : un vecteur de string contenant les
	* identifiants des sommets du graphe, ordonnes pour
	* former le cylce hamiltonien du graphe
	* Entraine : Rien
	******************************************************/
	template <template<class CArcPondere, class> class PGraphOrientPondere, class TSommet> vector<string> static OSGCycleHamiltonienInsertionMinMax(const PGraphOrientPondere<CArcPondere, TSommet>& GOPParam, const string& sSommetSource);

	/******************************************************
	* OSGCoutParcoursSommets
	*******************************************************
	* Entree : un vecteur de string vsParcours
	* Necessite : vsParcours doit representer un parcours
	* valide du graphe, c'est à dire ne contenir que des
	* identifiants de sommets du graphe relies entre eux
	* Sortie : float : le cout du parcours
	* Entraine : Rien
	******************************************************/
	template <template<class CArcPondere, class> class PGraphOrientPondere, class TSommet> float static OSGCoutParcoursSommets(const PGraphOrientPondere<CArcPondere, TSommet>& GOPParam, const vector<string>& vsParcours);
};

#include "COperationsSurGraphe.th"