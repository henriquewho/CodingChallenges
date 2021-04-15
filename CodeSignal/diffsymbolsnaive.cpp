/* https://app.codesignal.com/arcade/intro/level-8/8N7p3MqzGQg5vFJfZ
Find the number of different chars in a lowecase string
*/
#include <string> 
#include <iostream>
#include <set>
using namespace std; 

int differentSymbolsNaive(string s) {
    int letters[26] = {0};
    int count=0; 
    for (int i{}; i<s.size(); i++){
        letters[(int)s[i]-97]++; 
    }
    for (auto &x: letters) if (x!=0) count++; 
    return count; 
}

// Solution with set
/*
set<type>(structure.begin(), structure.end()) will return a set 
with all the elements from the structure. Since it is a set, each 
element can only appear one time.
*/
int differentSymbolsNaiveSet(string s) {
    return set<char>(s.begin(), s.end()).size(); 
}

int main(){
    string s; cin >> s; 
    cout << "Result: " << differentSymbolsNaiveSet(s); 
}