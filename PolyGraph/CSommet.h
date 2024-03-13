#pragma once
/******************************************************
* CLASSE : CSommet
*******************************************************
* ROLE : Interface de la classe CSommet repr�sentant
* les sommets d'un graphe
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
* DATE : 13/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include <iostream>
#include <string>
using namespace std;

/* TYPES :
* Pas de type particulier d�clar�
*/

/* VARIABLES:
*/
class CSommet
{
private:
	// ATTRIBUTS
	string sSMTIdentifiant;


public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* CSommet
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le sommet est initialis�
	******************************************************/
	CSommet();


	/******************************************************
	* CSommet
	*******************************************************
	* Entr�e : sParam string, l'identifiant avec lequel est
	* initialis� le sommet
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le sommet est initialis� avec 
	* l'identifiant en param�tre
	******************************************************/
	CSommet(string sParam);

	/******************************************************
	* ~CSommet
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le sommet est d�truit ainsi que les 
	* potentiels arcs qui lui sont associ�s
	******************************************************/
	~CSommet();



	// M�THODES

	/******************************************************
	* SMTLireIdentifiant
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : L'identifiant du sommet, string
	* Entra�ne : La lecture de l'attribut identifiant du 
	* sommet
	******************************************************/
	string SMTLireIdentifiant() const { return sSMTIdentifiant; };

	/******************************************************
	* SMTModifierIdentifiant
	*******************************************************
	* Entr�e : sIdentifiant, string
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La modification de l'attribut identifiant
	* du sommet
	******************************************************/
	inline void SMTModifierIdentifiant(string sIdentifiant) { sSMTIdentifiant = sIdentifiant; };

	


};
