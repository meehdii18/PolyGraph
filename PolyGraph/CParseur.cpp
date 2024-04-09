#include "CParseur.h"

map<string, vector<pair<int, int> > >CParseur::PRSParserFichier(const string& sNomFichier, const vector<string>& vDelimiteurs) {
    ifstream isFichier(sNomFichier);
    string sLigne;
    map<string, vector<pair<int, int> > > mDonnees;

    while (getline(isFichier, sLigne)) {
        for (const string& sDelimiteur : vDelimiteurs) {
            if (sLigne.find(sDelimiteur) != string::npos) {
                while (getline(isFichier, sLigne) && sLigne != "]") {
                    int iDebut, iFin;
                    sscanf_s(sLigne.c_str(), "%s=%d, %s=%d", sDelimiteur.c_str(), &iDebut, sDelimiteur.c_str(), &iFin);
                    mDonnees[sDelimiteur].push_back({ iDebut, iFin });
                }
            }
        }
    }
    
    return map<string, vector<pair<int, int> > >();
}