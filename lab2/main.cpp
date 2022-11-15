#include <iostream>
#include "SymbolTable.h"
#include "Scanner.h"
#include <fstream>
using namespace std;
int main() {
    Scanner scanner;
    pair<bool, string> correct = scanner.scan("/Users/cipri/flcd/flcd/lab2/testInput.in");
    if(correct.first) {
        cout<<"The program is lexically correct"<<"\n";
        scanner.printSymbolTable();
        scanner.printPif();
    }
    else {
        cout<<"The program is not lexically correct"<<"\n";
        cout<<correct.second;
    }
    return 0;
}
