#include "CParseur.h"
#include <iostream>
#include <stdexcept>
using namespace std;

map<string, unsigned int> CParseur::PRSParserFichier(string sFichier,vector<string> vMotsCles)
{
    map<string, unsigned int> mDonnees;
    for (const string& sMot : vMotsCles) {
        mDonnees[sMot] = 0;
    }
    ifstream strFichier("donnees.txt");
    if (strFichier.is_open()) {
        string sLigne;
        while (getline(strFichier, sLigne)) {
            for (const string& sMot : vMotsCles) {
                if (sLigne.find(("NB") + sMot)) {
                    //cout << "AAAAAAAAAAAAAA" << endl;
                }
            }
        }
        strFichier.close();
        return mDonnees;
    }
    else {
        throw runtime_error("Impossible d'ouvrir le fichier");
    }
}
