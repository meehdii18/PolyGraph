#include "CAffichage.h"

/******************************************************
* AFHAfficherSommet
*******************************************************
* Entrée : CSommet*, pointeur sur le sommet à afficher
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'affichage des informations concernants
* le sommet en paramètre
******************************************************/
void CAffichage::AFHAfficherSommet(const CSommet& SMTParam)
{
	string sId = SMTParam.SMTLireIdentifiant();
	cout << "ID Sommet : " << sId << endl;
}


/******************************************************
* AFHAfficherSommetAvecArc
*******************************************************
* Entrée : CSommet*, pointeur sur le sommet à afficher
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'affichage des informations concernants
* le sommet en paramètre
******************************************************/
void CAffichage::AFHAfficherSommetAvecArc(const CSommet& SMTParam)
{
	cout << "---------------------" << endl;
	vector<CArc*> vArcsEntrants = SMTParam.SMTLireArcsEntrants();
	vector<CArc*> vArcsSortants = SMTParam.SMTLireArcsSortants();
	AFHAfficherSommet(SMTParam);
	unsigned int uiBoucle;

	cout << "/// Arcs entrants :" << endl;
	for (uiBoucle = 0; uiBoucle < vArcsEntrants.size(); uiBoucle++)
	{
		AFHAfficherArc(*vArcsEntrants[uiBoucle]);
	}

	cout << "//// Arcs sortants :" << endl;
	for (uiBoucle = 0; uiBoucle < vArcsSortants.size(); uiBoucle++)
	{
		AFHAfficherArc(*vArcsSortants[uiBoucle]);
	}
	cout << "---------------------" << endl;
}


/******************************************************
* AFHAfficherArc
*******************************************************
* Entrée : CArc*, pointeur sur l'arc à afficher
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'affichage des informations concernants
* l'arc en paramètre
******************************************************/
void CAffichage::AFHAfficherArc(const CArc& ARCParam)
{
	string sOrigine = ARCParam.ARCLireOrigine();
	string sDestination = ARCParam.ARCLireDestination();
	cout << sOrigine << " -> " << sDestination << endl;
}


/******************************************************
* AFHAfficherGrapheOrient
*******************************************************
* Entrée : PGraphOrient<CArc,CSommet>*, pointeur sur
* le graphe orienté à afficher
* Nécessite : Rien
* Sortie : Rien
* Entraîne : L'affichage des informations concernants
* le graphe orienté en paramètre
******************************************************/
void CAffichage::AFHAfficherGraphe(const PGraphOrient<CArc, CSommet>& GPOParam)
{
	vector<CSommet*> vListeSommet = GPOParam.GPOLireListeSommets();
	vector<CArc*> vListeArc = GPOParam.GPOLireListeArcs();
	unsigned int uiBoucle;
	cout << "------------------------------------------" << endl;
	cout << "Graphe Oriente : \n" << "////////////// Sommets :" << endl;
	for (uiBoucle = 0; uiBoucle < vListeSommet.size(); uiBoucle++)
	{
		AFHAfficherSommet(*vListeSommet[uiBoucle]);
	}

	cout << "////////////// Arcs :" << endl;
	for (uiBoucle = 0; uiBoucle < vListeArc.size(); uiBoucle++)
	{
		AFHAfficherArc(*vListeArc[uiBoucle]);
	}
	cout << "------------------------------------------" << endl;
}
