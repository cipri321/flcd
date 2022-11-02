//
// Created by Ciprian Marin on 26.10.2022.
//

#ifndef LAB2_TOKENCLASSIFIER_H
#define LAB2_TOKENCLASSIFIER_H
#include <utility>
#include <vector>
#include <string>
#include <regex>
#include "TokenCode.h"

using namespace std;

class TokenClassifier {
    vector<string> reservedWords, operators, separators;

public:
    TokenCode getType(const string& token);

    bool isReservedWord(string token);
    bool isOperator(string token);
    bool isSeparator(string token);
    static bool isIdentifier(const string& token);
    static bool isConstant(const string& token);

    TokenClassifier() {
        reservedWords = vector<string>{"var", "integer", "boolean", "char", "false", "true", "loop_until", "read", "print", "if", "else"};
        operators = vector<string>{"<", "<=", ">", ">=", "=", "<-", "+", "-", "*", "/", "%", ":"};
        separators = vector<string>{"~", ";", " ", "\n", "{", "}", "(", ")", "[", "]"};
    }
};


#endif //LAB2_TOKENCLASSIFIER_H
