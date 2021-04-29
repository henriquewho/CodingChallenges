/* https://app.codesignal.com/arcade/code-arcade/loop-tunnel/7BFPq6TpsNjzgcpXy

Given n, find the minimal k such that: 
k = m!, for some integer m
k >= n
*/

#include <iostream> 
#include <algorithm>
using namespace std;

// First solution by brute force
int fact(int n){
    int res=1; 
    for (int i=1; i<=n; i++){
        res*=i; 
    }
    return res; 
}

int leastFactorial(int n){
    while (true){
        for (int i=1; i<=n; i++){
            if (fact(i) == n) return n; 
        }
        n++; 
    }
}

// Other solution
int leastFactorial2 (int n){
    int m=1; 
    for (int i=2; m<n; i++){
        m = m*i; 
    }
    return m; 
}

int main(){
    int n; cin >> n; 
    cout << "Result: " << leastFactorial2(n); 
}

