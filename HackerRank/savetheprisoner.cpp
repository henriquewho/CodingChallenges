/* https://www.hackerrank.com/challenges/save-the-prisoner/problem

n = number of prisoners 
m = number of sweets
s = chair number to begin passing

From s in [0...n], where does it stop after m steps
*/

#include <iostream> 
#include <vector> 
using namespace std; 

int saveThePrisoner(int n, int m, int s) {
    int ret=0; 
    ret = (-1+s+m)%(n); 
    if (ret==0) ret = n; 
    return ret; 
}

int main(){
    cout << saveThePrisoner(4,6,2); cout << endl;
    cout << saveThePrisoner(5,2,1); cout << endl;
    cout << saveThePrisoner(5,2,2); cout << endl;
    // 3 2 3
}