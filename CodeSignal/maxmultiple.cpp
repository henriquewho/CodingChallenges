/* https://app.codesignal.com/arcade/code-arcade/intro-gates/HEsmEacHr2s9wahjr

given a divisor and a bound, find the largest N such that
N is divisible by divisor (N%divisor==0)
N is less than or equal to bound 
N > 0 

*/

#include <iostream> 
#include <vector> 
using namespace std; 

int maxMultiple(int divisor, int bound) {
    // mult will be less than bound (if bound%divisor!=0) or equal to bound otherwise
    int mult = bound/divisor; 
    mult = divisor * mult; 
    return mult;  
}

int main(){
    int div, b; cin >> div >> b; 
    cout << maxMultiple(div, b); 
}