/* https://app.codesignal.com/arcade/intro/level-5/ZMR5n7vJbexnLrgaM

Given an arrangement of 'mines' in a minesweeper table, create its game setup with numbers indicating mines in the neighbours. The input matrix could be (or not) a square.
*/

#include <vector>
#include <iostream>
using namespace std; 

// Solution 2 = for each point, count the 8 surrounding values evaluating if it is a valid value. Create 8 increment assigments, and in each one check if one surrounding 'direction' is valid or not. 
vector<vector<int>> minesweeper2(vector<vector<bool>> matrix){
    vector<vector<int>> res(matrix.size(), vector<int>(matrix[0].size()));
    int lines = matrix.size()-1, rows = matrix[0].size()-1; 

    for (int i{}; i<=lines; i++){
        for (int j{}; j<=rows; j++){
            int v=0; 
            if (i!=0 && j!=0) v+=matrix[i-1][j-1];
            if (i!=0) v+=matrix[i-1][j];
            if (i!=0 && j!=rows) v+=matrix[i-1][j+1];
            if (j!=0) v+=matrix[i][j-1]; 
            if (j!=rows) v+=matrix[i][j+1];
            if (i!=lines && j!=0) v+=matrix[i+1][j-1];
            if (i!=lines) v+=matrix[i+1][j];
            if (i!=lines && j!=rows) v+=matrix[i+1][j+1];
            res[i][j]=v; 
        }
    }
    return res; 
}

// Naive solution = just count the values around each point in the matrix, discerning the special cases (corners and inside the borders)
vector<vector<int>> minesweeper(vector<vector<bool>> matrix) {
    int lines = matrix.size()-1; 
    int rows = matrix[0].size()-1;
    vector<vector<int>> res (matrix.size(), vector<int>(matrix[0].size()));

    for (int i=0; i<=lines; i++){
        for (int j=0; j<=rows; j++){
            int v=0; 
            // not cornered
            if (i!=0 && i!=lines && j!=0 && j!=rows){
                v = matrix[i-1][j-1]+matrix[i][j-1]+matrix[i+1][j-1]+matrix[i-1][j]+matrix[i+1][j]+matrix[i-1][j+1]+matrix[i][j+1]+matrix[i+1][j+1];
            }
            // left corner high
            else if (i==0 && j==0){
                v = matrix[0][1]+matrix[1][1]+matrix[1][0];
            } 
            // right corner high
            else if (i==0 && j==rows) {
                v = matrix[0][rows-1]+matrix[1][rows-1]+matrix[1][rows];
            }
            // left corner low 
            else if (i==lines && j==0){
                v = matrix[lines-1][1] + matrix[lines-1][0] + matrix[lines][1];
            }
            // right corner low 
            else if (i==lines && j==rows){
                v = matrix[lines][rows-1] + matrix [lines-1][rows-1] + matrix[lines-1][rows];
            }
            // inside the first line
            else if (i==0) {
                v = matrix[0][j-1]+matrix[0][j+1]+matrix[1][j-1]+matrix[1][j]+matrix[1][j+1];
            }
            // inside the last line
            else if (i==lines) {
                v = matrix[lines][j-1]+matrix[lines][j+1]+matrix[lines-1][j-1]+matrix[lines-1][j]+matrix[lines-1][j+1];
            }
            // inside the first col
            else if (i!=0 && i!=lines && j==0){
                v = matrix[i-1][0]+matrix[i+1][0]+matrix[i-1][1]+matrix[i][1]+matrix[i+1][1];
            }
            // inside the last col
            else if (j==rows){
                v = matrix[i-1][rows]+matrix[i+1][rows]+matrix[i-1][rows-1]+matrix[i][rows-1]+matrix[i+1][rows-1];
            }
            res[i][j]=v;
        }
    }
    return res; 
}


int main(){
    vector<vector<bool>> matrix = { {true, false, false}, {false, true, false}, {false, false, false}};
    vector<vector<int>> res = minesweeper2(matrix);
    for (auto x: res) {
        for (auto y: x) {
            cout << y << " ";
        }
        cout << endl; 
    }
}