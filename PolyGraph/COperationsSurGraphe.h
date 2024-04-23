#pragma once
#include "CGraphOrient.h"
#include <iostream>

using namespace std;

class COperationsSurGraphe
{
private:
	// Aucun attribut dans cette classe car ça n'aurait pas de sens d'en ajouter

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* COperationsSurGraphe (interdit)
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Il ne fait pas vraiment sens d'instancier
	* un objet de la classe COperationsSurGraphe donc le
	* constructeur est interdit
	******************************************************/
	COperationsSurGraphe() = delete;

	// MÉTHODES

	/******************************************************
	* OSGInverserArcs
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Tous les arcs du graphe sont inversés
	******************************************************/
	template <template<class, class> class PGraphOrient, class TArc, class TSommet> void static OSGInverserArcs(PGraphOrient<TArc, TSommet>& GPOParam);

};

#include "COperationsSurGraphe.th"