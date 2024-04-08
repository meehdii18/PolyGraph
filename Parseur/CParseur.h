#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <sstream>


using namespace std;

class CParseur {
public :
    CParseur() = delete;

    static map<string,vector<pair<int,int> > > PRSParserFichier(const string &sNomFichier, const vector<string> &vListeParam);

};
