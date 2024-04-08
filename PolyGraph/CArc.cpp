#include "CArc.h"

CArc::CArc(const string& sOrigine, const string& sDestination) : sARCOrigine(sOrigine), sARCDestination(sDestination)
{
}

/****************************************************************
* A DEPLACER DANS CGRAPHORIENT
* 
inline void CArc::ARCModifierOrigine(const string& sParam)
{
	// MODIFIER L'ANCIEN ET LE NOUVEAU SOMMET D'ORIGINE
}

inline void CArc::ARCModifierDestination(const string& sParam)
{
	// MODIFIER L'ANCIEN ET LE NOUVEAU SOMMET DE DESTINATION
}
*****************************************************************/

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

