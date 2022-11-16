//
// Created by Ciprian Marin on 15.11.2022.
//

#ifndef LAB2_TRANSITION_H
#define LAB2_TRANSITION_H

#include <string>
#include <utility>

using namespace std;


class Transition {
    string initial_state, final_state;
    string symbol;

public:
    Transition() {
        initial_state=final_state=symbol="";
    }
    Transition(string initial_state, string final_state, string symbol) {
        this->symbol=std::move(symbol);
        this->final_state=std::move(final_state);
        this->initial_state=std::move(initial_state);
    }

    string get_initial_state() {
        return this->initial_state;
    }

    string get_final_state() {
        return final_state;
    }

    string get_symbol() {
        return symbol;
    }
};


#endif //LAB2_TRANSITION_H
