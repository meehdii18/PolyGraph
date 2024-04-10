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


    // TEST PARSEUR
    vector<string> Delimiteurs = { "NBArcs","NBSommets","Numero","Debut","Fin" };
    map<string, vector<unsigned int>> data = CParseur::PRSParserFichier("./donnees.txt", Delimiteurs);

    for (const auto& pair : data) {
        cout << "Mot cle : " << pair.first << endl;
        cout << "Valeurs : ";
        for (const auto& value : pair.second) {
            cout << value << " ";
        }
        cout << endl;
    }
}


