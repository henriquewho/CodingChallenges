/* https://app.codesignal.com/arcade/intro/level-5/5xPitc3yT3dqS7XkP
In a matrix of numbers, if a number has eight numbers around it, calc the average of the 9 numbers set. 
*/

#include <vector> 
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std; 

// Here we have 4 nested for loops. But that's not a problem 
// for this alg, as the: 
// - first two for loops are obligatory to run through the matrix
// - other for loops will always have just 9 iterations total
// So it's just a style choice between using nested for loops or a big formula

vector<vector<int>> boxBlur(vector<vector<int>> image) {
    vector<vector<int>> res; 
    for (int i=1; i<image.size()-1; i++){
        res.push_back({});
        for (int j=1; j<image[0].size()-1; j++){
            int blurred=0; 
            for (int ii=i-1; ii<=i+1; ii++) {
                for (int jj=j-1; jj<=j+1; jj++){
                    blurred += image[ii][jj];
                }
            }
            blurred = floor(blurred/9);
            res[res.size()-1].push_back(blurred);
        }
    }
    return res; 
}

int main(){
    vector<vector<int>> image = {{7, 4, 0, 1}, 
                                {5, 6, 2, 2}, 
                                {6, 10, 7, 8}, 
                                {1, 4, 2, 0}};
    vector<vector<int>> res = boxBlur(image); 

    cout << "Result: \n"; 
    for (int i=0; i<res.size(); i++){
        for (int j=0; j<res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl; 
    }
}