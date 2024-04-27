#include "CAffichage.h"

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
void CAffichage::AFHAfficherListeSommets(const vector<string>& vsListe)
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < vsListe.size(); uiBoucle++)
	{
		cout << " - \"" << vsListe[uiBoucle] << "\"" << endl;
	}
}


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
void CAffichage::AFHAfficherSommetAvecArc(const PGraphOrient<CArc, CSommet>& GPOParam, const string& sIdSommet)
{
	cout << "---------------------" << endl;
	vector<string> vsArcsEntrants = GPOParam.GPOLirePredecesseursSommet(sIdSommet);
	vector<string> vsArcsSortants = GPOParam.GPOLireSuccesseursSommet(sIdSommet);
	
	cout << "ID Sommet : " << sIdSommet << endl;

	unsigned int uiBoucle;


	cout << "   ///////////////////" << endl;
	cout << "   // Arcs entrants //" << endl;
	cout << "   ///////////////////" << endl;

	for (uiBoucle = 0; uiBoucle < vsArcsEntrants.size(); uiBoucle++)
	{
		cout << " - " << vsArcsEntrants[uiBoucle] << endl;
	}

	cout << "   ///////////////////" << endl;
	cout << "   // Arcs sortants //" << endl;
	cout << "   ///////////////////" << endl;

	for (uiBoucle = 0; uiBoucle < vsArcsSortants.size(); uiBoucle++)
	{
		cout << " - " << vsArcsSortants[uiBoucle] << endl;
	}
	cout << "---------------------" << endl;
}


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
void CAffichage::AFHAfficherArcs(const vector<vector<string>>& vvsListe)
{
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < vvsListe.size(); uiBoucle++)
	{
		string sOrigine = vvsListe[uiBoucle][0];
		string sDestination = vvsListe[uiBoucle][1];
		cout << " - \"" << sOrigine << "\" -> \"" << sDestination << "\"" << endl;
	}
}


/******************************************************
* AFHAfficherGraphe
*******************************************************
* Entree : GPOParam, le graphe a afficher
* Necessite : Rien
* Sortie : Rien
* Entraine : L'affichage des informations concernants
* le graphe passe en paramètre
******************************************************/
void CAffichage::AFHAfficherGraphe(const PGraphOrient<CArc, CSommet>& GPOParam)
{
	vector<string> vsListeSommet = GPOParam.GPOLireListeSommets();
	vector<vector<string>> vvsListeArc = GPOParam.GPOLireListeArcs();

	cout << "------------------------------------------" << endl;
	cout << "Graphe : \n" << endl;
	cout << "/////////////" << endl;
	cout << "// Sommets //" << endl;
	cout << "/////////////\n" << endl;

	AFHAfficherListeSommets(vsListeSommet);


	cout << "\n////////////" << endl;
	cout << "//  Arcs  //" << endl;
	cout << "////////////\n" << endl;

	AFHAfficherArcs(vvsListeArc);

	cout << "\n------------------------------------------" << endl;
}
