#include <iostream>
#include "SymbolTable.h"
#include "Scanner.h"
#include "FiniteAutomata.h"
#include <fstream>
#include <iostream>
using namespace std;
int main() {
    FiniteAutomata fa;
    fa.load_from_json_file("/Users/cipri/CLionProjects/flcd/lab2/dfa_ex.json");
    vector<string> seq{"_", "_"};
    cout<<fa.check_sequence(seq)<<"\n";

    vector<string> seq1{"_", "a", "1"};
    cout<<fa.check_sequence(seq1)<<"\n";

    vector<string> seq2{"_"};
    cout<<fa.check_sequence(seq2)<<"\n";
    return 0;
}
