/* https://www.hackerrank.com/challenges/mars-exploration/problem
Given a string with SOS messages in it, determine how many letters of the SOS message have been changed. 
*/

#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 

// Complete the marsExploration function below.
int marsExploration(string s) {
    int res=0; 
    for (int i=0; i<s.size(); i++){
        int v=i%3; 
        switch (v){
            case 0: 
                if (s[i]!='S') res++; 
                break; 
            case 1: 
                if (s[i]!='O') res++; 
                break; 
            case 2: 
                if (s[i]!='S') res++; 
                break; 
        }
    }
    return res; 
}

int main(){
    string s = "SOSSPSSQSSOR";
    cout << "Result: " << marsExploration(s);
}