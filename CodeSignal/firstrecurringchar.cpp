/*
Find the first recurring character in a string
*/

#include <iostream>
#include <string> 
#include <map>
using namespace std; 

// solution with Map to avoid n^2 complexity
int firstRec(string str){
    int res=0; 
    map<char, int> mapa; 
    for (int i=0; i<str.size(); i++){
        auto itr = mapa.find(str[i]);
        if (itr!=mapa.end()) return i; 
        mapa.insert({str[i], 1});
    }
    return -1; 
}

int main(){
    string str = "abcdefapqowewiqeuqwioey";
    cout << "Result: " << firstRec(str);
}