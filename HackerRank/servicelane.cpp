/* https://www.hackerrank.com/challenges/service-lane/problem

You'll be given an array of widths at points along the road (indices), then a list of the indices of entry and exit points. 
Considering each entry and exit point pair, calculate the maximum size vehicle that can travel that segment of the service lane safely. 

Ex: 
n = 4
width = [2,3,2,1]
cases = [ [1,2] , [2,4]]

if the entry index is i=1 and the exit j=2, there are two segments widths of 2 and 3 respect, so the widest vehicle that can fit in both is 2. 
If i=2, and j=4, the widths are are 3,2,1 which limits vehicle width to 1. 

*/

#include <iostream>
#include <vector>
#include <string>
#include <climits> 
#include <algorithm>
using namespace std; 

// Complete the serviceLane function below.
vector<int> serviceLane(int n, vector<int> width, vector<vector<int>> cases) {
    vector<int> res; 

    // for each case i
    for (int i=0; i<cases.size(); i++){
        int lesser=INT_MAX; 

        for (int j=cases[i][0]; j<=cases[i][1]; j++){
            if (width[j]<=lesser) lesser = width[j];
        }

        res.push_back(lesser);
    }
    return res; 
}

vector<int> serviceLane2(int n, vector<int> width, vector<vector<int>> cases) {
    vector<int> res; 

    // for each case i
    for (int i=0; i<cases.size(); i++){
        int lesser=INT_MAX; 

        int beg = cases[i][0], end = cases[i][1];
        int lesserinrange = min(width[beg], width[end]);
        if (lesserinrange<=lesser) lesser = lesserinrange; 

        res.push_back(lesser);
    }
    return res; 
}


int main(){
    int n,t; 
    n=8; t=5; 
    vector<int> width {2, 3, 1, 2, 3, 2, 3, 3};
    vector<vector<int>> cases { {0,3}, {4,6}, {6,7}, {3,5}, {0,7} };

    vector<int> res = serviceLane2(n, width, cases);
    for (auto &x: res) cout << x << endl;
}