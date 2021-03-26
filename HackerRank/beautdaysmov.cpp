/* https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

Task: given a range of numbered days and a number k, determine the number of beautiful days. 

Beautiful day = numbers n where   |n - reverse(n) | is divisible by k.
For each n, if |n - rev(n)| % k ==0, then n is beutiful. 

i = starting number, j = ending number, k = the divisor


Obs: there's a way to reverse an integer without using strings: 

while(n!=0){
    rem = n%10; 
    reverse = reverse*10+rem; 
    n = n/10; 
}

*/

#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm>

using namespace std; 

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    int count=0; 
    for (int ii = i; ii <= j; ii++){

        int n = ii; 
        string s = to_string(ii);
        reverse(s.begin(), s.end());
        int nRev = stoi(s); 

        if ( abs(n-nRev)%k==0 ) count++;
    }

    return count; 

}

int main(){
    int a = beautifulDays(20, 23, 6);
    cout << a; 
}