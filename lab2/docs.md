Hash Table
 - used to implement the Symbol Table with O(1) amortized time complexity for insert and get

 - ```bool add(const string& s, int val) - used to add a new pair with the key s and value val, which will be the position in the symbol table implemented as an array```
 - ```int get(const string& s) - used to get the position in the array for the key s```
 - ```static long long compute_hash(const string& s) - creates a hash for a string by writing the string in base 31 using the ASCII codes of the chars```
 - ```bool exists(const string& s) - checks if key exists in table```
 - ```int find_value(const string& s) - returns the value of the key or -1 if it doesn't exist```


SymbolTable
 - used to implement the symbol table for the compiler
 - it can insert or get the id of a given identifier or constant

Scanner
 - ```pair<bool, string> scan(const string& fileName) - scans and creates the pif and symbol table for a given program, returns a pair that can either start with true and then an empty string or false and the lexical error```
 - ```vector<string> tokenize(string line) - creates a vector of tokens extracted from a string```

Finite Automata
 - ```void load_from_json_file(string filename) - creates a finite automata from a json file(structure is described below)```
 - ```bool check_sequence(const vector<string>& sequence) - checks if a sequence will be accepted by the finite automata```

            Structure of json file:
            <json_file>::= {states": <string_array>,
                        "alphabet": <string_array>
                        "transitions": <transition_array>,
                        "initial_state": <string>,
                        "final_states": <string_array>
                        }
              <string_array> ::= [] | [<string_list]
              <string_list> ::= <string> | <string>, <string_list>
              <transition_array> ::= [] | [<transition_list>]
              <transition_array> ::= <transition> | <transition>, <transition_list>
              <transition> ::= {"initial_state": <string>, "symbol":<string>, "final_state":<string>}
              <string> ::= "<char_seq>"
              <char_seq> ::= <empty> | <char><char_seq>
              <char> ::= any char