//
// Created by Ciprian Marin on 26.10.2022.
//

#include "SymbolTable.h"
#include <iostream>

int SymbolTable::insert(const string &name) {
    int value = table.get(name);
    if(value != -1)
        return value;
    table.add(name, size++);
    return table.get(name);
}

int SymbolTable::get_id(const string &name) {
    return table.get(name);
}

ostream &operator<<(ostream &os, const SymbolTable &symbolTable) {
    vector<pair<int, string> > hash_table = symbolTable.table.get_table();
    for(auto it: hash_table)
        os<<it.first<<" "<<it.second<<"\n";
    return os;
}
