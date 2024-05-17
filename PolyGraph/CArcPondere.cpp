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
CArcPondere::CArcPondere(const string& sOrigine, const string& sDestination, const float fPoids) : CArc(sOrigine, sDestination) {
    fAPRPoids = fPoids;
}

CArcPondere::CArcPondere(const string& sOrigine, const string& sDestination) : CArc(sOrigine, sDestination) {
    fAPRPoids = 0;
}
