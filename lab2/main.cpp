#include <iostream>
#include "SymbolTable.h"
#include "Scanner.h"
#include <fstream>
using namespace std;
int main() {
    Scanner scanner;
    scanner.scan("/Users/cipri/flcd/flcd/lab2/testInput.in");
    scanner.printPif();
    return 0;
}
