#include "CParseur.h"
#include "CGraphOrient.h"
#include "CGraph.h"
#include "CAffichage.h"
#include "COperationsSurGraphe.h"

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

    //GPOGraphe.GPOInverserArcs();
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

    //GPOGraphe.GPOInverserArcs();
    COperationsSurGraphe::OSGInverserArcs(GPOGraphe);

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    GPOGraphe.GPOSupprimerSommet("Sommet 1 renomme");

    CAffichage::AFHAfficherGraphe(GPOGraphe);

    cout << "------------------------------------------FIN TEST------------------------------------------" << endl;
}

int main()
{

    testCGraphOrient();

    testCGraph();
    
    try
    {
        string fichier = "./donnees.txt";
        string arc = "nbarcs";

        // TEST LIRE VALEUR
        cout << "NBArcs : " << CParseur::PRSLireValeur(fichier, arc) << endl;


        // TEST LIRE VALEUR COMPLEXE
        string motCle = "Arcs";
        vector<string> delimiteurs = { "Debut","Fin" };
        map<string, vector<string>> valeursComplexes = CParseur::PRSLireValeurComplexe(fichier, motCle, delimiteurs);
        for (const auto& entry : valeursComplexes) {
            cout << "Cle : " << entry.first << endl;
            cout << "Valeur : ";
            for (const auto& value : entry.second) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
    catch (const std::runtime_error& erreur)
    {
        std::cerr << "Runtime error: " << erreur.what() << std::endl;
    }
}


