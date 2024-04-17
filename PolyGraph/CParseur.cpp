#include "CParseur.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

/******************************************************
* PRSMinuscule
*******************************************************
* Entrée : sParam, chaîne de caractère à modifier
* Nécessite : Rien
* Sortie : string 
* Entraîne : La transformation de toute la chaîne de 
* caractère en minuscule
******************************************************/
string CParseur::PRSMinuscule(string sParam)
{
    transform(sParam.begin(), sParam.end(), sParam.begin(), tolower);
    return sParam;
}

/******************************************************
* PRSLireValeur
*******************************************************
* Entrée : sFichier, fichier à traiter, 
* sMotCle, châine de caractère à chercher
* Nécessite : Rien
* Sortie : string
* Entraîne : Vérification de la présence du mot clé
* sous la forme souhaitée dans le fichier et renvoie
* la valeur associée
******************************************************/
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

/******************************************************
* PRSLireValeurComplexe
*******************************************************
* Entrée : sFichier, fichier à traiter,
* sMotCle, châine de caractère à chercher
* vDelimiteurs, liste de châine de caractère contenant
* les délimiteurs
* Nécessite : Rien
* Sortie : map<string, vector<string>>
* Entraîne : Vérification de la présence du mot clé
* sous la forme souhaitée dans le fichier et renvoie
* les valeurs associées
******************************************************/
map<string, vector<string>> CParseur::PRSLireValeurComplexe(const string &sFichier, const string &sMotCle, const vector<string> &vDelimiteurs)
{   
    map<string, vector<string>> vDonnees;
    ifstream strFichier(sFichier);

    if (strFichier.is_open()) {
        string sLigne;
        while (getline(strFichier, sLigne)) {
            // On parcours chaque ligne
            // On cherche "sMotCle=["
            // sur les ligne suivantes jusqu'à "]" on appel PRSLireValeur simple pour chaque délimiteurs et 
            // on ajoute dans vDonnees le résultat pour chaque délimiteurs sur chaque ligne
            if (sLigne.find(sMotCle + "=[") != string::npos) {
                while (!(sLigne == "]")) {
                    getline(strFichier, sLigne);
                    for (const string& sDelimiteurs : vDelimiteurs) {
                        // Créer une fonction PRSLireValeurLigne qui fait pareil que PRSLireValeur mais sur une seule ligne
                        // Cherche le mot clé suivi de =
                        // Stocke dans une variable tout ce qui suit le = ( sauf les premiers espaces ) jusqu'à rencontré soit une virgule ou fin de ligne et recommence
                        vDonnees[sDelimiteurs].push_back(PRSLireValeurLigne(sLigne,sDelimiteurs));
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

/******************************************************
* PRSLireValeurLigne
*******************************************************
* Entrée : sLigne, ligne à traiter,
* sMotCle, châine de caractère à chercher
* Nécessite : Rien
* Sortie : string
* Entraîne : Vérification de la présence du mot clé
* sous la forme souhaitée sur la ligne uniquement et
* renvoie la valeur associée
******************************************************/
string CParseur::PRSLireValeurLigne(const string& sLigne, const string& sMotCle)
{
    string sLigneMinuscule = PRSMinuscule(sLigne);
    string sMotCleMinuscule = PRSMinuscule(sMotCle);
    size_t stPosMotCle = sLigneMinuscule.find(sMotCleMinuscule);
    if (stPosMotCle != string::npos) {
        size_t stPosEgal = sLigneMinuscule.find('=', stPosMotCle);
        if (stPosEgal != string::npos) {
            size_t stPosVirgule = sLigneMinuscule.find(',', stPosEgal);
            if (stPosVirgule != string::npos) {
                size_t stPosNonEspace = sLigne.find_first_not_of(" \t", stPosEgal + 1);
                return sLigne.substr(stPosNonEspace, stPosVirgule - stPosNonEspace);
            }
            else{
                size_t stPosNonEspace = sLigne.find_first_not_of(" \t", stPosEgal + 1);
                return sLigne.substr(stPosNonEspace);
            }
        }
    }
    return "";
}

