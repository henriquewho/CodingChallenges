/* https://app.codesignal.com/arcade/code-arcade/corner-of-0s-and-1s/e3zfPNTwTa9qTQzcX

Reverse the order of the bits in a given integer. 
*/
#include <iostream>
#include <string> 
#include <bitset>
#include <algorithm>
#include <math.h>
using namespace std; 

string toBinary (int a){
    string str=""; 
    while (a>0){
        string newChar = to_string(a%2);
        a/=2; 
        str = newChar + str;
    }
    return str; 
}

int mirrorBits(int a){
    string strBin = toBinary(a); 
    int res=0; 
    for (int i{}; i<strBin.size(); i++){
        if (strBin[i]=='1'){
            res+=pow(2,i); 
        }
    }
    return res; 
}

int main(){
    int a; cin>>a; 
    cout << "Result: " << mirrorBits(a);
}
