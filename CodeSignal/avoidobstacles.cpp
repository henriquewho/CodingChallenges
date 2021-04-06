/* https://app.codesignal.com/arcade/intro/level-5/XC9Q2DhRRKQrfLhb5

You're given an array of integers representing coords of obstacles in a line. 
Assume you're jumping from the point with the coord 0 to the right. You're allowed 
only to make jumps of the same length represented by some integer.
Find the minimal lenght of the jump enough to avoid all obstacles. 

Ex: {5, 3, 6, 7, 9}, jump on 4, then 8, then after 9 it doesn't matter
*/

#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std; 

// Try all possible jumps from 1 to the maximum, which is the biggest
// element in the array. First we need to order the array. 
// Don't know if there's a better algorithm for this (O(n^2) worst case)
// A simple change could be to start testing from the size of the biggest sequence in the array
int avoidObstacles(vector<int> inputArray) {
    vector<int> arr = inputArray; 
    sort(arr.begin(), arr.end());

    bool obst = true; 
    int jump=1; 

    while (obst){
        obst = false; 
        jump++; 
        for (int i=0; i<arr.size(); i++){
            // For each element in the array, we check if jumps of 
            // the same size will end up in that element
            if (arr[i] % jump ==0 ){
                obst=true; 
                break; 
            }
        }
    }
    return jump; 
}

int main(){
    vector<int> arr = {5, 3, 6, 7, 9};
    cout << "Result: " << avoidObstacles(arr); 
}