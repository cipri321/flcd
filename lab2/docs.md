Hash Table
 - used to implement the Symbol Table with O(1) amortized time complexity for insert and get

 - ```bool add(const string& s, int val) - used to add a new pair with the key s and value val, which will be the position in the symbol table implemented as an array```
 - ```int get(const string& s) - used to get the position in the array for the key s```
 - ```static long long compute_hash(const string& s) - creates a hash for a string by writing the string in base 31 using the ASCII codes of the chars```
 - ```bool exists(const string& s) - checks if key exists in table```
 - ```int find_value(const string& s) - returns the value of the key or -1 if it doesn't exist```

