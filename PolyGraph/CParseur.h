#pragma once
/******************************************************
* CLASSE : CParseur
*******************************************************
* ROLE : Interface de la classe CParseur contenant
* des fonctions de parsage
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphaël AVELINE
* DATE : 17/04/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

/* TYPES :
* Pas de type particulier déclaré
*/

/* VARIABLES:
*/

class CParseur {
public:
    // Constructeur et destructeur
    /******************************************************
	* CParseur (interdit)
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Il ne fait pas sens d'instancier un objet
	* de la classe CParseur étant donnée que toutes les 
	* méthodes sont statiques 
	******************************************************/
    CParseur() = delete;

	
	// Méthodes

	/******************************************************
	* PRSMinuscule
	*******************************************************
	* Entrée : sParam, chaîne de caractère à modifier
	* Nécessite : Rien
	* Sortie : string
	* Entraîne : La transformation de toute la chaîne de
	* caractère en minuscule
	******************************************************/
    static string PRSMinuscule(string sParam);

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
    static string PRSLireValeur(string sFichier,string sMotCle);

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
    static map<string,vector<string>> PRSLireValeurComplexe(const string& sFichier, const string& sMotCle, const vector<string>& vDelimiteurs);

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
    static string PRSLireValeurLigne(const string& sLigne, const string& sMotCle);
};