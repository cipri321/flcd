//
// Created by Ciprian Marin on 26.10.2022.
//

#include "Scanner.h"
#include <fstream>
#include <iostream>

pair<bool, string> Scanner::scan(const string& fileName) {
    ifstream fi(fileName);
    char *aux=new char[1005];
    bool lexically_correct = true;
    string error = "";
    while(fi.getline(aux, 1000)) {
        vector<string> tokens = tokenize(aux);
        for_each(tokens.begin(), tokens.end(), [this, &lexically_correct, &error](const string& token) {
            TokenCode tk = tokenClassifier.getType(token);
            switch (tk) {
                case reservedWord:
                case op:
                case sep: {
                    pif.add(token, -1);
                    return;
                }
                case id: {
                    int idx = idSymbolTable.insert(token);
                    pif.add("id", idx);
                    return;
                }
                case constant: {
                    int idx = constSymbolTable.insert(token);
                    pif.add("const", idx);
                    return;
                }
                case invalid: {
                    error+=token+" is invalid\n";
                    lexically_correct = false;
                    return ;
                }

            }
        });

    }
    return {lexically_correct, error};
}

vector<string> Scanner::tokenize(string line) {
    vector<string> tokens;

    for(int i=0;i<line.size();i++) {
        //separator
        if (tokenClassifier.isSeparator(line.substr(i, 1)) && line[i] != ' ') {
            tokens.push_back(line.substr(i, 1));
        }
        //check char constant
        else if(line[i] == '\'') {
            if(TokenClassifier::isConstant(line.substr(i, 3))) {
                tokens.push_back(line.substr(i, 3));
                i+=2;
            }
            else {
                throw ;
            }
        }
        //check string constant
        else if(line[i] == '\"') {
            auto find_res = find(line.begin() + i, line.end(), '\"');
            if(find_res == line.end()) {
                throw ;
            }
            int pos = find_res - line.begin();
            if(TokenClassifier::isConstant(line.substr(i, pos - i + 1))) {
                tokens.push_back(line.substr(i, pos - i + 1));
                i=pos;
            }
            else {
                throw;
            }
        }
        //identifier error numeric first char
        else if(isdigit(line[i]) && i<line.size()-1 && isalpha(line[i+1])) {
            tokens.push_back(line.substr(i, 2));
            i++;
        }
        //check numeric constant
        else if(isdigit(line[i]) ||
                ((i<line.size()-1 && (line[i] == '+' || line[i] == '-') && isdigit(line[i+1])) &&
                !(!tokens.empty() &&
                (TokenClassifier::isConstant(tokens.back()) || TokenClassifier::isIdentifier(tokens.back()))))) {
            int len = 2;
            while(i+len-1<line.size() && TokenClassifier::isConstant(line.substr(i, len))) {
                len++;
            }
            len--;
            if(TokenClassifier::isConstant(line.substr(i, len))) {
                tokens.push_back(line.substr(i, len));
                i+=len-1;
            }
            else {
                throw ;
            }
        }
        //checking operator
        else if(i<line.size()-1 && tokenClassifier.isOperator(line.substr(i, 2))) {
            tokens.push_back(line.substr(i, 2));
            i++;
        }
        else if(tokenClassifier.isOperator(line.substr(i, 1))) {
            tokens.push_back(line.substr(i, 1));
        }
        //check if it is identifier or reserved word
        else if(isalpha(line[i])) {
            int len=1;
            while(i+len-1<line.size() && TokenClassifier::isIdentifier(line.substr(i, len))) {
                len++;
            }
            len --;
            if(TokenClassifier::isIdentifier(line.substr(i, len))) {
                tokens.push_back(line.substr(i, len));
                i+=len-1;
            }
        }
        else {
            tokens.push_back(line.substr(i, 1));
        }
    }

    return tokens;
}

void Scanner::printPif() {
    cout<<"PIF:\n"<<pif;
}

void Scanner::printSymbolTable() {
    cout<<"ID symbol table:\n"<<idSymbolTable<<"\n\nConst symbol table:\n"<<constSymbolTable<<"\n";
}
