//
// Created by Ciprian Marin on 19.10.2022.
//

#ifndef LAB2_HASHTABLE_H
#define LAB2_HASHTABLE_H

#include <vector>
#include <string>

using namespace std;

class HashTable {
    vector<vector<pair<string, int> >> table;
    const int hash_size = 10;
public:
    HashTable() {
        table = vector<vector<pair<string, int> > >(hash_size);
    }
    bool add(const string& s, int val);
    int get(const string& s);
    void clear();
private:
    static long long compute_hash(const string& s);
    bool exists(const string& s);
    int find_value(const string& s);
};


#endif //LAB2_HASHTABLE_H
