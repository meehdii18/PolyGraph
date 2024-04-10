#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class CParseur {
public:
    CParseur() = delete;
    static map<string, vector<unsigned int>> PRSParserFichier(string sFichier, vector<string> vMotsCles);
    static string PRSMinuscule(string sParam);
};