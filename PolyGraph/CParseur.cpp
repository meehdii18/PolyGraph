#include "CParseur.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;

/******************************************************
* PRSMinuscule
*******************************************************
* Entr�e : sParam, cha�ne de caract�re � modifier
* N�cessite : Rien
* Sortie : string 
* Entra�ne : La transformation de toute la cha�ne de 
* caract�re en minuscule
******************************************************/
string CParseur::PRSMinuscule(string sParam)
{
    transform(sParam.begin(), sParam.end(), sParam.begin(), tolower);
    return sParam;
}

/******************************************************
* PRSLireValeur
*******************************************************
* Entr�e : sFichier, fichier � traiter, 
* sMotCle, ch�ine de caract�re � chercher
* N�cessite : Rien
* Sortie : string
* Entra�ne : V�rification de la pr�sence du mot cl�
* sous la forme souhait�e dans le fichier et renvoie
* la valeur associ�e
******************************************************/
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

/******************************************************
* PRSLireValeurComplexe
*******************************************************
* Entr�e : sFichier, fichier � traiter,
* sMotCle, ch�ine de caract�re � chercher
* vDelimiteurs, liste de ch�ine de caract�re contenant
* les d�limiteurs
* N�cessite : Rien
* Sortie : map<string, vector<string>>
* Entra�ne : V�rification de la pr�sence du mot cl�
* sous la forme souhait�e dans le fichier et renvoie
* les valeurs associ�es
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
            // sur les ligne suivantes jusqu'� "]" on appel PRSLireValeur simple pour chaque d�limiteurs et 
            // on ajoute dans vDonnees le r�sultat pour chaque d�limiteurs sur chaque ligne
            if (sLigne.find(sMotCle + "=[") != string::npos) {
                while (!(sLigne == "]")) {
                    getline(strFichier, sLigne);
                    for (const string& sDelimiteurs : vDelimiteurs) {
                        // Cr�er une fonction PRSLireValeurLigne qui fait pareil que PRSLireValeur mais sur une seule ligne
                        // Cherche le mot cl� suivi de =
                        // Stocke dans une variable tout ce qui suit le = ( sauf les premiers espaces ) jusqu'� rencontr� soit une virgule ou fin de ligne et recommence
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
* Entr�e : sLigne, ligne � traiter,
* sMotCle, ch�ine de caract�re � chercher
* N�cessite : Rien
* Sortie : string
* Entra�ne : V�rification de la pr�sence du mot cl�
* sous la forme souhait�e sur la ligne uniquement et
* renvoie la valeur associ�e
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

