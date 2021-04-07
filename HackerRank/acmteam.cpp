/* https://www.hackerrank.com/challenges/acm-icpc-team/problem

task = given a list of topics known by each person, presented as binary strings, determine the maximum number of topis a 2-person team can know. 
Each subject has a column in the binary string (1 = know, 0 = dont know). Also determine the number of teams that know the maximum number of topics. 
Return an integer array with two elements: 
the first is the maximum number of topics known, the second is the number of teams that know that number of topics
*/

#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 

vector<int> acmTeam(vector<string> topic) {
    vector<int> res{-1, 0}; 
    int numTopics = topic[0].size(); 

    // For each string i, compare it with with each string j where j is after i, so the comparisions are like: 
    // 1 2, 1 3, 1 4, 1 6, 2 3, 2 4, 2 5, 3 4, 3 5, 4 5. In each comparison, then compare each of the k chars in the strings i and j. 
    for (int i=0; i<topic.size(); i++){
        for (int j=i+1; j<topic.size(); j++){
            int couple=0; 
            for (int k=0; k<numTopics; k++){
                if (topic[i][k]=='1' || topic[j][k]=='1'){
                    couple++; 
                }
            }
            // if the correspondence is equal to the biggest one yet, increase the number of possible doubles. 
            // If it is the maximum one yet, clear the number of possible couples and adjust the biggest counter
            if (couple==res[0]) res[1]++; 
            if (couple>res[0]) {
                res[0]=couple;
                res[1]=1; 
            }
        }
    }
    return res; 
}

int main(){
    vector<string> topic {"10101", "11100", "11010", "00101"};
    vector<string> topic2 {"000", "001", "110"};
    //vector<int> res = acmTeam(topic);
    vector<int> res = acmTeam(topic2);

    for (auto x: res) cout << x << " "; 
}