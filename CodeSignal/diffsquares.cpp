/* https://app.codesignal.com/arcade/intro/level-12/fQpfgxiY6aGiGHLtv
Calculate the number of DIFFERENT 2x2 squares in a rectangular matrix
*/
#include <iostream>
#include <vector> 
#include <string> 
#include <set>
#include <sstream>
using namespace std; 

// Solution using set
int differentSquares(vector<vector<int>> matrix) {
    set<string> set; 

    if (matrix.size()<2 || matrix[0].size()<2) return 0; 
    for (int i=0; i<matrix.size()-1; i++){
        for (int j=0; j<matrix[0].size()-1; j++){
            string curr =""; 
            stringstream str; 
            str << matrix[i][j] << matrix[i][j+1] << matrix[i+1][j] << matrix[i+1][j+1]; 
            curr = str.str(); 
            set.insert(curr); 
        }
    }
    return set.size(); 
}

int main(){
    vector<vector<int>> matrix { {1,2,1}, {2,2,2}, {2,2,2} , {1,2,3}, {2,2,1} };
    cout << "Result: " << differentSquares(matrix); 
}
