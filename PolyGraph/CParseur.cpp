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

string CParseur::PRSLireValeur(string sFichier, string sMotCle)
{
    ifstream strFichier(sFichier); 

    if (strFichier.is_open()) {
        string sLigne;
        while (getline(strFichier, sLigne)) {
            // Vérifier si la ligne ne se trouve pas entre des crochet car on la traite dans l'autre version de LireValeur
            if (sLigne.find('[') == string::npos && sLigne.find(']') == string::npos) {
                size_t stPosEgal = sLigne.find('=');
                if (stPosEgal != string::npos) { // S'il y a bien un = dans la ligne et qu'il n'y a pas de crochet on traite la ligne
                    string sMotMinuscule = PRSMinuscule(sMotCle);
                    string sLigneMinuscule = PRSMinuscule(sLigne.substr(0, stPosEgal));
                    // Supprimer les espaces entre le = et le mot clé
                    sLigneMinuscule.erase(remove_if(sLigneMinuscule.begin(), sLigneMinuscule.end(), ::isspace), sLigneMinuscule.end());
                    if (sLigneMinuscule == sMotMinuscule) {
                        string sValeur = sLigne.substr(stPosEgal + 1);
                        // Retirer les espaces au début de la chaîne
                        sValeur.erase(0, sValeur.find_first_not_of(" \t"));
                        return sValeur;
                    }
                }
            }
        }
        strFichier.close();
    }
    else {
        throw runtime_error("Impossible d'ouvrir le fichier");
    }

    return ""; // Retourner une chaîne vide si aucune valeur correspondante n'a été trouvée
}


vector<vector<string>> CParseur::PRSLireValeurComplexe(string sFichier, string sMotCle, vector<string> vDelimiteurs)
{   
    vector<vector<string>> vDonnees;
    ifstream strFichier(sFichier);

    if (strFichier.is_open()) {
        string sLigne;
        while (getline(strFichier, sLigne)) {
            // On parcours chaque ligne
            // On cherche "sMotCle=["
            // sur les ligne suivantes jusqu'à "]" on appel PRSLireValeur simple pour chaque délimiteurs et 
            // on ajoute dans vDonnees le résultat pour chaque délimiteurs sur chaque ligne
            if (sLigne.find(sMotCle + "=[") != string::npos) {
                continue;
            }
        }
        strFichier.close();
    }
    else {
        throw runtime_error("Impossible d'ouvrir le fichier");
    }

    return vDonnees;
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


