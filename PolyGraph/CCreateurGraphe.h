#pragma once
/******************************************************
* CLASSE : CCreateurGraph (nom a potentiellement modifier)
*******************************************************
* ROLE : Interface de la classe CCreateurGraphe ayant
* comme role la creation de graph a partir d'informations
* recuperees via une entree utilisateur
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
* DATE : 18/04/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include "CParseur.h"
#include "PGraph.h"
#include "PGraphOrientPondere.h"
using namespace std;

class CCreateurGraph
{
private:

public:
	// Constructeurs et destructeurs

	/******************************************************
	* CCreateurGraph (defaut) // Je pense que ce sera delete et que y'aura que des méthodes statiques comme le parseur
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Cela ne sert a rien d'instancier un objet
	* de la classe CParseur car toutes les methodes sont
	* statiques
	******************************************************/
	CCreateurGraph() = default;

	// METHODES

	/******************************************************
	* CCGImporterGrapheFichier
	*******************************************************
	* Entree : GPOParam le graphe dans lequel importer des
	* donnees avec des arcs non ponderes;
	* sFichier le chemin d'acces du fichier ou sont
	* contenues les donnees a ajouter
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La lecture du fichier en parametre et s'il
	* est conforme, la modification du graphe associe
	******************************************************/
	void static CCGImporterGrapheFichier(PGraphOrient<CArc, CSommet>& GPOParam, const string& sFichier);

	/******************************************************
	* CCGImporterGrapheFichier
	*******************************************************
	* Entree : GPOParam le graphe dans lequel importer des
	* donnees avec des arcs ponderes;
	* sFichier le chemin d'acces du fichier ou sont
	* contenues les donnees a ajouter
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La lecture du fichier en parametre et s'il
	* est conforme, la modification du graphe associe
	******************************************************/
	void static CCGImporterGrapheFichier(PGraphOrientPondere<CArcPondere, CSommet>& GPOParam, const string& sFichier);

	/******************************************************
	* CCGCreerGrapheOrientFichier
	*******************************************************
	* Entree : sFichier le chemin d'acces du fichier ou
	* sont contenues les donnees a ajouter au graphe cree
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La lecture du fichier en parametre et s'il
	* est conforme, la creation du graphe associe
	******************************************************/
	PGraphOrient<CArc, CSommet> static CCGCreerGrapheOrientFichier(const string& sFichier);

	/******************************************************
	* CCGCreerGrapheFichier
	*******************************************************
	* Entree : sFichier le chemin d'acces du fichier ou
	* sont contenues les donnees a ajouter au graphe cree
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La lecture du fichier en parametre et s'il
	* est conforme, la creation du graphe associe
	******************************************************/
	PGraph<CArc, CSommet> static CCGCreerGrapheFichier(const string& sFichier);

	/******************************************************
	* CCGCreerGrapheOrientPondereFichier
	*******************************************************
	* Entree : sFichier le chemin d'acces du fichier ou
	* sont contenues les donnees a ajouter au graphe cree
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : La lecture du fichier en parametre et s'il
	* est conforme, la creation du graphe associe
	******************************************************/
	PGraphOrientPondere<CArcPondere, CSommet> static CCGCreerGrapheOrientPondereFichier(const string& sFichier);
};