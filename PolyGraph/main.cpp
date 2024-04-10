#include <iostream>
#include "CParseur.h"
#include "CGraphOrient.h"
#include "CAffichage.h"

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

    GPOGraphe.GPOSupprimerSommet("Sommet 1");

    CAffichage::AFHAfficherGraphe(GPOGraphe);
}

int main()
{
    testCGraphOrient();

    cout << "------------------------------------------FIN TEST------------------------------------------" << endl;

    vector<string> Delimiteurs = { "Arcs","Sommets" };
    map<string,unsigned int> data = CParseur::PRSParserFichier("./donnes.txt",Delimiteurs);
    
    for (const auto& pair : data) {
        cout << pair.first << ": " << pair.second << endl;
    }
}


