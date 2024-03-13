#include "CArc.h"

/******************************************************
* ARCInverser
*******************************************************
* Entrée : Rien
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'origine et la destination de l'arc sont
* inversées
******************************************************/
void CArc::ARCInverser()
{
	string sTampon = sARCDestination;

	sARCDestination = sARCOrigine;

	sARCOrigine = sTampon;
}