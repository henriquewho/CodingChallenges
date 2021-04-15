/* https://app.codesignal.com/arcade/intro/level-10/HJ2thsvjL25iCvvdm

*/

#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

/* Tests wether is a '-' or symbol, then checks if is a digit or 
an alpha between A and F */
bool isMAC48Address(string str) {
    if (str.size()!=17) return false; 
    for (int i{}; i<str.size(); i++){
        if ((i+1)%3==0) {
            if (str[i]!='-') return false; 
        } else {
            if (!isdigit(str[i])){
                if ((int) str[i] < 65 || (int) str[i] > 70) return false; 
            }
        }
    }
    return true; 
}

int main(){
    string str1 = "00-1B-63-84-45-E6";
    string str2 = "00-1B-63-84-45-E6";
    cout << "Result: " << isMAC48Address(str2);

    //cout << (int)'A' << " " << (int)'F'; 
}
