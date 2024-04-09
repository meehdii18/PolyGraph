#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class CParseur {
public:
    CParseur() = delete;
    static map<string, unsigned int> PRSParserFichier(string sFichier, vector<string> vMotsCles);
};