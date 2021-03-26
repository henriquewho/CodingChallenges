/* https://www.hackerrank.com/challenges/minimum-distances/problem

The dist between two array values is the number of indices between them. 
Given the array, find the minimum distance between any pair of elements in the array. Is no such value exists, return -1.
*/

#include <iostream> 
#include <vector> 
#include <climits>
#include <map>
using namespace std; 

// Second version with map, O(f) = n
int minimumDistances(vector<int> a){
    int minDist = INT_MAX; 
    map<int,int> mapA; 

    for (int i=0; i<a.size(); i++){

        auto itr = mapA.find(a[i]);
        
        if (itr==mapA.end()){
            mapA.insert({a[i], i});
        } else {
            int dif = i - itr->second; 
            mapA[a[i]] = i; 
            if (dif < minDist) minDist = dif; 
        }
    }
    return minDist; 
}

// First version with nested for, O(f)=n^2
int minimumDistances2(vector<int> a) {
    int minDist = INT_MAX; 
    for (int i=0; i<a.size(); i++){
        for (int j=i; j<a.size(); j++){
            if (i!=j){
                if (a[i]==a[j]) {
                    if ((j-i) < minDist) minDist=j-i; 
                }
            }
        }
    }
    if (minDist == INT_MAX) return -1; 
    else return minDist; 
}

int main(){
    vector<int> dis {7,1,3,4,1,7};
    cout << minimumDistances(dis);

}