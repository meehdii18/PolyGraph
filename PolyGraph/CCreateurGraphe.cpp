#include "CCreateurGraphe.h"

/******************************************************
* CCGImporterGrapheFichier
*******************************************************
* Entree : GPOParam le graphe dans lequel importer des
* donnees;
* sFichier le chemin d'acces du fichier ou sont
* contenues les donnees a ajouter
* Necessite : Rien
* Sortie : Rien
* Entraine : La lecture du fichier en parametre et s'il
* est conforme, la modification du graphe associe
******************************************************/
void CCreateurGraph::CCGImporterGrapheFichier(PGraphOrient<CArc, CSommet>& GPOParam, const string& sFichier)
{
    try
    {
        // LIRE VALEUR SIMPLE
        unsigned int uiNbArc = stoi(CParseur::PRSLireValeur(sFichier, "nbarcs"));
        unsigned int uiNbSommet = stoi(CParseur::PRSLireValeur(sFichier, "nbsommets"));
        unsigned int uiBoucle;
        unsigned int uiCritereArret;

        // LIRE VALEUR COMPLEXE
        vector<string> vDelimiteurs1 = { "Debut","Fin" };
        map<string, vector<string>> vDonneesArc = CParseur::PRSLireValeurComplexe(sFichier, "Arcs", vDelimiteurs1);
        vector<string> vDelimiteurs2 = { "Numero" };
        map<string, vector<string>> vDonneesSommet = CParseur::PRSLireValeurComplexe(sFichier, "Sommets", vDelimiteurs2);

        // V�rification que les donn�es dans le fichier sont coh�rentes
        // Si c'est le cas on peut cr�er les sommets et les arcs
        // Sinon on renvoie une erreur
        if (vDonneesSommet["Numero"].size() != uiNbSommet)
        {
            throw(runtime_error("Incoherence des donnees dans le fichier texte concernant le nombre de sommets."));
        }
        if (vDonneesArc["Debut"].size() != uiNbArc or vDonneesArc["Fin"].size() != uiNbArc)
        {
            throw(runtime_error("Incoherence des donnees dans le fichier texte concernant le nombre d'arcs."));
        }
        //Ajouter sommets et arcs
        uiCritereArret = (unsigned int)vDonneesSommet["Numero"].size();

        for (uiBoucle = 0; uiBoucle < uiCritereArret; uiBoucle++)
        {
            GPOParam.GPOAjouterSommet(vDonneesSommet["Numero"][uiBoucle]);
        }

        uiCritereArret = (unsigned int)vDonneesArc["Debut"].size();

        for (uiBoucle = 0; uiBoucle < uiCritereArret; uiBoucle++)
        {
            GPOParam.GPOAjouterArc(vDonneesArc["Debut"][uiBoucle], vDonneesArc["Fin"][uiBoucle]);
        }

    }
    catch (const runtime_error& erreur)
    {
        std::cerr << "Runtime error: " << erreur.what() << std::endl;
    }
}

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

void CCreateurGraph::CCGImporterGrapheFichier(PGraphOrient<CArcPondere, CSommet>& GPOParam, const string& sFichier)
{
    try
    {
        // LIRE VALEUR SIMPLE
        unsigned int uiNbArc = stoi(CParseur::PRSLireValeur(sFichier, "nbarcs"));
        unsigned int uiNbSommet = stoi(CParseur::PRSLireValeur(sFichier, "nbsommets"));
        unsigned int uiBoucle;
        unsigned int uiCritereArret;

        // LIRE VALEUR COMPLEXE
        vector<string> vDelimiteurs1 = { "Debut","Fin","Poids"};
        map<string, vector<string>> vDonneesArc = CParseur::PRSLireValeurComplexe(sFichier, "Arcs", vDelimiteurs1);
        vector<string> vDelimiteurs2 = { "Numero" };
        map<string, vector<string>> vDonneesSommet = CParseur::PRSLireValeurComplexe(sFichier, "Sommets", vDelimiteurs2);

        // V�rification que les donn�es dans le fichier sont coh�rentes
        // Si c'est le cas on peut cr�er les sommets et les arcs
        // Sinon on renvoie une erreur
        if (vDonneesSommet["Numero"].size() != uiNbSommet)
        {
            throw(runtime_error("Incoherence des donnees dans le fichier texte concernant le nombre de sommets."));
        }
        if (vDonneesArc["Debut"].size() != uiNbArc or vDonneesArc["Fin"].size() != uiNbArc)
        {
            throw(runtime_error("Incoherence des donnees dans le fichier texte concernant le nombre d'arcs."));
        }
        //Ajouter sommets et arcs
        uiCritereArret = (unsigned int)vDonneesSommet["Numero"].size();

        for (uiBoucle = 0; uiBoucle < uiCritereArret; uiBoucle++)
        {
            GPOParam.GPOAjouterSommet(vDonneesSommet["Numero"][uiBoucle]);
        }

        uiCritereArret = (unsigned int)vDonneesArc["Debut"].size();

        for (uiBoucle = 0; uiBoucle < uiCritereArret; uiBoucle++)
        {
            GPOParam.GPOAjouterArc(vDonneesArc["Debut"][uiBoucle], vDonneesArc["Fin"][uiBoucle], vDonneesArc["Poids"][uiBoucle]);
        }

    }
    catch (const runtime_error& erreur)
    {
        std::cerr << "Runtime error: " << erreur.what() << std::endl;
    }
}