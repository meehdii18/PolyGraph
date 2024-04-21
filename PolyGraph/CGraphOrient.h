#pragma once
/******************************************************
* CLASSE : CGraphOrient pour repr�senter un graphe 
* orient�
*******************************************************
* ROLE : Interface de la classe CGraphOrient permettant
* de cr�er des graphes orient�s et d'effectuer des
* op�rations sur celui-ci
*******************************************************
* VERSION : 1.0
* AUTEUR : Mehdi AMELLADI et Rapha�l AVELINE
* DATE : 19/03/2024
*******************************************************
* INCLUSIONS EXTERNES :
*/
#include "CArc.h"
#include "CSommet.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
using namespace std;

/* TYPES :
* Pas de type particulier d�clar�
*/

/* VARIABLES:
*/
template<class TArc, class TSommet> class PGraphOrient
{
private:
	// ATTRIBUTS

	vector<TArc*> vGPOListeArcs;

	vector<TSommet*> vGPOListeSommets;

	// M�THODES PRIV�ES

	/******************************************************
	* GPOTrouverSommet
	*******************************************************
	* Entr�e : sIdentifiant l'identifiant du sommet cherch�
	* N�cessite : Rien
	* Sortie : Un pointeur vers le sommet si il est dans le
	* graphe, nullptr sinon
	* Entra�ne : Rien
	******************************************************/
	TSommet* GPOTrouverSommet(const string& sIdentifiant) const;

	/******************************************************
	* GPOTrouverArc
	*******************************************************
	* Entr�e : sOrigine et sDestination l'origine et la
	* destination de l'arc cherch�
	* N�cessite : Rien
	* Sortie : Un pointeur vers l'arc si il est dans le
	* graphe, nullptr sinon
	* Entra�ne : Rien
	******************************************************/
	TArc* GPOTrouverArc(const string& sOrigine, const string& sDestination) const;

public:
	// CONSTRUCTEURS ET DESTRUCTEURS

	/******************************************************
	* PGraphOrient
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Un graphe vide est cr��
	******************************************************/
	PGraphOrient() {}

	/******************************************************
	* PGraphOrient (Recopie)
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Un graphe copie de GPOParam est cr��
	******************************************************/
	PGraphOrient(const PGraphOrient &GPOParam);

	/******************************************************
	* ~PGraphOrient
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Le graphe est d�truit
	******************************************************/
	~PGraphOrient() {} // A MODIFIER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// M�THODES

	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entra�ne : Rien
	******************************************************/
	vector<vector<string>> GPOLireListeArcs() const;

	/******************************************************
	* GPOLireListeSommets
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les sommets du graphe
	* Entra�ne : Rien
	******************************************************/
	vector<string> GPOLireListeSommets() const;

	/******************************************************
	* GPOLirePredecesseursSommets
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les sommets depuis
	* lesquels des arcs du graphe viennent au sommet
	* d'identifiant sIDSommet.
	* Entra�ne : Rien
	******************************************************/
	vector<string> GPOLirePredecesseursSommet(const string& sIdSommet) const;

	/******************************************************
	* GPOLireSuccesseursSommets
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les sommets vers
	* lesquels des arcs du graphe vont depuis le sommet
	* d'identifiant sIDSommet.
	* Entra�ne : Rien
	******************************************************/
	vector<string> GPOLireSuccesseursSommet(const string& sIdSommet) const;

	/******************************************************
	* GPOAjouterSommet
	*******************************************************
	* Entr�e : sIdentifiant l'identifiant du sommet � cr�er
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La cr�ation d'un sommet d'identifiant 
	* sIdentifiant, puis l'ajout de ce sommet dans 
	* vGPOListeSommets.
	******************************************************/
	void GPOAjouterSommet(const string& sIdentifiant);

	/******************************************************
	* GPOSupprimerSommet
	*******************************************************
	* Entr�e : sIdentifiant l'identifiant du sommet � 
	* supprimer
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La suppression du sommet d'identifiant
	* sIdentifiant du graphe
	******************************************************/
	void GPOSupprimerSommet(const string& sIdentifiant);

	/******************************************************
	* GPOModifierIdentifiantSommet
	*******************************************************
	* Entr�e : sIdentifiant, string, identifiant � modifier
	* sNouvelIdenfiant, string, le nouvel identifiant du
	* sommet
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La modification de l'attribut identifiant
	* du sommet
	******************************************************/
	void GPOModifierIdentifiantSommet(const string& sIdentifiant, const string& sNouvelIdentifiant);

	/******************************************************
	* GPOAjouterArc
	*******************************************************
	* Entr�e : sOrigine et sDestination l'origine et la
	* destination de l'arc � cr�er
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La cr�ation d'un arc reliant les sommets
	* d'origine et de destination, si ceux-si existent et
	* si l'arc n'existe pas.
	******************************************************/
	void GPOAjouterArc(const string& sOrigine, const string& sDestination);

	/******************************************************
	* GPOSupprimerArc
	*******************************************************
	* Entr�e : sOrigine et sDestination l'origine et la
	* destination de l'arc c� supprimer
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : La suppression de l'arc reliant les
	* sommets d'origine et de destination
	******************************************************/
	void GPOSupprimerArc(const string& sOrigine, const string& sDestination);

	/******************************************************
	* GPOInverserArcs
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Rien
	* Entra�ne : Tous les arcs du graphe sont invers�s
	******************************************************/
	void GPOInverserArcs(); // A METTRE DANS UNE CLASSE D'OP�RATIONS SUR LES GRAPHES
};

#include "CGraphOrient.th"