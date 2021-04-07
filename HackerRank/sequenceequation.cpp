/* https://www.hackerrank.com/challenges/permutation-equation/problem

Given a sequence of n integers p(1), p(2), .. p(n), where each element is distinct and satisfies 1<= p(x) <= n.
For each x where 1<= x <= n, fina any integer y such that p(p(y)) = x and print the value of y on a new line.
Ex: p = [5,2,1,3,4]. Each value of x between 1 and 5, the length of the sequence, is: 

First line to push: x =1. The element 1 is found at the p[3], or third element of p. 
3 is in the p[4]. You should push 4.
*/

#include <iostream> 
#include <vector> 
#include <map>

using namespace std; 

vector<int> permutationEquationDirect(vector<int> p){
    vector<int> res; 
    p.insert(p.begin(), -99);

    for (int i=1; i<p.size(); i++)
        res.push_back(p[p[i]]);
    return res; 
}

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
    vector<int> res;
    map<int, int>  valuekey; 

    for (int i=0; i<p.size(); i++){
        valuekey.insert({p[i], i+1});
    }
    for (int i=1; i<=p.size(); i++){
        auto itr = valuekey.find(i);
        auto itr2 = valuekey.find(itr->second);
        res.push_back(itr2->second);
    }
    return res; 
}

int main(){

    vector<int> p {5,2,1,3,4};
    p = permutationEquation(p); 
    for (int x: p) cout << x << " ";
    cout<<endl; 

    vector<int> p2 {5,2,1,3,4};
    p2 = permutationEquationDirect(p2);
    for (int x: p2) cout << x << " ";

}