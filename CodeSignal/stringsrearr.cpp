/* https://app.codesignal.com/arcade/intro/level-7/PTWhv2oWqd6p4AHB9
Given an array of equal-length strings, you'd like to know if its possible to 
rearrange the order of the strings so that each consecutive pair of strings 
differ by exactly one char. Return true if possible. 
*/

#include <string>
#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std; 

/* inputArray[i] and inputArray[i+1] must have exactly one differing char. 
So, inputArray = {"aa", "aa"} should return false, they differ by 0 elements. 
Solution is by brute force, couldn't think of a better option. 
*/

bool strDiff(string a, string b){
    int count=0; 
    for (int i{}; i<a.size(); i++){
        if (a[i]!=b[i]) count++; 
    }
    return (count==1) ? true : false; 
}

bool stringsRearrangement(vector<string> arr) {
    // without sorting one test case returned error
    sort (arr.begin(), arr.end());    

    // Used next_permutation, which will rearrange the elements n!-1 times. 
    // So in each while iteration, i and i-1 used for the comparison will assume new values.
    // The -1 accounts for the original arrangement
    while (next_permutation(arr.begin(), arr.end())){
        bool flag=true; 
        for (int i{}; i<arr.size()-1; i++){
            if ( !( strDiff(arr[i], arr[i+1])) ){
                flag=false; 
                continue; 
            }
        }
        // found a solution, return true
        if (flag==true) return true; 
    }    
    // checked all possiblities and no one returned a solution
    return false;     
}

int main(){
    vector<string> a = {"aba", "bbb", "bab"};
    vector<string> b = {"ab", "bb", "aa"};
    
    if (stringsRearrangement(a)) cout << "Result: True"; else cout << "Result: False";
}
