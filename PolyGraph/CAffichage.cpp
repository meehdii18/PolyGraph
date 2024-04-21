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
void CAffichage::AFHAfficherListeSommets(const vector<string>& vsListe)
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < vsListe.size(); uiBoucle++)
	{
		cout << "ID Sommet : " << vsListe[uiBoucle] << endl;
	}
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
void CAffichage::AFHAfficherSommetAvecArc(const PGraphOrient<CArc, CSommet>& GPOParam, const string& sIdSommet)
{
	cout << "---------------------" << endl;
	vector<string> vsArcsEntrants = GPOParam.GPOLirePredecesseursSommet(sIdSommet);
	vector<string> vsArcsSortants = GPOParam.GPOLireSuccesseursSommet(sIdSommet);
	
	cout << "ID Sommet : " << sIdSommet << endl;

	unsigned int uiBoucle;

	cout << "/// Arcs entrants :" << endl;

	for (uiBoucle = 0; uiBoucle < vsArcsEntrants.size(); uiBoucle++)
	{
		cout << " - " << vsArcsEntrants[uiBoucle] << endl;
	}

	cout << "//// Arcs sortants :" << endl;

	for (uiBoucle = 0; uiBoucle < vsArcsSortants.size(); uiBoucle++)
	{
		cout << " - " << vsArcsSortants[uiBoucle] << endl;
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
void CAffichage::AFHAfficherArc(const vector<vector<string>>& vvsListe)
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < vvsListe.size(); uiBoucle++)
	{
		string sOrigine = vvsListe[uiBoucle][0];
		string sDestination = vvsListe[uiBoucle][1];
		cout << sOrigine << " -> " << sDestination << endl;
	}
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
	vector<string> vsListeSommet = GPOParam.GPOLireListeSommets();
	vector<vector<string>> vvsListeArc = GPOParam.GPOLireListeArcs();

	cout << "------------------------------------------" << endl;
	cout << "Graphe Oriente : \n" << "////////////// Sommets :" << endl;

	AFHAfficherListeSommets(vsListeSommet);

	cout << "////////////// Arcs :" << endl;

	AFHAfficherArc(vvsListeArc);

	cout << "------------------------------------------" << endl;
}
