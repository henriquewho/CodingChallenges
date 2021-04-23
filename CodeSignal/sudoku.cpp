/* https://app.codesignal.com/arcade/intro/level-12/tQgasP8b62JBeirMS

Check if a 9x9 grid of numbers represents a correct solution for sudoku. 
Each column, each row and each of the nine 3x3 subgrids contains all the 
digits from 1 to 9. 
*/

#include <vector> 
#include <iostream>
#include <string> 
#include <algorithm>
#include <set>
using namespace std; 

// Passes 2 times by the grid. Could pass just once. First checks lines and columns, in
// the same 'step'. Then checks each 3x3 subgrid. 
bool sudoku (vector<vector<int>> grid) {
    for (int i{}; i<grid.size(); i++){
        set<int> lines;
        set<int> cols; 
        for (int j{}; j<grid.size(); j++){
            lines.insert(grid[i][j]);
            cols.insert(grid[j][i]);
        }
        if (lines.size()!=9) return false; 
        if (cols.size()!=9) return false; 
        lines.clear(); 
        cols.clear(); 
    }

    int count=0, indexLines=0, indexCols=0; 
    set<int> internal; 
    while(count<82){
        for (int i=indexLines; i<indexLines+3; i++){
            for (int j=indexCols; j<indexCols+3; j++){
                internal.insert(grid[i][j]);
            }
        }
        if (internal.size()!=9) return false; 
        internal.clear(); 
        count+=9; 
        indexLines+=3;
        if (indexLines==9){
            indexCols+=3; 
            indexLines=0; 
        }
    }
    return true; 
}

// Diff solution with similar cost. Uses the fact that the outer loop has 9 
// iterations. Pre-set the starting point of each of the 9 subgrids to run
// the calculation
bool sudoku (vector<vector<int>> grid) {
    vector<vector<int>> stPoint {{0,0}, {0,3}, {0,6}, {3,0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6}};
    for (int i{}; i<grid.size(); i++){
        set<int> internal; 
        for (int ii=stPoint[i][0]; ii<stPoint[i][0]+3; ii++){
            for (int jj=stPoint[i][1]; jj<stPoint[i][1]+3; jj++){
                internal.insert(grid[ii][jj]);
            }
        }
        if (internal.size()!=9) return false; 

        set<int> lines;
        set<int> cols; 
        for (int j{}; j<grid.size(); j++){
            lines.insert(grid[i][j]);
            cols.insert(grid[j][i]);
        }
        if (lines.size()!=9) return false; 
        if (cols.size()!=9) return false; 
        lines.clear(); 
        cols.clear(); 
        internal.clear(); 
    }
    return true; 
}

int main(){
    vector<vector<int>> grid {
        {1,3,2,5,4,6,9,8,7}, 
        {4,6,5,8,7,9,3,2,1}, 
        {7,9,8,2,1,3,6,5,4}, 
        {9,2,1,4,3,5,8,7,6}, 
        {3,5,4,7,6,8,2,1,9}, 
        {6,8,7,1,9,2,5,4,3}, 
        {5,7,6,9,8,1,4,3,2}, 
        {2,4,3,6,5,7,1,9,8}, 
        {8,1,9,3,2,4,7,6,5}}; 

    cout << "Result: " << sudoku(grid); 
}