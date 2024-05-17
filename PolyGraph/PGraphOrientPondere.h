#pragma once
#include "PGraphOrient.h"
template<class TArc, class TSommet> class PGraphOrientPondere :
    public PGraphOrient<TArc,TSommet>
{
	static_assert(std::is_base_of<CArcPondere, TArc>::value, "TArc must be derived from CArcPondere");


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

	/******************************************************
	* fGPOPoidsArc
	*******************************************************
	* Entree : sOrigine et sDestination l'origine et la 
	* destination de l'arc dont on veux récupérer le poids
	* Necessite : l'arc sOrigine -> sDestination existe
	* dans le graphe
	* Sortie : Le poids de l'arc d'origine sOrigine et de
	* destination sDestination
	* Entraine : Rien
	******************************************************/
	float fGPOPoidsArc(const string& sOrigine, const string& sDestination) const;
};

#include "PGraphOrientPondere.th"

