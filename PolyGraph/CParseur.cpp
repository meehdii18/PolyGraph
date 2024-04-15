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
            // V�rifier si la ligne ne se trouve pas entre des crochet car on la traite dans l'autre version de LireValeur
            if (sLigne.find('[') == string::npos && sLigne.find(']') == string::npos) {
                size_t stPosEgal = sLigne.find('=');
                if (stPosEgal != string::npos) { // S'il y a bien un = dans la ligne et qu'il n'y a pas de crochet on traite la ligne
                    string sMotMinuscule = PRSMinuscule(sMotCle);
                    string sLigneMinuscule = PRSMinuscule(sLigne.substr(0, stPosEgal));
                    // Supprimer les espaces entre le = et le mot cl�
                    sLigneMinuscule.erase(remove_if(sLigneMinuscule.begin(), sLigneMinuscule.end(), ::isspace), sLigneMinuscule.end());
                    if (sLigneMinuscule == sMotMinuscule) {
                        string sValeur = sLigne.substr(stPosEgal + 1);
                        // Retirer les espaces au d�but de la cha�ne
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

    return ""; // Retourner une cha�ne vide si aucune valeur correspondante n'a �t� trouv�e
}


vector<vector<string>> CParseur::PRSLireValeurComplexe(const string &sFichier, const string &sMotCle, const vector<string> &vDelimiteurs)
{   
    vector<vector<string>> vDonnees;
    ifstream strFichier(sFichier);

    if (strFichier.is_open()) {
        string sLigne;
        while (getline(strFichier, sLigne)) {
            // On parcours chaque ligne
            // On cherche "sMotCle=["
            // sur les ligne suivantes jusqu'� "]" on appel PRSLireValeur simple pour chaque d�limiteurs et 
            // on ajoute dans vDonnees le r�sultat pour chaque d�limiteurs sur chaque ligne
            if (sLigne.find(sMotCle + "=[") != string::npos) {
                while (!(sLigne == "]")) {
                    getline(strFichier, sLigne);
                    for (const string& sDelimiteurs : vDelimiteurs) {
                        // Cr�er une fonction PRSLireValeurLigne qui fait pareil que PRSLireValeur mais sur une seule ligne
                        // Cherche le mot cl� suivi de =
                        // Stocke dans une variable tout ce qui suit le = ( sauf les premiers espaces ) jusqu'� rencontr� soit une virgule ou fin de ligne
                    }
                }
            }
        }
        strFichier.close();
    }
    else {
        throw runtime_error("Impossible d'ouvrir le fichier");
    }

    return vDonnees;
}
