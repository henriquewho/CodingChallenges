/* https://app.codesignal.com/arcade/intro/level-2/2mxbGwLzvkTCKAJMG

Given a sequence of integers as an array, determine whether is possible to obtain a strictly increasing seq by removing no more than one element from the array. No sorting allowed, so you should consider the default order of the elements. 

*/

#include <iostream> 
#include <vector> 
#include <string>
#include <climits>
using namespace std; 

// solution usng three indexes to compare the elements in trios.
bool almostIncreasingSequence(vector<int> arr) {
    int i1=0, i2=1, i3=2, count=0; 

    if (arr.size() < 3) return true; // for the case where arr has only up to two elements

    while (i3<arr.size()){
        if (arr[i1] < arr[i2] && arr[i2] < arr[i3]) {
            i1++; i2++; i3++; 
        } else {
            count++; if (count>1) return false; 
            
            if ( (arr[i1]>=arr[i2] && arr[i2]>=arr[i3]) || ((arr[i1]>=arr[i2] && arr[i2] >= arr[i3] && arr[i1]>=arr[i3]))) {
                return false; 
            }
            else if ( (arr[i1] > arr[i2] && arr[i1] > arr[i3]) || ((arr[i1]>arr[i2] && arr[i2]<arr[i3])) ){
                i1++; i2++; i3++;
            }
            else if (arr[i1]<arr[i2] && (arr[i1]==arr[i3])){
                arr.erase(arr.begin()+i3);
            }
            else if (arr[i1] < arr[i2] && arr[i2] > arr[i3]){
                arr.erase(arr.begin()+i2);
            }
        }
    }
    return true; 
}

int main(){
    vector<int> sequence1 {10, 1, 2, 3, 4, 5};
    vector<int> sequence2 {40, 50, 60, 10, 20, 30};
    vector<int> sequence3 {1, 2, 3, 8, 3, 4, 5};
    vector<int> sequence4 {1, 2, 3, 4, 3, 6};  // 3 8 3 
    vector<int> sequence5 {1,2,5,3,5};           // 2 8 3
    vector<int> sequence6 {1,2,1,2};

    cout << "Result: " << almostIncreasingSequence(sequence1) << endl; 
    cout << "Result: " << almostIncreasingSequence(sequence2) << endl; 
    cout << "Result: " << almostIncreasingSequence(sequence3) << endl; 
    cout << "Result: " << almostIncreasingSequence(sequence4) << endl; 
    cout << "Result: " << almostIncreasingSequence(sequence5) << endl; 
    cout << "Result: " << almostIncreasingSequence(sequence6) << endl; 
}