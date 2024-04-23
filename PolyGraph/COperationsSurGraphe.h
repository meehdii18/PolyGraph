#pragma once
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

class COperationsSurGraphe
{
private:
	// Aucun attribut dans cette classe car �a n'aurait pas de sens d'en ajouter

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* COperationsSurGraphe (interdit)
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Il ne fait pas vraiment sens d'instancier
	* un objet de la classe COperationsSurGraphe donc le
	* constructeur est interdit
	******************************************************/
	COperationsSurGraphe() = delete;

	// M�THODES

	/******************************************************
	* OSGInverserArcs
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Tous les arcs du graphe sont invers�s
	******************************************************/
	template <template<class, class> class PGraphOrient, class TArc, class TSommet> void static OSGInverserArcs(PGraphOrient<TArc, TSommet>& GPOParam)
	{
		vector<vector<string>> vARCListeArcs = GPOParam.GPOLireListeArcs();
		unsigned int uiBoucle = 0;
		unsigned int uiCritereArret = (unsigned int)vARCListeArcs.size();

		while (uiBoucle < uiCritereArret)
		{
			string sAncienneOrigine = vARCListeArcs[uiBoucle][0];

			string sAncienneDestination = vARCListeArcs[uiBoucle][1];

			try
			{
				GPOParam.GPOAjouterArc(sAncienneDestination, sAncienneOrigine);
				GPOParam.GPOSupprimerArc(sAncienneOrigine, sAncienneDestination);
			}
			catch (const std::logic_error& erreur)
			{
				cerr << "Logic error: " << erreur.what() << endl; // A CHANGER C DEGUEU
			}

			uiBoucle++;
		}
	}

};
