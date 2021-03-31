/* https://app.codesignal.com/arcade/intro/level-2/yuGuHvcCaFCKk56rJ

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

// Recusive solution
int shapeArea(int n) {
    if (n==1) return 1; 
    if (n==2) return 5; 
    return shapeArea(n-1) + n + (n-1)*2 + n-2; 
}

int main(){
    int n; cin>>n; 
    cout << shapeArea(n); 
}

