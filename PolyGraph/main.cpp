#include "CParseur.h"
#include "PGraphOrient.h"
#include "PGraph.h"
#include "CAffichage.h"
#include "COperationsSurGraphe.h"
#include "CCreateurGraphe.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Veuillez rentrez le bon nombre de parametres." << endl;
    }
    else
    {
        PGraphOrient<CArc, CSommet> GPOGraphe(argv[1]);

        CAffichage::AFHAfficherGraphe(GPOGraphe);

        COperationsSurGraphe::OSGInverserArcs(GPOGraphe);

        CAffichage::AFHAfficherGraphe(GPOGraphe);
    }
}


