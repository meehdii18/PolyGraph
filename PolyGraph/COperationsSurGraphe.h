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
	template <template<class, class> class PGraphOrient, class TArc, class TSommet> void static OSGInverserArcs(PGraphOrient<TArc, TSommet>& GPOParam);

};

#include "COperationsSurGraphe.th"