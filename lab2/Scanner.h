//
// Created by Ciprian Marin on 26.10.2022.
//

#ifndef LAB2_SCANNER_H
#define LAB2_SCANNER_H

#include "SymbolTable.h"
#include "TokenClassifier.h"
#include "PIF.h"
using namespace std;

class Scanner {
    SymbolTable idSymbolTable, constSymbolTable;
    TokenClassifier tokenClassifier;
    PIF pif;

public:
    pair<bool, string> scan(const string& fileName);
    void printPif();
    void printSymbolTable();
private:
    vector<string> tokenize(string line);



};


#endif //LAB2_SCANNER_H
