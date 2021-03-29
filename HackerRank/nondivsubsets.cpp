/* https://www.hackerrank.com/challenges/non-divisible-subset/problem?h_r=next-challenge&h_v=zen

Given a set of distinct integers, print the size of a maximal subset S, where the sum of any 2 numbers in the subset is not evenly divisible by k.

S = [19,10,12,10,24,25,22]   k = 4   return 3 

If theres a n with n%k==0, add 1 number to the subset. More than one will cause (n+m)%k==0.
For loop will run k/2 times, as from the first half (index i) I'll access the second half (index k-i). Elements of restos[i] and restos[k-i] can't coexist in the subset, as for example k=4. i=1 and k-i = 4-1=3; element from restos[1]+restos[3] will generate an element which is divisible by 4. Select the biggest subgroup between those two. 

if k is pair, then elements n and m where n and m%k = k/2 summed up: (n+m)%k==0; So, the subset can contain only one of them. 
If it's not the situation above, add the biggest subgroup between i and k-i.

*/

#include <iostream> 
#include <vector> 
using namespace std;  

// template function = any iterable Object is accepted
template <typename Object> 
void printV (const Object a){
    for (auto x: a) cout << x << " ";
    cout << endl; 
}

int nonDivisibleSubset(int k, vector<int> s) {
    int result=0; 
    vector<int> restos(k, 0); 

    for (int i=0; i<s.size(); i++){
        int index = s[i]%k; 
        restos[index] = restos[index] + 1;
    } //printV(restos);

    if (restos[0]>0) result++; 

    for (int i=1; i<=k/2; i++){
        int tmp = (restos[k-i] > restos[i]) ? restos[k-i] : restos[i]; cout << tmp << " ";

        if (k%2==0 && i == k/2 && restos[i]>0) result = result+1; 
        else result = result+tmp; 
    }

    return result; 
    
}

int main(){
    //vector<int> set {19,10,12,24,25,22};
    //int k = 4;

    vector<int> set {278, 576, 496, 727, 410, 124, 338, 149, 209, 702, 282, 718, 771,575, 436};
    int k = 7; 
    cout << "Result: " << nonDivisibleSubset(k, set);
}