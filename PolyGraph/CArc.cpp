#include "CArc.h"

/******************************************************
* ARCInverser
*******************************************************
* Entr�e : Rien
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : L'origine et la destination de l'arc sont
* invers�es
******************************************************/
void CArc::ARCInverser()
{
	string sTampon = sARCDestination;

	sARCDestination = sARCOrigine;

	sARCOrigine = sTampon;
}