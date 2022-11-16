//
// Created by Ciprian Marin on 26.10.2022.
//

#ifndef LAB2_PIF_H
#define LAB2_PIF_H

#include <vector>
#include <string>
#include "TokenCode.h"

using namespace std;

class PIF {
    vector<pair<string, int> > table;
public:
    void add(const string& key, int val) {
        table.emplace_back(key, val);
    }
    friend ostream& operator<<(ostream& os, const PIF& pif);
};


#endif //LAB2_PIF_H
