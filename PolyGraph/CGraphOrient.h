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
	~PGraphOrient() {}

	// M�THODES

	/******************************************************
	* GPOLireListeArcs
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les arcs du graphe
	* Entra�ne : Rien
	******************************************************/
	const vector<TArc*>& GPOLireListeArcs() const { return vGPOListeArcs; }

	/******************************************************
	* GPOLireListeSommets
	*******************************************************
	* Entr�e : Rien
	* N�cessite : Rien
	* Sortie : Le vecteur contenant les sommets du graphe
	* Entra�ne : Rien
	******************************************************/
	const vector<TSommet*>& GPOLireListeSommets() const { return vGPOListeSommets; }

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
	* GPOTrouverSommet
	*******************************************************
	* Entr�e : sIdentifiant l'identifiant du sommet cherch�
	* N�cessite : Rien
	* Sortie : Un pointeur vers le sommet si il est dans le
	* graphe, nullptr sinon
	* Entra�ne : Rien
	******************************************************/
	TSommet* GPOTrouverSommet(const string& sIdentifiant);

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
	* GPOTrouverArc
	*******************************************************
	* Entr�e : sOrigine et sDestination l'origine et la
	* destination de l'arc cherch�
	* N�cessite : Rien
	* Sortie : Un pointeur vers le'arc si il est dans le
	* graphe, nullptr sinon
	* Entra�ne : Rien
	******************************************************/
	TArc* GPOTrouverArc(const string& sOrigine, const string& sDestination);
};

#include "CGraphOrient.th"