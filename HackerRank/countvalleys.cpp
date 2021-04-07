/* https://www.hackerrank.com/challenges/counting-valleys/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

U = uphill, D = downhill

*/

#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

int countingValleys(int steps, string path) {
    int level=0, count=0; 
    for (int i=0; i<path.size(); i++) {
        if ( ( level==0 ) && path[i]=='D') {
            count++; 
        }

        if (path[i] == 'U') {
            level++;
        } else { 
            level--; 
        }
    }
    return count; 
}

int main(){
    
    cout << countingValleys(8, "UDDDUDUU");
    return 0;
}