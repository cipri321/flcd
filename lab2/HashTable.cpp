//
// Created by Ciprian Marin on 19.10.2022.
//

#include "HashTable.h"

using namespace std;
#include <vector>
#include <string>

bool HashTable::add(const string& s, int val) {
    if(exists(s)) {
        return true;
    }

    long long hash = compute_hash(s);
    int hash_pos = (int)(hash%((long long)hash_size));

    table[hash_pos].push_back({s, val});

    return true;
}

int HashTable::get(const string& s) {
    return find_value(s);
}

long long HashTable::compute_hash(const string& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

bool HashTable::exists(const string& s) {
    return find_value(s) != -1;
}

int HashTable::find_value(const string &s) {
    long long hash = compute_hash(s);
    int hash_pos = (int)(hash%((long long)hash_size));
    for(auto const &it: table[hash_pos]) {
        if(it.first == s)
            return it.second;
    }
    return -1;
}

void HashTable::clear() {
    table.clear();
}
