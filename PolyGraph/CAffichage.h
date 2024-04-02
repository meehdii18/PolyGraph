#pragma once
/******************************************************
* CLASSE : CAffichage
*******************************************************
* ROLE : Interface de la classe CAffichage donnant
* des outils pour afficher les �l�ments de chaque classe
* du programme
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
* DATE : 02/04/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/

#include "CGraphOrient.h"
using namespace std;

class CAffichage
{
private :
	// Aucun attribut dans cette classe car �a n'aurait pas de sens d'en ajouter

public:
	// CONSTRUCTEURS ET DESTRUCTEUR

	/******************************************************
	* CAffichage (interdit)
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Il ne fait pas vraiment sens d'instancier
	* un objet de la classe CAffichage donc le 
	* constructeur est interdit
	******************************************************/
	CAffichage() = delete;


	// M�THODES

	/******************************************************
	* AFHAfficherSommet
	*******************************************************
	* Entr�e : CSommet*, le sommet � afficher
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'affichage des informations concernants
	* le sommet en param�tre
	******************************************************/
	void static AFHAfficherSommet(const CSommet& SMTParam);

	/******************************************************
	* AFHAfficherSommetAvecArc
	*******************************************************
	* Entr�e : CSommet*, le sommet � afficher
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'affichage des informations concernants
	* le sommet en param�tre
	******************************************************/
	void static AFHAfficherSommetAvecArc(const CSommet& SMTParam);

	/******************************************************
	* AFHAfficherArc
	*******************************************************
	* Entr�e : CArc*, l'arc � afficher
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'affichage des informations concernants
	* l'arc en param�tre
	******************************************************/
	void static AFHAfficherArc(const CArc& ARCParam);

	/******************************************************
	* AFHAfficherGrapheOrient
	*******************************************************
	* Entr�e : PGraphOrient<CArc,CSommet>*, le graphe
	* orient� � afficher
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'affichage des informations concernants
	* le graphe orient� en param�tre
	******************************************************/
	void static AFHAfficherGrapheOrient(const PGraphOrient<CArc,CSommet>& GPOParam);

	/******************************************************
	* AFHAfficherGraphe
	*******************************************************
	* Entr�e : PGraphOrient<?,CSommet>*, le graphe 
	* � afficher
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : L'affichage des informations concernants
	* le graphe en param�tre
	******************************************************/
	// void static AFHAfficherGraphe(PGraphOrient<?, CSommet>* ?Param); ? -> Classe h�rit�e de CArc ayant la m�me origine et destination pas encore cr�er et trigramme pas encore trouv� pour CGraphe
};
