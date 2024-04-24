#pragma once
/******************************************************
* CLASSE : CParseur
*******************************************************
* ROLE : Classe contenant des fonctions de parsage
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
* DATE : 17/04/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std ;

/* TYPES :
* Pas de type particulier declare
*/

/* VARIABLES:
*/

class CParseur
{
private:
	//ATTRIBUTS

	// Aucun attribut dans cette classe car ça n'aurait pas de sens d'en ajouter

public:
    // CONSTRUCTEURS ET DESTRUCTEURS

    /******************************************************
	* CParseur (delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Cela ne sert a rien d'instancier un objet
	* de la classe CParseur car toutes les methodes sont 
	* statiques 
	******************************************************/
    CParseur() = delete;

	
	// METHODES

	/******************************************************
	* PRSMinuscule
	*******************************************************
	* Entree : sParam la chaine de caractères a modifier
	* Necessite : Rien
	* Sortie : sParam transformee en minuscule
	* Entraine : Rien
	******************************************************/
    static string PRSMinuscule(string sParam);

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
    static string PRSLireValeur(string sFichier,string sMotCle);

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
    static map<string,vector<string>> PRSLireValeurComplexe(const string& sFichier, const string& sMotCle, const vector<string>& vDelimiteurs);

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
    static string PRSLireValeurLigne(const string& sLigne, const string& sMotCle);
};
