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
    static string PRSLireValeur(string sFichier,string sMotCle);
    static vector<vector<string>> PRSLireValeurComplexe(string sFichier, string sMotCle, vector<string> vDelimiteurs);
};