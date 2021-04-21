/* https://app.codesignal.com/arcade/intro/level-11/o2uq6eTuvk7atGadR
Encode a string s with the following steps: 
- Divide s into the least possible number of disjoint substrings consisting of identical chars. aabbbc is divided into aa bbb and c
- Each substr with length greater than one is replaced with a concat of its length and the repeating char. bbb turns into 3b
- all the new strings are concatenated together and a new string is returned
*/

#include <string> 
#include <iostream>
#include <vector> 
#include <map> 
using namespace std; 

string lineEncoding(string str) {
    int countEach=1;
    string res=""; 
    for (int i=0; i<str.size(); i++){
        if (str[i] == str[i+1]){
            countEach++; 
        } else {
            if (countEach==1){
                res = res+str[i];
            } else {
                res = res + to_string(countEach) + str[i];
            }
            countEach=1; 
        }
    }
    return res; 
}

int main(){
    string str = "abbcabb"; 
    cout << "Result: " << lineEncoding(str) << endl; 
}