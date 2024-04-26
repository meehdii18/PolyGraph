#include "CSommet.h"

/******************************************************
* SMTAjouterArcEntrant
*******************************************************
* Entree : Un arc rentrant dans le sommet
* Necessite : Rien
* Sortie : Rien
* Entraine : L'arc est ajoute dans la liste des arcs
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
			ssMessageErreur << " existe deja et n'a donc pas ete ajoute.";

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
* Entree : Un arc rentrant dans le sommet
* Necessite : Rien
* Sortie : Rien
* Entraine : L'arc est supprime de la liste des arcs
* entrant dans le sommet
******************************************************/
void CSommet::SMTSupprimerArcEntrant(CArc* ARCArcEntrant)
{
	vSMTArcsEntrants.erase(remove_if(vSMTArcsEntrants.begin(),
		vSMTArcsEntrants.end(),
		[&](CArc* ARCElement) {return *ARCElement == *ARCArcEntrant; }),
		vSMTArcsEntrants.end());
}

/******************************************************
* SMTAjouterArcSortant
*******************************************************
* Entree : Un arc sortant du sommet
* Necessite : Rien
* Sortie : Rien
* Entraine : L'arc est ajoute dans la liste des arcs
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
			ssMessageErreur << " existe deja et n'a donc pas ete ajoute.";

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
* Entree : Un arc rentrant dans le sommet
* Necessite : Rien
* Sortie : Rien
* Entraine : L'arc est supprime de la liste des arcs
* sortants du sommet
******************************************************/
void CSommet::SMTSupprimerArcSortant(CArc* ARCArcSortant)
{
	vSMTArcsSortants.erase(remove_if(vSMTArcsSortants.begin(),
		vSMTArcsSortants.end(),
		[&](CArc* ARCElement) { return *ARCElement == *ARCArcSortant; }),
		vSMTArcsSortants.end());
}
