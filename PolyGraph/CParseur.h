#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class CParseur {
public:
    CParseur() = delete;
    static string PRSMinuscule(string sParam);
    static string PRSLireValeur(string sFichier,string sMotCle);
    static vector<vector<string>> PRSLireValeurComplexe(const string& sFichier, const string& sMotCle, const vector<string>& vDelimiteurs);
};