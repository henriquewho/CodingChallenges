/* https://www.hackerrank.com/challenges/divisible-sum-pairs/problem

Given an array of integers and an positive int k, determine the number of (i,j) paris where i<j and ar[i] + ar[j] is divisible by k

ar = 1,2,3,4,5,6
k=5
res = 3 ( 1,4  2,3  4,6 )
*/

#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count=0;

    for (int i=0; i<ar.size(); i++){

        for (int j=i+1; j<ar.size(); j++){
            //cout << ar[i] << " and " << ar[j] << endl;
            if ( (ar[i]+ar[j]) % k==0  ) {
               count++; 
            }
        }

    }
    return count; 

}

int main(){

    vector<int> ar {1,3,2,6,1,2};
    int k=3, n=ar.size(); 

    auto count = divisibleSumPairs(n,k,ar);
    cout << count << endl;

    return 0; 
}