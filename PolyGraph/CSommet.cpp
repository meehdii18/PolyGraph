#include "CSommet.h"

/******************************************************
* ~CSommet
*******************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : Le sommet est détruit ainsi que les
* potentiels arcs qui lui sont associés
******************************************************/
CSommet::~CSommet()
{
	unsigned int uiNombreArcsEntrants = vSMTArcsEntrants.size();
	unsigned int uiNombreArcsSortants = vSMTArcsSortants.size();
	unsigned int uiBoucle = 0;

	for (uiBoucle = 0; uiBoucle < uiNombreArcsEntrants; uiBoucle++)
	{
		delete vSMTArcsEntrants[uiBoucle];
	}

	for (uiBoucle = 0; uiBoucle < uiNombreArcsSortants; uiBoucle++)
	{
		delete vSMTArcsSortants[uiBoucle];
	}

}

/*
void CSommet::SMTModifierIdentifiant(const string& sIdentifiant)
{
	unsigned int uiNombreArcsEntrants = vSMTArcsEntrants.size();
	unsigned int uiNombreArcsSortants = vSMTArcsSortants.size();
	unsigned int uiBoucle = 0;
	/*
	for (uiBoucle = 0; uiBoucle < uiNombreArcsEntrants; uiBoucle++)
	{
		CArc& ARCCourant = *vSMTArcsEntrants[uiBoucle];

		ARCCourant.ARCModifierDestination(sIdentifiant);
	}

	for (uiBoucle = 0; uiBoucle < uiNombreArcsSortants; uiBoucle++)
	{
		CArc& ARCCourant = *vSMTArcsSortants[uiBoucle];

		ARCCourant.ARCModifierOrigine(sIdentifiant);
	}
	
	sSMTIdentifiant = sIdentifiant;

}
*/