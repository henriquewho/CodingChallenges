/* https://app.codesignal.com/arcade/intro/level-4/Xfeo7r9SBSpo3Wico

Given a string, find out if its chars can be rearranged to form a string
*/



#include <iostream>
#include <vector> 
#include <string> 
#include <map> 
using namespace std; 

// All chars must be in  pair numbers to meet the problem condition
// with just one in odd qtity if the string is odd itself
bool palindromeRearranging(string inputString) {
    vector<int> occurrences(26); 
    for (int i{}; i<inputString.size(); i++){
        occurrences[(int)inputString[i]-97]++;
    }
    int odd=0; 
    for (auto &x: occurrences) if (x%2) odd++; 
    if (inputString.size()%2==0) {
        return (odd==0) ? true : false; 
    } else return (odd<=1) ? true : false; 
}

int main(){
    string a = "acab";
    cout << "Result: " << palindromeRearranging(a);
}

