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

