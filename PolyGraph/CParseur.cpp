#include "CParseur.h"
#include <iostream>
#include <stdexcept>
using namespace std;


string CParseur::PRSMinuscule(string sParam)
{
    for (char& cLettre : sParam) {
        cLettre = tolower(cLettre);
    }
    return sParam;
}

map<string, vector<unsigned int>> CParseur::PRSParserFichier(string sFichier, vector<string> vMotsCles)
{
    map<string, vector<unsigned int>> mDonnees;
    ifstream strFichier(sFichier);
    if (strFichier.is_open()) {
        string sLigne;
        while (getline(strFichier, sLigne)) {
            for (const string& sMot : vMotsCles) {
                size_t stPosEgal = sLigne.find('=');
                size_t stPosVirgule = sLigne.find(',');

                // Si on trouve une virgule ça veut dire qu'il y a deux affectations sur cette ligne
                if (stPosVirgule != string::npos) {
                    string sPartie1 = sLigne.substr(0, stPosVirgule);
                    string sPartie2 = sLigne.substr(stPosVirgule + 1);

                    // Recherche du premier mot-clé dans la première partie de la ligne
                    size_t stPosEgalPartie1 = sPartie1.find('=');
                    if (stPosEgalPartie1 != string::npos) {
                        string sMotMinuscule = PRSMinuscule(sMot);
                        string sLigneMinuscule = PRSMinuscule(sPartie1.substr(0, stPosEgalPartie1));
                        if (sLigneMinuscule == sMotMinuscule) {
                            string sValeur = sPartie1.substr(stPosEgalPartie1 + 1);
                            mDonnees[sMot].push_back(stoi(sValeur));
                        }
                    }

                    // Recherche du deuxième mot-clé dans la deuxième partie de la ligne
                    size_t stPosEgalPartie2 = sPartie2.find('=');
                    if (stPosEgalPartie2 != string::npos) {
                        string sMotMinuscule = PRSMinuscule(sMot);
                        string sMot2 = sPartie2.substr(0, stPosEgalPartie2); // Obtention du deuxième mot-clé
                        size_t stPosPremierCharPasEspace = sMot2.find_first_not_of(" \t");
                        if (stPosPremierCharPasEspace != string::npos) {
                            sMot2 = sMot2.substr(stPosPremierCharPasEspace);
                        }
                        string sMot2Minuscule = PRSMinuscule(sMot2);
                        cout << sMot2Minuscule << sMotMinuscule << endl;
                        if (sMot2Minuscule == sMotMinuscule) {
                            string sValeur = sPartie2.substr(stPosEgalPartie2 + 1);
                            mDonnees[sMot].push_back(stoi(sValeur));
                        }
                    }
                }
                else {
                    if (stPosEgal != string::npos) {
                        string sMotMinuscule = PRSMinuscule(sMot);
                        string sLigneMinuscule = PRSMinuscule(sLigne.substr(0, stPosEgal));
                        if (sLigneMinuscule == sMotMinuscule) {
                            string sValeur = sLigne.substr(stPosEgal + 1);
                            mDonnees[sMot].push_back(stoi(sValeur));
                        }
                    }
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


