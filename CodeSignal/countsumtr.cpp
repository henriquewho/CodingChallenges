/* https://app.codesignal.com/arcade/code-arcade/loop-tunnel/hBw5BJiZ4LmXcy92u
Given n, l and r, find the number of ways to represent n as: 
- n = A + B   ,  such that  l <= A <= B <= r
Constraints:  5 <= n <= 100000000
*/

#include <iostream>
#include <algorithm>
using namespace std; 

// Find the first case by using the same method as the brute force one, but 
// then use a formulaic solution to avoid multiple loops. Used 'goto' to escape
// nested loops. 

int countSumOfTwoRepresentations2(int n, int l, int r) {
    int res=0, first=0, second=0; 
    for (int i=l; i<=r; i++){
        for (int j=r; j>=l; j--){
            if (j+i==n && i<=j){
                first=i, second=j;
                goto l1;  
            } 
        }
    }
l1: if (first==0) return 0; 
    else return ((second-first)/2)+1; 
}

// First solution by brute force, obviously TLE for the big cases
int countSumOfTwoRepresentations(int n, int l, int r) {
    int res=0; 
    for (int i=l; i<=r; i++){
        for (int j=r; j>=l; j--){
            if (j+i==n && i<=j){
                cout << i << " " << j << endl; 
                res++; 
            } 
        }
    }
    return res; 
}

int main(){
    int n, l, r; 
    cin >> n >> l >> r; 
    cout << "Result: " << countSumOfTwoRepresentations2(n,l,r); 
}