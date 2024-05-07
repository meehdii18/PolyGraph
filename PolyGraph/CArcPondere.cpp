#include "CArcPondere.h"

/******************************************************
* CArcPondere
*******************************************************
* Entree : sOrigine string, l'origine de l'arc
* sDestination string, la destination de l'arc
* uiPoids unsigned int, le poids de l'arc
* Necessite : Rien
* Sortie : Rien
* Entraine : Un arc allant de sOrigine vers
* sDestination est initialise avec un poids
******************************************************/
CArcPondere::CArcPondere(const string& sOrigine, const string& sDestination, const unsigned int uiParam) : CArc(sOrigine, sDestination) {
    uiPoids = uiParam;
}

bool CArcPondere::operator==(const CArcPondere& ARPArcAComparer)
{
    return (ARCLireOrigine() == ARPArcAComparer.ARCLireOrigine() and ARCLireDestination() == ARPArcAComparer.ARCLireDestination()) and ARPArcAComparer.ARPLirePoids() == ARPLirePoids();
}
