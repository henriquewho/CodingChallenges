/* https://app.codesignal.com/arcade/intro/level-2/xskq4ZxLyqQMCLshr

Given a rectangular matrix (h can / will be different from w) of integers where each value represents  a room cost, 
return the total sum of all rooms that don't appear below a 0. 
*/

#include <iostream> 
#include <vector> 
using namespace std; 

int matrixElementsSum(vector<vector<int>> matrix) {
    int res=0; 
    for (int i=0; i<matrix[0].size(); i++){
        for (int j=0; j<matrix.size(); j++){
            res+= matrix[j][i]; 
            if ( matrix[j][i] == 0 ) break; 
        }
    }
    return res;
}

int main(){
    vector<vector<int>> matrix = {{0, 1, 1, 2}, 
                                  {0, 5, 0, 0}, 
                                  {2, 0, 3, 3}};
    cout << "Result: " << matrixElementsSum(matrix); 
}