#pragma once
/******************************************************
* CLASSE : CParseur
*******************************************************
* ROLE : Interface de la classe CParseur contenant
* des fonctions de parsage
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
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
* Pas de type particulier d�clar�
*/

/* VARIABLES:
*/

class CParseur {
public:
    // Constructeur et destructeur
    /******************************************************
	* CParseur (interdit)
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Il ne fait pas sens d'instancier un objet
	* de la classe CParseur �tant donn�e que toutes les 
	* m�thodes sont statiques 
	******************************************************/
    CParseur() = delete;

	
	// M�thodes

	/******************************************************
	* PRSMinuscule
	*******************************************************
	* Entr�e : sParam, cha�ne de caract�re � modifier
	* N�cessite : Rien
	* Sortie : string
	* Entra�ne : La transformation de toute la cha�ne de
	* caract�re en minuscule
	******************************************************/
    static string PRSMinuscule(string sParam);

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
    static string PRSLireValeur(string sFichier,string sMotCle);

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
    static map<string,vector<string>> PRSLireValeurComplexe(const string& sFichier, const string& sMotCle, const vector<string>& vDelimiteurs);

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
    static string PRSLireValeurLigne(const string& sLigne, const string& sMotCle);
};