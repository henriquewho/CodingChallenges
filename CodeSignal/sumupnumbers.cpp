/* https://app.codesignal.com/arcade/intro/level-12/YqZwMJguZBY7Hz84T
Return the sum of numbers, and only the numbers, in a given string
*/

#include <vector>
#include <string>
#include <iostream> 
using namespace std; 

int sumUpNumbers(string str) {
    int res=0; 
    string curr="0"; 

    for (int i={}; i<=str.size(); i++){

        if (!isdigit(str[i]) || i==str.size()){
            int num = stoi(curr); 
            res+=num; 
            curr="0"; 
        } else {
            curr+=str[i];
        }

    }

    return res; 

}

int main(){
    string str; 
    getline(cin, str); 
    cout << "Result: " << sumUpNumbers(str); 
}