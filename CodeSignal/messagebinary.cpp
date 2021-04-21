/* https://app.codesignal.com/arcade/intro/level-12/sCpwzJCyBy2tDSxKW
Convert a binary message to a string
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <bitset> 
using namespace std; 

// aux function, converts any 8 digit binary to integer
int toBin(string str){
    int value=0; 
    int index=0; 
    for (int i=7; i>=0; i--){
        value+= ((str[i]=='0') ? 0 : 1) * pow(2,index); 
        index++; 
    }
    return value; 
}

// converts from integer (given by toBin()) to char
string messageFromBinaryCode(string code) {
    string msg=""; 
    for (int i{}; i<code.size()-1; i=i+8){
        string current = code.substr(i, 8); 
        int currentInt = toBin(current);
        msg += (char)currentInt; 
    }
    return msg; 
}

// Version using bitset.to_ulong() = retuns an ulong with the 
// integer value that has the same bits set as the bitset 
string messageFromBinaryCode2(string code){
    string msg=""; 
    for (int i{}; i<code.size()-1; i=i+8){
        bitset<8> character (code.substr(i, 8)); 
        msg += character.to_ulong(); 
    }
    return msg; 
}

int main(){
    string code = "01001101011000010111100100100000011101000110100001100101001000000100011001101111011100100110001101100101001000000110001001100101001000000111011101101001011101000110100000100000011110010110111101110101"; 
    cout << "Result: " << messageFromBinaryCode2(code); 
}