/* https://app.codesignal.com/arcade/intro/level-8/Rqvw3daffNE7sT7d5
Given an array of positive integers, find the maximal possible sum of 
k consecutive elements. 
*/
#include <iostream> 
#include <vector> 
using namespace std; 

// Linear solution, passes all the tests
/* First creates a sum with the first k elements from the array. 
Then, at each iteration, change the sum to delete the first value 
and replace it with the next in the array. Then test the value. 
*/
int arrayMaxConsecutiveSum(vector<int> arr, int k) {
    int localSum=0; 
    for (int i{}; i<k; i++) localSum+=arr[i];
    int maxSum = localSum; 
    for (int i=k; i<arr.size(); i++){
        localSum-=arr[i-k];
        localSum+=arr[i];
        if (localSum > maxSum) maxSum=localSum; 
    }
    return maxSum; 
}

// Solution worst case O(n^2), didn't passed one test case
int arrayMaxConsecutiveSum2(vector<int> arr, int k) {
    int maxSum = INT_MIN; 

    for (int i{}; i<=arr.size()-k; i++){
        int localSum=0; 
        for (int j=i; j<i+k; j++){
            localSum+=arr[j];
        }
        if (localSum > maxSum) maxSum = localSum; 
    }
    return maxSum; 
}

int main(){
    vector<int> inputArray {};
    int num;
    cout << "Enter the array (-1 to stop): \n"; 
    do {
        cin >> num; 
        inputArray.push_back(num);
    } while (num!=-1);
    
    cout << "Enter k: \n";
    int k; cin >> k; 
    cout << "Result: " << arrayMaxConsecutiveSum(inputArray, k); 
}
