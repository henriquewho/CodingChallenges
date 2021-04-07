/* https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem

c[n] = array of clouds. 
e = energy level = 100
k = length of one jump

The char starts from c[0] and uses 1 unit of energy to make a jump of size k to cloud c[ (i+k)%n ]. 
If it lands on a thundercloud, c[i] = 1, it's energy decreases by 2 additional units. The game ends when the char lands back on cloud 0.
Determine the final value of e after the game ends. 
*/

#include <iostream> 
#include <vector> 

using namespace std; 

// my version
int jumpingOnClouds(vector<int> c, int k) {
    int energy = 100; 
    int position=0, thunder=0; 

    while (energy > 0){
        position = (position+k)%c.size(); 
        if (c[position]==1) thunder =2; else thunder =0; 
        energy = energy - 1 - thunder;
        if (position==0) return energy;
    }
    return energy; 
}

// other version
int jumpingOnClouds2(vector<int> c, int k) {
    int energy=100; 
    int position = k % c.size(); 
    energy = energy - 1 - c[position]*2; 

    while (position!=0){
        position = (position+k) % c.size(); 
        energy = energy - 1 - c[position]*2; 
    }

    return energy; 
}

int main(){
    vector<int> c {0,0,1,0,0,1,1,0}; 
    int k=2;
    cout << jumpingOnClouds2(c,k);
}