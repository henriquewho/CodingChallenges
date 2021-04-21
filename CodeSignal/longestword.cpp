/* https://app.codesignal.com/arcade/intro/level-12/s9qvXv4yTaWg8g4ma
Find the longest word in the text
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

string longestWord(string str) {
    string word="", temp=""; 

    for (int i{}; i<=str.size(); i++){
        if (isalpha(str[i])){
            temp+=str[i]; 
        } else if ( !isalpha(str[i]) || i==str.size() ){
            if (temp.size() > word.size()){
                word = temp; 
            }
            temp=""; 
        }
    }
    return word; 
}

int main(){
    string str; 
    getline(cin,str);
    cout << "Result: " << longestWord(str) << endl; 
}