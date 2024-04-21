#pragma once
/******************************************************
* CLASSE : CCreateurGraph (nom � potentiellement modifier)
*******************************************************
* ROLE : Interface de la classe CCreateurGraphe ayant 
* comme r�le la cr�ation de graph � partir d'informations
* r�cup�r�es via une entr�e utilisateur
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
* DATE : 18/04/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include "CParseur.h"
#include "CGraph.h"
using namespace std;

class CCreateurGraph
{
private : 

public :
	// Constructeurs et destructeurs

	CCreateurGraph() = default;
	
	// M�thodes

	/******************************************************
	* CCGCreerGraphOrientFichier
	*******************************************************
	* Entr�e : string, le fichier � traiter pour cr�er 
	* le graphe
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La lecture du fichier en param�tre et s'il
	* est conforme, la cr�ation du graphe orient� associ�
	******************************************************/
	void CCGCreerGraphOrientFichier(string& sFichier);

	/******************************************************
	* CCGCreerGraphFichier
	*******************************************************
	* Entr�e : string, le fichier � traiter pour cr�er
	* le graphe
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La lecture du fichier en param�tre et s'il
	* est conforme, la cr�ation du graphe associ�
	******************************************************/
	void CCGCreerGraphFichier(string& sFichier);
};

