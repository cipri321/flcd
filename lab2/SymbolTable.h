//
// Created by Ciprian Marin on 26.10.2022.
//

#ifndef LAB2_SYMBOLTABLE_H
#define LAB2_SYMBOLTABLE_H

#include "HashTable.h"

class SymbolTable {
    HashTable identifiers;
    HashTable constants;
    vector<Value> values;
public:
    bool insert(const string &name, const Value &val);
    Value get_value(const string &name);
};


#endif //LAB2_SYMBOLTABLE_H
