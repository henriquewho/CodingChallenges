/* https://app.codesignal.com/arcade/intro/level-12/uRWu6K8E7uLi3Qtvx
Construct a square matrix with a size NxN containing integers from 1 
to N^2 in a spiral order, from top left in clockwise direction
*/

#include <string> 
#include <vector> 
#include <iostream> 
using namespace std; 

// Goes until the last column OR until the element !=0. Do the same going to the 
// last line, back to the first column and back to the first line. Repeat until 
// the matrix is filled. 
vector<vector<int>> spiralNumbers(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0)); 
    int i=1, l=0, c=-1, lastDir=0;      // number, line, column, last direction

    while (i <= (n*n) ) {
        if (lastDir==0){
            res[l][++c] = i; 
            if (c==n-1 || res[l][c+1]!=0) lastDir=1; 
        } else if (lastDir==1){
            res[++l][c] = i; 
            if (l==n-1 || res[l+1][c]!=0) lastDir=2;
        } else if (lastDir==2){
            res[l][--c] = i; 
            if (c==0 || res[l][c-1]!=0) lastDir=3;
        } else if (lastDir==3){
            res[--l][c] = i; 
            if (l==0 || res[l-1][c]!=0) lastDir=0;
        }
        i++; 
    }
    return res; 
}

int main(){
    int n; 
    cin >> n; 
    vector<vector<int>> res = spiralNumbers(n); 
    for (auto &x: res) {
        for (auto &y: x) {
            cout << y <<","; 
        }
        cout << endl; 
    }
}