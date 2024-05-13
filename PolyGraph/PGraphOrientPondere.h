#pragma once
#include "PGraphOrient.h"
template<class TArc, class TSommet> class PGraphOrientPondere :
    public PGraphOrient<TArc,TSommet>
{
public:
	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entraine : Rien
	******************************************************/
	vector<vector<string>> GPOLireListeArcs() const;

	/******************************************************
	* GPOAjouterArc
	*******************************************************
	* Entree : sOrigine, sDestination et fPoids
	* respectivement l'origine, la destination et le poids
	* de l'arc a creer
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La creation d'un arc reliant les sommets
	* d'origine et de destination, si ceux-ci existent et
	* si l'arc n'existe pas.
	******************************************************/
	void GPOAjouterArc(const string& sOrigine, const string& sDestination, const float fPoids);
};

#include "PGraphOrientPondere.th"

