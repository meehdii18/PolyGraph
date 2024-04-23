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
	* Entr�e : sOrigine et sDestination l'origine et la
	* destination de l'arc � cr�er
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La cr�ation d'un arc reliant les sommets
	* d'origine et de destination, si ceux-si existent et
	* si l'arc n'existe pas.
	******************************************************/
	void GPOAjouterArc(const string& sOrigine, const string& sDestination);

	/******************************************************
	* GPOSupprimerArc
	*******************************************************
	* Entr�e : sOrigine et sDestination l'origine et la
	* destination de l'arc c� supprimer
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La suppression de l'arc reliant les
	* sommets d'origine et de destination
	******************************************************/
	void GPOSupprimerArc(const string& sOrigine, const string& sDestination);
};

#include "CGraph.th"


