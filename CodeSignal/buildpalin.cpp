/* https://app.codesignal.com/arcade/intro/level-10/ppZ9zSufpjyzAsSEx
Given a string, find the sortest possible string which can be achived by 
adding chars to the end of the initial str to make it a palindrome. 
Ex: abcdc , add ba and return abcdcba, abcdeffgffe returns abcdeffgffedcba
*/

#include <iostream> 
#include <string> 
#include <stack>
#include <vector> 
using namespace std; 

// Aux function to determine if str is a palindrome
bool isPalin(string str){
    for (int i{}; i<=str.size()/2; i++)
        if (str[i]!=str[str.size()-1-i]) return false; 
    return true; 
}

/* If str is a palindrome already, just return it. If not, find the size of the 
biggest possible palindrome from the last char in str. Then aux = the prefix
of str which isn't a palindrome. Reverse it and add to the end of str. Now str is a palindrome. 
*/
string buildPalindrome(string str) {
    if (isPalin(str)) return str;  
    int size = str.size()-1, sizePalind=0; ; 
    char lastChar = str[size];
    for (int i{}; i<=size; i++){
        if (str[i] == str[lastChar]){
            sizePalind++;
            lastChar--; 
        } else {
            sizePalind=0; 
            lastChar=size; 
        }
    }
    string aux = str.substr(0, str.size() - sizePalind); 
    reverse(aux.begin(), aux.end()); 
    return str+aux; 
}

int main(){
    string str; cin >> str;  
    cout << "Result: " << buildPalindrome(str);
}