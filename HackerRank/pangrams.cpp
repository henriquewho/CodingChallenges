/* https://www.hackerrank.com/challenges/pangrams/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

Return "pangram" or "not pangram". A string is a pangram if it has all letters in the alphabet. 
*/

#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

string pangrams(string s) {
    vector<int> letters(26,0); 

    for (int i=0; i<s.size(); i++){
        int numLetter = (int)s[i];

        if (numLetter>=65 && numLetter<=90){
            letters[numLetter-65]++;
        } else if (numLetter>=97 && numLetter<=122) {
            letters[numLetter-97]++;
        }
        
    }

    for (auto x: letters) if (x==0) return "not pangram";
    return "pangram"; 
}


int main(){

    string s = "We promptly judged naantique ivory buckles for the next prize";
    cout << "Result: " << pangrams(s); 
}