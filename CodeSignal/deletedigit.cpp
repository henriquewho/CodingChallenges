/* https://app.codesignal.com/arcade/intro/level-11/vpfeqDwGZSzYNm2uX
Given an integer n, find the maximal possible by deleting one of its digits. 
*/

#include <string>
#include <vector> 
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;  

// Brute force solution in O(m) where m = number of digits in n
int deleteDigit(int n) {
    int res=0; 

    // For each iteration, will test the number without a digit, 
    // from the first on the right until the first in the left
    for (int i=1; i<=n; i = i*10){
        int curr = n%i + ( (n/i)/10) * i; 
        res = max(res,curr);
    }

    return res; 
}

int main(){
    int n; 
    cin >> n; 
    cout << "Result: " << deleteDigit(n) << endl; 
}