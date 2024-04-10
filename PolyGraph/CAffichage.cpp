#include "CAffichage.h"

/******************************************************
* AFHAfficherSommet
*******************************************************
* Entr�e : CSommet*, pointeur sur le sommet � afficher
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : L'affichage des informations concernants
* le sommet en param�tre
******************************************************/
void CAffichage::AFHAfficherSommet(const CSommet& SMTParam)
{
	string sId = SMTParam.SMTLireIdentifiant();
	cout << "ID Sommet : " << sId << endl;
}


/******************************************************
* AFHAfficherSommetAvecArc
*******************************************************
* Entr�e : CSommet*, pointeur sur le sommet � afficher
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : L'affichage des informations concernants
* le sommet en param�tre
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
* Entr�e : CArc*, pointeur sur l'arc � afficher
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : L'affichage des informations concernants
* l'arc en param�tre
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
* Entr�e : PGraphOrient<CArc,CSommet>*, pointeur sur
* le graphe orient� � afficher
* N�cessite : Rien
* Sortie : Rien
* Entra�ne : L'affichage des informations concernants
* le graphe orient� en param�tre
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
