/* https://app.codesignal.com/arcade/intro/level-10/8RiRRM3yvbuAd3MNg
Given a list of votes received by candidates and the number of missing votes, 
determine how many candidates can win the election alone
*/

#include <vector> 
#include <iostream> 
#include <algorithm>
using namespace std; 

/* Sorts the list to make it easier to detect that there's 
no winner in case k=0. Then just checks the values with +k.
*/
int electionsWinners(vector<int> votes, int k) {
    sort(votes.begin(), votes.end());
    int biggest = votes[votes.size()-1], possible =1;
    for (int i=votes.size()-2; i>=0; i--){
        if (votes[i] == biggest && k==0) return 0; 
        else if (votes[i]+k > biggest) possible++; 
    }
    return possible; 
}

int main(){
    int nCand, k; 
    vector<int> votes; 
    cin >> nCand >> k; 
    for (int i{}; i<nCand; i++) {
        int vote; cin >> vote; 
        votes.push_back(vote);
    }
    cout << "Result: " << electionsWinners(votes, k);
}

