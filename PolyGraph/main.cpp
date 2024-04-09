#include <iostream>
#include "CParseur.h"
using namespace std;

int main()
{
    vector<string> Delimiteurs = { "Arcs","Sommets" };
    map<string,unsigned int> data = CParseur::PRSParserFichier("./donnes.txt",Delimiteurs);
    
    for (const auto& pair : data) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
