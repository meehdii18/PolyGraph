#include "CParseur.h"
#include "PGraphOrient.h"
#include "PGraph.h"
#include "CAffichage.h"
#include "COperationsSurGraphe.h"
#include "CCreateurGraphe.h"

#include <iostream>

using namespace std;

void testCGraphOrient()
{
    PGraphOrient<CArc, CSommet> GPOGraphe;

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOAjouterSommet("Sommet 1");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOAjouterSommet("Sommet 2");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOAjouterArc("Sommet 1", "Sommet 2");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOModifierIdentifiantSommet("Sommet 1", "Sommet 1 renomme");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    COperationsSurGraphe::OSGInverserArcs(GPOGraphe);

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOSupprimerSommet("Sommet 1 renomme");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    cout << "------------------------------------------FIN TEST------------------------------------------" << endl;
}

void testCGraph()
{
    PGraph<CArc, CSommet> GPOGraphe;

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOAjouterSommet("Sommet 1");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOAjouterSommet("Sommet 2");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOAjouterArc("Sommet 1", "Sommet 2");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOModifierIdentifiantSommet("Sommet 1", "Sommet 1 renomme");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    COperationsSurGraphe::OSGInverserArcs(GPOGraphe);

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOSupprimerSommet("Sommet 1 renomme");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    cout << "------------------------------------------FIN TEST------------------------------------------" << endl;
}

int main()
{

    //testCGraphOrient();

    //testCGraph();
    
    //PGraphOrient<CArc, CSommet> Graphe = CCreateurGraph::CCGCreerGraphOrientDepuisFichier("./donnees.txt");
    //CAffichage::AFHAfficherGraphe(Graphe);
    /*
    PGraph<CArc, CSommet> Graphe;
    CCreateurGraph::CCGImporterGrapheFichier(Graphe, "./donnees.txt");
    CAffichage::AFHAfficherGraphe(Graphe);
    */

    PGraph<CArc, CSommet> Graphe("./donnees.txt");
    CAffichage::AFHAfficherGraphe(Graphe);
    Graphe.GPOSupprimerSommet("3");
    Graphe.GPOSupprimerArc("1", "2");
    CAffichage::AFHAfficherGraphe(Graphe);
}


