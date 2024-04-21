#pragma once
/******************************************************
* CLASSE : CCreateurGraph (nom à potentiellement modifier)
*******************************************************
* ROLE : Interface de la classe CCreateurGraphe ayant 
* comme rôle la création de graph à partir d'informations
* récupérées via une entrée utilisateur
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphaël AVELINE
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
	
	// Méthodes

	/******************************************************
	* CCGCreerGraphOrientFichier
	*******************************************************
	* Entrée : string, le fichier à traiter pour créer 
	* le graphe
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La lecture du fichier en paramètre et s'il
	* est conforme, la création du graphe orienté associé
	******************************************************/
	void CCGCreerGraphOrientFichier(string& sFichier);

	/******************************************************
	* CCGCreerGraphFichier
	*******************************************************
	* Entrée : string, le fichier à traiter pour créer
	* le graphe
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : La lecture du fichier en paramètre et s'il
	* est conforme, la création du graphe associé
	******************************************************/
	void CCGCreerGraphFichier(string& sFichier);
};

