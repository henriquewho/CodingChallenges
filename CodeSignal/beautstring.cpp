/* https://app.codesignal.com/arcade/intro/level-10/PHSQhLEw3K2CmhhXE
A string is beautiful if each letter appears AT MOST as many times as the previous letter in the alphabet within the string. if a occurs 10 times, b can appear from 0 to 10 times, and so on. 
*/

#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
using namespace std; 

/* Solution with map, which stores the frequency for each letter. 
Then checks if the letters form a sequence. If they form, run 
through the map asserting that the main condition is true. 
*/
bool isBeautifulString(string str) {
    map<char, int> freq; 
    map<char, int>::iterator itr; 
    for (auto &x: str){
        itr = freq.find(x);
        if (itr!=freq.end()){
            itr->second++; 
        } else {
            freq.insert({x, 1});
        }
    }

    itr = freq.end(); 
    itr--; 
    int last = (int)itr->first; 
    if ((last-96) != freq.size()) return 0; 
    
    itr = freq.begin(); 
    int prev = itr->second; 
    while (itr!=freq.end()){
        if (itr->second > prev) return 0; 
        prev = itr->second; 
        itr++; 
    }
    return 1; 
}


int main(){
    string str = "abcdefghijklmnopqrstuvwxyzqwertuiopasdfghjklxcvbnm"; 
    cout << "Result: " << isBeautifulString(str); 
}