/* https://www.hackerrank.com/challenges/cut-the-sticks/problem

task: given a number of sticks vector<int> arr. You'll cut the sticks into smaller sticks, discarding the shortest pieces until there are none left. At each iteration you'll determine the length of the shortest stick remaining, cut that lenght from each of the longer sticks and then discard all the pieces of that shortest length. When all remaning sticks are of the same length, they can't be shortened so discard them.
Print the number of sticks remanning after each iteration.
*/

#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std; 

// A slightly better solution
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> solution; 

    // sort the array
    //sort(arr.begin(), arr.end());
    for (int i=0; i<arr.size(); i++){
        for (int j=i; j<arr.size(); j++){
            if (i!=j){
                if (arr[i]>arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    solution.push_back(arr.size());

    for (int i=0; i<arr.size()-1; i++){
        if (arr[i]!=arr[i+1]) {
            solution.push_back(arr.size()-i-1);
        }
    }
    return solution;
}

// My solution.
vector<int> cutTheSticks2(vector<int> arr) {
    vector<int> solution; 
    int count=0, totalCount=0;

    // sort the array
    for (int i=0; i<arr.size(); i++){
        for (int j=i; j<arr.size(); j++){
            if (i!=j){
                if (arr[i]>arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    //sort(arr.begin(), arr.end());

    solution.push_back(arr.size());
    
    for (int i=0; i<arr.size()-1; i++){
        if ( arr[i] == arr[i+1] ) {
            count++;
        }
        else {
            totalCount +=count+1; 
            solution.push_back(arr.size()-totalCount);
            count=0;
        }
    }
    return solution; 
}

int main(){
    vector<int> arr {3,1,2,5,4};
    //vector<int> arr {1,2,3,4,3,3,2,1};
    vector<int> res = cutTheSticks(arr);
    for (auto x: res) cout << x << " "; 
}