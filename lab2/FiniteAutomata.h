//
// Created by Ciprian Marin on 15.11.2022.
//

#ifndef FLCD_FINITEAUTOMATA_H
#define FLCD_FINITEAUTOMATA_H
#include <json/json.h>
#include <json/value.h>

#include "Transition.h"
#include <vector>
#include <unordered_map>

using namespace std;

class FiniteAutomata {
    vector<string> states;
    vector<string> alphabet;
    vector<Transition> transitions;
    string initial_state;
    vector<string> final_states;

    unordered_map<string, unordered_map<string, string> > transition_map;


public:
    void load_from_json_file(string filename);
    bool check_sequence(const vector<string>& sequence);
    friend ostream& operator<<(ostream& os, const FiniteAutomata& fa);

private:
    string get_next_state(const string& curr_state, const string& symbol);
    void prepare_transition_map();
    string get_next_state_eff(const string& curr_state, const string& symbol);

};


#endif //FLCD_FINITEAUTOMATA_H
