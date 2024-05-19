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
    if (argc == 3)
    {
        PGraphOrientPondere<CArcPondere, CSommet> GOPGraphe = CCreateurGraph::CCGCreerGrapheOrientPondereFichier(argv[1]);

        CAffichage::AFHAfficherGraphe(GOPGraphe);

        CAffichage::AFHAfficherCycleHamiltonien(GOPGraphe, argv[2]);
    }
    else if (argc == 2)
    {
        PGraphOrientPondere<CArcPondere, CSommet> GPOGraphe = CCreateurGraph::CCGCreerGrapheOrientPondereFichier(argv[1]);

        CAffichage::AFHAfficherGraphe(GPOGraphe);

        COperationsSurGraphe::OSGInverserArcs(GPOGraphe);

        CAffichage::AFHAfficherGraphe(GPOGraphe);
    }
    else
    {
        cout << "Veuillez rentrez le bon nombre de parametres." << endl;

        cout << "Pour creer un graphe pondere et l'inverser, entrer en parametre le chemin d'acces au fichier contenant les infos d'initialisation du graphe;" << endl;

        cout << "Pour creer un graphe pondere et afficher son cycle hamiltonien, entrer en parametre le chemin d'acces au fichier et le sommet source du cycle (qui doit appartenir au graphe)." << endl;
    }
}


