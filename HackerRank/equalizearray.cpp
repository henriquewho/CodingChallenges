/* https://www.hackerrank.com/challenges/equality-in-a-array/problem

Given an array of integers, determine the minimum number of elements to delete to leave only elements of equal value. 

Solution = just need to count which element is the prevalent (most occurences) and then subtract the total size - number of occurences of that element. 
*/

#include <iostream> 
#include <vector> 
using namespace std; 

// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {
    vector<int> numbers(101,0);
    int frequent=0; 

    for (int i=0; i<arr.size(); i++){
        numbers[arr[i]]++; 
        if ( numbers[arr[i]] > numbers[frequent] ) frequent = arr[i];
    }
    return arr.size() - numbers[frequent];
}


int main(){
    vector<int> arr {3,3,2,1,3};
    cout << equalizeArray(arr);
}