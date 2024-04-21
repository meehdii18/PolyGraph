#pragma once
/******************************************************
* CLASSE : CAffichage
*******************************************************
* ROLE : Interface de la classe CAffichage donnant
* des outils pour afficher les éléments de chaque classe
* du programme
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Raphaël AVELINE
* DATE : 02/04/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include "CGraphOrient.h"
using namespace std;

class CAffichage
{
private :
	// Aucun attribut dans cette classe car ça n'aurait pas de sens d'en ajouter

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* CAffichage (interdit)
	*******************************************************
	* Entrée : Rien
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : Il ne fait pas vraiment sens d'instancier
	* un objet de la classe CAffichage donc le 
	* constructeur est interdit
	******************************************************/
	CAffichage() = delete;


	// MÉTHODES

	/******************************************************
	* AFHAfficherSommet
	*******************************************************
	* Entrée : CSommet*, le sommet à afficher
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'affichage de l'identifiant du sommet 
	* en paramètre
	******************************************************/
	void static AFHAfficherListeSommets(const vector<string>& vsListe);

	/******************************************************
	* AFHAfficherSommetAvecArc
	*******************************************************
	* Entrée : CSommet*, le sommet à afficher
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'affichage de l'identifiant et des arcs
	* du sommet en paramètre
	******************************************************/
	void static AFHAfficherSommetAvecArc(const PGraphOrient<CArc, CSommet>& GPOParam, const string& sIdSommet);

	/******************************************************
	* AFHAfficherArc
	*******************************************************
	* Entrée : CArc*, l'arc à afficher
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'affichage des informations concernants
	* l'arc en paramètre
	******************************************************/
	void static AFHAfficherArc(const vector<vector<string>>& vvsListe);

	/******************************************************
	* AFHAfficherGraph
	*******************************************************
	* Entrée : PGraphOrient<CArc,CSommet>*, le graphe
	* orienté à afficher
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'affichage des informations concernants
	* le graphe orienté en paramètre
	******************************************************/
	void static AFHAfficherGraphe(const PGraphOrient<CArc,CSommet>& GPOParam);

	/******************************************************
	* AFHAfficherGraphe
	*******************************************************
	* Entrée : PGraph<?,CSommet>*, le graphe 
	* à afficher
	* Nécessite : Rien
	* Sortie : Rien
	* Entraîne : L'affichage des informations concernants
	* le graphe en paramètre
	******************************************************/
	// void static AFHAfficherGraphe(PGraph<?, CSommet>* ?Param); ? -> Classe héritée de CArc ayant la même origine et destination pas encore créer et trigramme pas encore trouvé pour CGraphe
};
