#pragma once
#include "CGraphOrient.h"
//class CGraph : public PGraphOrient
//{

//};

template<class TArc, class TSommet> class PGraph : public PGraphOrient<TArc, TSommet>
{
public :

	/******************************************************
	* GPOAjouterArc
	*******************************************************
	* Entrée : sOrigine et sDestination l'origine et la
	* destination de l'arc à créer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La création d'un arc reliant les sommets
	* d'origine et de destination, si ceux-si existent et
	* si l'arc n'existe pas.
	******************************************************/
	void GPOAjouterArc(const string& sOrigine, const string& sDestination);

	/******************************************************
	* GPOSupprimerArc
	*******************************************************
	* Entrée : sOrigine et sDestination l'origine et la
	* destination de l'arc cà supprimer
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La suppression de l'arc reliant les
	* sommets d'origine et de destination
	******************************************************/
	void GPOSupprimerArc(const string& sOrigine, const string& sDestination);
};

#include "CGraph.th"


