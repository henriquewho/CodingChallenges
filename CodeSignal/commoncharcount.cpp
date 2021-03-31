/* https://app.codesignal.com/arcade/intro/level-3/JKKuHJknZNj4YGL32

Given two strings, find the number of common chars between them. 
aabcc & adcaa = return 3 (a, a, c)
*/

#include <vector> 
#include <string> 
#include <iostream> 
#include <map> 
using namespace std; 

// map solution to avoid n*n time complexity, being 2*n instead
int commonCharacterCount(string s1, string s2) {
    map<char, int> mapa; 
    int res=0; 

    // creates map of all chars found in s1 with their frequency
    for (int i=0; i<s1.size(); i++){
        auto itr = mapa.find(s1[i]);
        if (itr==mapa.end()){
            mapa.insert({s1[i], 1});
        } else {
            mapa[s1[i]]++; 
        }
    }

    // for all chars in s2, if char is in the map, increases the count
    for (int i=0; i<s2.size(); i++){
        auto itr = mapa.find(s2[i]);
        if (itr!=mapa.end()){ 
            if (mapa[s2[i]]>0) mapa[s2[i]]--, res++;
        }
    }
    return res; 
}

int main(){
    string s1 = "aabccfqoausjvmxabwyuuskakcmxnahsudowpadskxcxmashds", s2 = "adcfaaapqwoeourytyfghjdksalxcmmznxb";
    cout << "Result: " << commonCharacterCount(s1, s2);
}
