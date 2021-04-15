/* https://app.codesignal.com/arcade/intro/level-9/hoLtYWbjdrD2PF6yo
Return the digit degree of n. It is the number of times we need to 
replace this number with the sum of its digits to get a one digit degree. 
*/
#include <string>
#include <iostream> 
#include <algorithm> 
#include <sstream>
using namespace std; 

// Version using string manipulation
int digitDegree2 (int n) {
    int sum=n; 
    int count=0; 
    
    while (sum >= 10){
        count++; 
        stringstream ss; 
        ss << sum;  
        string str = ss.str(); 
        sum =0; 
        for (auto &x: str){
            sum += stoi(string(1, x)); 
        }
    }
    return count; 
}

// Recursive version. DigitSum is an aux function to return the sum of 
// the digits of a number. The recursion then is trivial. 
int digitSum(int n){
    int sum=0; 
    while (n) {
        sum += n%10; 
        n/= 10; 
    }
    return sum; 
}

int digitDegree (int n){
    if (n/10 > 0){
        return 1+digitDegree(digitSum(n));
    }
    return 0; 
}



int main(){
    int n; cin >> n; 
    cout << "Result: " << digitDegree(n); 
}