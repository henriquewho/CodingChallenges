/* https://app.codesignal.com/arcade/intro/level-4/xYXfzQmnhBvEKJwXP

Two arrays are similar if one can be obtained from another by swapping at most 
one pair of elements in one of the arrays. Check if a and b are similar. 
*/

#include <iostream>
#include <vector> 
using namespace std; 

// In diff we push the 'different' elements. To meet the conditions, 
// diff must have 4 elements in in two pairs. Otherwise it's impossible
// to make them equal with only one swap. 
bool areSimilar(vector<int> a, vector<int> b) {
    int size = a.size(); 
    vector<int> diff; 
    for (int i{}; i<size; i++){
        if (a[i]!=b[i]){
            diff.push_back(a[i]); 
            diff.push_back(b[i]);
            if (diff.size()>4) return false; 
        }
    }
    if (diff.size()==0) return true;
    else if (diff.size()<4) return false; 
    else {
        if (diff[0]==diff[3] && diff[1]==diff[2]) return true; 
        else return false; 
    }
}
int main(){
    vector<int> a {1,2,3} , b {1,2,3};
    cout << "Result: " << areSimilar(a,b);
}

