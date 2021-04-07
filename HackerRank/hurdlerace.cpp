/* https://www.hackerrank.com/challenges/the-hurdle-race/problem

Hurdles are of varying heights, and the chars have a maximum height they can jump.
If they take a potion, the chars can increase they height by 1 unit for each dose. How many doses of the potion must the character take to be able to jump all of the hurdles?
If the char doesn't need any potion, return 0. 
*/

#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

// Complete the hurdleRace function below.
int hurdleRace(int k, vector<int> height) {
    int biggestDif=0; 
    for (int i=0; i<height.size(); i++){
        if ( (height[i]>k) && (height[i]-k>biggestDif))  
            biggestDif = height[i]-k; 
    }
    return biggestDif; 
}

int main(){
    int k=4; vector<int> hei {1,6,3,5,2}; 
    cout << hurdleRace(k, hei);
}