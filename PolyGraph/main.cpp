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
    //testCGraphOrient();

    //cout << "------------------------------------------FIN TEST CGraphOrient------------------------------------------" << endl;


    string fichier = "./donnees.txt";
    // TEST LIRE VALEUR
    // cout << CParseur::PRSLireValeur(fichier, "nbarcs") << endl;

    
    // TEST LIRE VALEUR COMPLEXE
    string motCle = "Arcs";
    vector<string> delimiteurs = { "Debut","Fin"};
    vector<vector<string>> valeursComplexes = CParseur::PRSLireValeurComplexe(fichier, motCle, delimiteurs);
    for (const auto& valeurs : valeursComplexes) {
        cout << "Valeurs complexes : ";
        for (const auto& valeur : valeurs) {
            cout << valeur << " ";
        }
        cout << endl;
    }
}


