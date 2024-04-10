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
	unsigned int uiNombreArcsEntrants = (unsigned int) vSMTArcsEntrants.size();
	unsigned int uiNombreArcsSortants = (unsigned int) vSMTArcsSortants.size();
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

/******************************************************
* SMTAjouterArcEntrant
*******************************************************
* Entrée : Un arc rentrant dans le sommet
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'arc est ajouté dans la liste des arcs
* entrant dans le sommet
******************************************************/
void CSommet::SMTAjouterArcEntrant(CArc* ARCArcEntrant)
{
	unsigned int uiBoucle = 0;
	unsigned int uiCritereArret = (unsigned int) vSMTArcsEntrants.size();

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

/******************************************************
* SMTSupprimerArcEntrant
*******************************************************
* Entrée : Un arc rentrant dans le sommet
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'arc est supprimé de la liste des arcs
* entrant dans le sommet
******************************************************/
void CSommet::SMTSupprimerArcEntrant(CArc* ARCArcEntrant)
{
	vSMTArcsEntrants.erase(remove_if(vSMTArcsEntrants.begin(),
		vSMTArcsEntrants.end(),
		[&](CArc* ARCElement) {return *ARCElement == *ARCArcEntrant; }));
}

/******************************************************
* SMTAjouterArcSortant
*******************************************************
* Entrée : Un arc sortant du sommet
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'arc est ajouté dans la liste des arcs
* sortant du sommet
******************************************************/
void CSommet::SMTAjouterArcSortant(CArc* ARCArcSortant)
{
	unsigned int uiBoucle = 0;
	unsigned int uiCritereArret = (unsigned int) vSMTArcsSortants.size();

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

/******************************************************
* SMTSupprimerArcSortant
*******************************************************
* Entrée : Un arc rentrant dans le sommet
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'arc est supprimé de la liste des arcs
* entrant dans le sommet
******************************************************/
void CSommet::SMTSupprimerArcSortant(CArc* ARCArcSortant)
{
	vSMTArcsSortants.erase(remove_if(vSMTArcsSortants.begin(),
		vSMTArcsSortants.end(),
		[&](CArc* ARCElement) {return *ARCElement == *ARCArcSortant; }));
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