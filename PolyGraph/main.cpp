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

void testParseur()
{
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

int main()
{
    //testCGraphOrient();

    //cout << "------------------------------------------FIN TEST CGraphOrient------------------------------------------" << endl;


    string fichier = "./donnees.txt";
    // TEST LIRE VALEUR
    cout << CParseur::PRSLireValeur(fichier, "nbarcs") << endl;

    // TEST LIRE VALEUR COMPLEXE
    string motCle = "Sommets";
    vector<string> delimiteurs = { "Numero" };
    
    try {
        vector<vector<string>> valeursComplexes = CParseur::PRSLireValeurComplexe(fichier, motCle, delimiteurs);
        for (const auto& valeurs : valeursComplexes) {
            cout << "Valeurs complexes : ";
            for (const auto& valeur : valeurs) {
                cout << valeur << " ";
            }
            cout << endl;
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Erreur lors de la lecture du fichier : " << e.what() << std::endl;
    }
    
    
    // TEST PARSEUR
    //testParseur();
}


