//
// Created by Ciprian Marin on 26.10.2022.
//

#ifndef LAB2_VALUE_H
#define LAB2_VALUE_H

#include <string>
using namespace std;
class Value {
    string name;
    string type;
    any val;
    Value(string n, string t, bool val) {
        name = n;
        type = t;
        boolValue = val;
    }
    Value(string n, string t, int val) {
        name = n;
        type = t;
        intValue = val;
    }
    Value(string n, string t, char val) {
        name = n;
        type = t;
        charValue = val;
    }

};


#endif //LAB2_VALUE_H
