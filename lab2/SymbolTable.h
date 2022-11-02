//
// Created by Ciprian Marin on 26.10.2022.
//

#ifndef LAB2_SYMBOLTABLE_H
#define LAB2_SYMBOLTABLE_H

#include "HashTable.h"

class SymbolTable {
    HashTable table;
    int size=0;
public:
    int insert(const string &name);
    int get_id(const string &name);
//    friend ostream& operator<<(ostream& os, const SymbolTable& symbolTable);

};


#endif //LAB2_SYMBOLTABLE_H
