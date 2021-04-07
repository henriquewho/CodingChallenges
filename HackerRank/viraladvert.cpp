/* https://www.hackerrank.com/challenges/strange-advertising/problem

Determine how many people have liked the ad by the end of a given day. 
*/

#include <iostream> 
#include <vector> 
#include <string>
using namespace std; 

// Recursive version
int viralAdvertisingRecAux (int n, int received, int cumulative) { 
    if (n ==0) return cumulative; 
    else {
        return viralAdvertisingRecAux(n-1, (received/2)*3, cumulative+(received/2));
    }
}
int viralAdvertisingRec(int n){
    return viralAdvertisingRecAux(n, 5, 0);
}

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int shared = 5, liked=2, cumulative=2; 
    for (int i=2; i<=n; i++){
        shared = (shared/2) * 3;
        liked = shared/2; 
        cumulative+=liked; 
    }
    return cumulative; 
}

int main(){
    cout << viralAdvertisingRec(5);
}