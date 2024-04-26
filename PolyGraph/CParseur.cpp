#include "CParseur.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

/******************************************************
* PRSMinuscule
*******************************************************
* Entree : sParam la chaine de caractères a modifier
* Necessite : Rien
* Sortie : sParam transformee en minuscule
* Entraine : Rien
******************************************************/
string CParseur::PRSMinuscule(const string& sParam)
{
    string sCopy = sParam;
    transform(sCopy.begin(), sCopy.end(), sCopy.begin(), tolower);
    return sCopy;
}

/******************************************************
* PRSLireValeur
*******************************************************
* Entree : sFichier le fichier a traiter,
* sMotCle la chaine de caractères a chercher
* Necessite : Rien
* Sortie : le string contenant la valeur associee au
* mot cle sMotCle
* Entraine : Rien
******************************************************/
string CParseur::PRSLireValeur(const string& sFichier, const string& sMotCle)
{
    ifstream strFichier(sFichier); 

    if (strFichier.is_open()) {
        string sLigne;
        while (getline(strFichier, sLigne)) {
            // Verifier si la ligne ne se trouve pas entre des crochet car on la traite dans l'autre version de LireValeur
            if (sLigne.find('[') == string::npos && sLigne.find(']') == string::npos) {
                size_t stPosEgal = sLigne.find('=');
                if (stPosEgal != string::npos) { // S'il y a bien un = dans la ligne et qu'il n'y a pas de crochet on traite la ligne
                    string sMotMinuscule = PRSMinuscule(sMotCle);
                    string sLigneMinuscule = PRSMinuscule(sLigne.substr(0, stPosEgal));
                    // Supprimer les espaces entre le = et le mot cle
                    sLigneMinuscule.erase(remove_if(sLigneMinuscule.begin(), sLigneMinuscule.end(), ::isspace), sLigneMinuscule.end());
                    if (sLigneMinuscule == sMotMinuscule) {
                        string sValeur = sLigne.substr(stPosEgal + 1);
                        // Retirer les espaces au debut de la chaine
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

    return ""; // Retourner une chaine vide si aucune valeur correspondante n'a ete trouvee
}

/******************************************************
* PRSLireValeurComplexe
*******************************************************
* Entree : sFichier le fichier a traiter,
* sMotCle la chaine de caractère a chercher,
* vDelimiteurs la liste de chaine de caractères 
* contenant les delimiteurs
* Necessite : Rien
* Sortie : Un vecteur contenant les valeurs associees 
* au mot cle si celui-ci est present
* Entraine : Rien
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
            // sur les ligne suivantes jusqu'a "]" on appel PRSLireValeur simple pour chaque delimiteurs et 
            // on ajoute dans vDonnees le resultat pour chaque delimiteurs sur chaque ligne
            if (sLigne.find(sMotCle + "=[") != string::npos) {
                while (!(sLigne == "]")) {
                    getline(strFichier, sLigne);
                    for (const string& sDelimiteurs : vDelimiteurs) {
                        // Creer une fonction PRSLireValeurLigne qui fait pareil que PRSLireValeur mais sur une seule ligne
                        // Cherche le mot cle suivi de =
                        // Stocke dans une variable tout ce qui suit le = ( sauf les premiers espaces ) jusqu'a rencontre soit une virgule ou fin de ligne et recommence
                        string sValeur = PRSLireValeurLigne(sLigne, sDelimiteurs);
                        if (!sValeur.empty()) {
                            vDonnees[sDelimiteurs].push_back(sValeur);
                        }
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
* Entree : sLigne la ligne a traiter,
* sMotCle la chaine de caractère a chercher
* Necessite : Rien
* Sortie : un string contenant la valeur associee au
* mot cle sMotCle si celui-ci est present
* Entraine : Rien
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
            size_t stDebutSansEspace = sLigne.find_first_not_of(" \t", stPosEgal + 1);
            size_t stFinSansEspace = sLigne.find_last_not_of(" \t,", stPosVirgule) + 1;
            return sLigne.substr(stDebutSansEspace, stFinSansEspace - stDebutSansEspace);
        }
    }
    return "";
}

