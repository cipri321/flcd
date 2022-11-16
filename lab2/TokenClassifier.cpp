//
// Created by Ciprian Marin on 26.10.2022.
//

#include "TokenClassifier.h"

TokenCode TokenClassifier::getType(const string& token) {
    if(isReservedWord(token))
        return reservedWord;
    if(isOperator(token))
        return op;
    if(isSeparator(token))
        return sep;
    if(isConstant(token))
        return constant;
    if(isIdentifier(token))
        return id;
    return invalid;
}

bool TokenClassifier::isReservedWord(string token) {
    return any_of(reservedWords.begin(), reservedWords.end(), [&token](const string& word) {return word==token;});
}
bool TokenClassifier::isOperator(string token) {
    return any_of(operators.begin(), operators.end(), [&token](const string& op) {return op==token;});
}
bool TokenClassifier::isSeparator(string token) {
    return any_of(separators.begin(), separators.end(), [&token](const string& word) {return word==token;});
}
bool TokenClassifier::isIdentifier(const string& token) {
    regex idPattern("^[a-zA-Z]([a-z|A-Z|0-9|_])*$");
    return regex_match(token, idPattern);
}
bool TokenClassifier::isConstant(const string& token) {
    regex intPattern("([+-]?[1-9][0-9]*)|0");
    regex charPattern("^\'[a-zA-Z0-9_?!#*./%+=<>;)(}{ ]\'");
    regex stringPattern("^\"[a-zA-Z0-9_?!#*./%+=<>;)(}{ ]+\"");
    regex boolPattern("^(true|false)");
    return regex_match(token, intPattern) ||
    regex_match(token, charPattern) ||
    regex_match(token, stringPattern) ||
            regex_match(token, boolPattern);
}

