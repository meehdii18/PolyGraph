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

void CSommet::SMTAjouterArcEntrant(CArc* ARCArcEntrant)
{
	unsigned int uiBoucle = 0;
	unsigned int uiCritereArret = vSMTArcsEntrants.size();

	while (uiBoucle < uiCritereArret)
	{
		if (*vSMTArcsEntrants[uiBoucle] == *ARCArcEntrant )
		{
			ostringstream ssMessageErreur;

			ssMessageErreur << "L'arc d'origine ";
			ssMessageErreur << ARCArcEntrant->ARCLireOrigine().c_str();
			ssMessageErreur << " et allant vers le sommet ";
			ssMessageErreur << SMTLireIdentifiant().c_str();
			ssMessageErreur << " existe déjà et n'a donc pas été ajouté.";

			string sDescription = ssMessageErreur.str();

			throw logic_error(sDescription);
		}
		uiBoucle++;
	}

	vSMTArcsEntrants.push_back(ARCArcEntrant);
}

void CSommet::SMTAjouterArcSortant(CArc* ARCArcSortant)
{
	unsigned int uiBoucle = 0;
	unsigned int uiCritereArret = vSMTArcsSortants.size();

	while (uiBoucle < uiCritereArret)
	{
		if (*vSMTArcsSortants[uiBoucle] == *ARCArcSortant)
		{
			ostringstream ssMessageErreur;

			ssMessageErreur << "L'arc d'origine ";
			ssMessageErreur << ARCArcSortant->ARCLireDestination().c_str();
			ssMessageErreur << " et allant vers le sommet ";
			ssMessageErreur << SMTLireIdentifiant().c_str();
			ssMessageErreur << " existe déjà et n'a donc pas été ajouté.";

			string sDescription = ssMessageErreur.str();

			throw logic_error(sDescription);
		}
		uiBoucle++;
	}

	vSMTArcsSortants.push_back(ARCArcSortant);
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