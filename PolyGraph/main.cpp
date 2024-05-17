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

        PGraphOrientPondere<CArcPondere, CSommet> GPOGraphe = CCreateurGraph::CCGCreerGrapheOrientPondereFichier("./donnees.txt");

        CAffichage::AFHAfficherGraphe(GPOGraphe);

        //COperationsSurGraphe::OSGInverserArcs(GPOGraphe); Inverser ne marche plus

        //CAffichage::AFHAfficherGraphe(GPOGraphe);

        //cout << COperationsSurGraphe::OSGVerifierGrapheComplet(GPOGraphe) << endl;

        CAffichage::AFHAfficherCycleHamiltonien(GPOGraphe, "O");
    }
    else
    {
        //PGraph<CArc, CSommet> GPOGraphe = CCreateurGraph::CCGCreerGrapheFichier(argv[1]);

        PGraphOrientPondere<CArcPondere, CSommet> GPOGraphe = CCreateurGraph::CCGCreerGrapheOrientPondereFichier(argv[1]);

        CAffichage::AFHAfficherGraphe(GPOGraphe);

        COperationsSurGraphe::OSGInverserArcs(GPOGraphe);

        CAffichage::AFHAfficherGraphe(GPOGraphe);

        cout << COperationsSurGraphe::OSGVerifierGrapheComplet(GPOGraphe) << endl;
    }
}


