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

}

bool FiniteAutomata::check_sequence(const vector<string>& sequence) {
    string curr_state = initial_state;
    for(const auto &it: sequence) {
        if((curr_state=get_next_state(curr_state, it)).empty()) {
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

string FiniteAutomata::get_next_state(const string& curr_state, string symbol) {
    for(Transition it:transitions) {
        if(it.get_initial_state() == curr_state && it.get_symbol() == symbol) {
            return it.get_final_state();
        }
    }
    return {};
}
