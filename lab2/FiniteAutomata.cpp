//
// Created by Ciprian Marin on 15.11.2022.
//

#include "FiniteAutomata.h"
#include <fstream>
#include <iostream>

void FiniteAutomata::load_from_json_file(string filename) {
    ifstream fi(filename, std::ifstream::binary);
    Json::Value jsonData;
    Json::Reader reader;
    if(reader.parse(fi, jsonData, false)) {
        for (const auto & state : jsonData["states"]) {
            states.push_back(state.asString());
        }

        for (const auto & symbol : jsonData["alphabet"]) {
            alphabet.push_back(symbol.asString());
        }

        for (const auto & transition : jsonData["transitions"]) {
            transitions.emplace_back(
                            transition["src_state"].asString(),
                            transition["dst_state"].asString(),
                            transition["symbol"].asString()
                    );
        }

        initial_state = jsonData["initial_state"].asString();
        for(const auto & state:jsonData["final_states"]) {
            final_states.push_back(state.asString());
        }
    }
    prepare_transition_map();
}

bool FiniteAutomata::check_sequence(const vector<string>& sequence) {
    string curr_state = initial_state;
    for(const auto &it: sequence) {
        if((curr_state=get_next_state_eff(curr_state, it)).empty()) {
            return false;
        }
    }
    return any_of(
            final_states.begin(),
            final_states.end(),
            [&curr_state](const string& final_state) {
                return curr_state==final_state;
            });
}

string FiniteAutomata::get_next_state(const string& curr_state, const string& symbol) {
    for(Transition it:transitions) {
        if(it.get_initial_state() == curr_state && it.get_symbol() == symbol) {
            return it.get_final_state();
        }
    }
    return {};
}

ostream &operator<<(ostream &os, const FiniteAutomata &fa) {
    os<<"STATES:\n";
    for(const auto& it:fa.states) {
        os<<it<<"\n";
    }
    os<<"\nALPHABET:\n";
    for(const auto& it:fa.alphabet) {
        os<<it<<" ";
    }
    os<<"\n\nTRANSITIONS:\n";
    for(auto it:fa.transitions) {
        os<<it.get_initial_state()<<" -> "<<it.get_symbol()<<" -> "<<it.get_final_state()<<"\n";
    }
    os<<"\nINITIAL STATE:\n";
    os<<fa.initial_state<<"\n";
    os<<"\nFINAL STATES:\n";
    for(const auto& it:fa.final_states) {
        os<<it<<"\n";
    }
    return os;
}

void FiniteAutomata::prepare_transition_map() {
    for(auto it: transitions) {
        transition_map[it.get_initial_state()][it.get_symbol()] = it.get_final_state();
    }
}

string FiniteAutomata::get_next_state_eff(const string &curr_state, const string &symbol) {
    if(transition_map[curr_state].find(symbol) == transition_map[curr_state].end())
        return "";
    return transition_map[curr_state][symbol];
}

