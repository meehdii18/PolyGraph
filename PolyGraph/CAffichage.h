#pragma once
/******************************************************
* CLASSE : CAffichage
*******************************************************
* ROLE : Classe donnant des outils pour afficher des 
* graphes et leurs elements
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphael AVELINE
* DATE : 02/04/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include "CGraphOrient.h"

using namespace std;

/* TYPES :
* Pas de type particulier declare
*/

/* VARIABLES:
*/

class CAffichage
{
private :
	//ATTRIBUTS

	// Aucun attribut dans cette classe car ça n'aurait pas de sens d'en ajouter

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* CAffichage (delete)
	*******************************************************
	* Entree : Rien
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : Il ne fait pas vraiment sens d'instancier
	* un objet de la classe CAffichage donc le 
	* constructeur est interdit
	******************************************************/
	CAffichage() = delete;


	// METHODES

	/******************************************************
	* AFHAfficherListeSommet
	*******************************************************
	* Entree : vsListe, la liste des identifiants des
	* sommets a afficher
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'affichage des identifiants des sommets
	* du graphe
	******************************************************/
	void static AFHAfficherListeSommets(const vector<string>& vsListe);

	/******************************************************
	* AFHAfficherSommetAvecArc
	*******************************************************
	* Entree : GPOParam le graphe auquel le sommet a 
	* afficher appartient, et sIdSommet l'identifiant de ce
	* sommet
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'affichage de l'identifiant et des arcs
	* du sommet
	******************************************************/
	void static AFHAfficherSommetAvecArc(const PGraphOrient<CArc, CSommet>& GPOParam, const string& sIdSommet);

	/******************************************************
	* AFHAfficherArcs
	*******************************************************
	* Entree : vvsListe, la liste des origines et 
	* destinations des arcs du graphe
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'affichage des informations des arcs du
	* graphe
	******************************************************/
	void static AFHAfficherArcs(const vector<vector<string>>& vvsListe);

	/******************************************************
	* AFHAfficherGraphe
	*******************************************************
	* Entree : GPOParam, le graphe a afficher
	* Necessite : Rien
	* Sortie : Rien
	* Entraine : L'affichage des informations concernants
	* le graphe passe en paramètre
	******************************************************/
	void static AFHAfficherGraphe(const PGraphOrient<CArc,CSommet>& GPOParam);
};
