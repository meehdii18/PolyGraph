#include "CArc.h"

CArc::CArc(const string& sOrigine, const string& sDestination) : sARCOrigine(sOrigine), sARCDestination(sDestination)
{
}

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

inline void CArc::ARCAfficherArc() const
{
	cout << "Origine de l'arc : \'" << ARCLireOrigine() << "\', Destination de l'arc : \'" << ARCLireDestination() << "\';";
}
