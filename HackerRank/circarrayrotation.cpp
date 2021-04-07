/* https://www.hackerrank.com/challenges/circular-array-rotation/problem

For each array, perform a number of right circular rotations and return the values of the elements at the given indexes. 

Ex: 
a[3,4,5]
k = 2
queries = [1,2]

5,3,4 4,5,3 return [5,3]

*/

#include <iostream> 
#include <vector> 
using namespace std; 

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> ret; 
    vector<int> newArr(a.size());
    for (int i=0; i<a.size(); i++){
        int newIndex = (i+k)%a.size(); 
        newArr[newIndex] = a[i];
    }
    for (auto x: queries){
        ret.push_back(newArr[x]);
    }
    return ret; 
}

int main(){
    vector<int> arr {3,4,5}, queries {1,2};
    int k=2; 

    vector<int> res = circularArrayRotation(arr, k, queries);
    for (auto x: res) cout << x << " ";
}