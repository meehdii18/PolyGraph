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


/******************************************************
* operator==
*******************************************************
* Entree : Deux arcs a comparer
* Necessite : Rien
* Sortie : Vrai si les deux arcs ont les memes
* origines, destinations et poids.
* Entraine : Rien
******************************************************/
bool CArcPondere::operator==(const CArcPondere& APRArcAComparer)
{
    return (ARCLireOrigine() == APRArcAComparer.ARCLireOrigine() and ARCLireDestination() == APRArcAComparer.ARCLireDestination() and APRArcAComparer.APRLirePoids() == APRLirePoids() );
}
