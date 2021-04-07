/* https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem?h_r=next-challenge&h_v=zen

Check if a substring appears in order inside a bigger string
*/

#include <iostream>
#include <string> 
#include <vector> 
using namespace std; 

string hackerrankInString(string s) {
    string str = "hackerrank"; 
    int counter=0; 
    for (int i{}; i<s.size(); i++){
        if (s[i]==str[counter]) counter++; 
        if (counter==str.size()) return "YES";
    }
    return "NO"; 
}

int main(){
    string s = "hereiamstackerrank";
    cout << "Result: " << hackerrankInString(s); 
}