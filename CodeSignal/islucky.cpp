/* https://app.codesignal.com/arcade/intro/level-3/3AdBC97QNuhF6RwsQ

n has a even number of digits. 
return true if the sum of the first half of digits is equal to the sum of the second half. 
*/

#include <iostream>
#include <vector> 
#include <string> 
using namespace std; 

// most efficient version I could think, just uses a string method once to determine 
// the number of digits and passes through n one time
bool isLucky(int n){
    int digits = to_string(n).size(); 
    int counter=digits, balance=0; 
    while (n>0){
        int dig = n%10; 
        n/=10; 
        balance += (counter>(digits/2)) ? dig : -dig; 
        counter--; 
    }
    return (balance) ? false : true; 
}

int main(){
    int n=1231; 
    cout << isLucky(n); 
}