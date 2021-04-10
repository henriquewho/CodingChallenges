/* https://app.codesignal.com/arcade/intro/level-7/ZFnQkq9RmMiyE6qtq
Given a sorted array of integers, determine which element of a is closest to all other values of a. 
Find the element x in a which minimizes the following sum: 
abs(a[0]-x) + abx(a[1]-x) + ... + abs(a[a.size()-1]-x)
*/
#include <iostream> 
#include <vector> 
#include <math.h>
#include <climits>
using namespace std; 

// Constant solution O(1)
/* The values in the array don't matter for the calculation, as they're already
sorted! An element having the value of -9999 or 9999 doesn't interfere in the 
final result, as the value we look for is already in the array (we don't look for
the best element overall, but the best element in the array). So, we just return
the array 'median' element, the one in its size/2 position, as this is the 'tipping
point' for the equation. 
*/
int absoluteValuesSumMinimization2(vector<int> a) {
    return a[(a.size() - 1) / 2];
}

// Naive solution by brute force with O(n^2) time complexity
int absoluteValuesSumMinimization(vector<int> a) {
    int value=0, absSum=0;
    vector<int> values(a.size()); 

    for (int i{}; i<a.size(); i++){
        absSum=0; 
        for (int j{}; j<a.size(); j++){
            absSum+=abs(a[j]-a[i]);
        }
        values[i]=absSum;
    }

    int smallest=INT_MAX; 
    for (int i{}; i<values.size(); i++) {
        if (values[i]<smallest) {
            smallest = values[i];
            value=i; 
        }
    }

    return a[value]; 
}

int main(){
    vector<int> a = {0,1,3,9999,29999,39999,40000};
    cout << "Result: " << absoluteValuesSumMinimization(a); 
}