/* https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

Given n containers, determine if is possible to order the elements: 
- there are n kinds of balls, divided in n containers
- [x1, x2, x3...] is a container, with x1 balls of type 1, x2 of type 2 and so on
- all moves should be swaps of a ball from a container for other of other container
n = number of containers and types of ball goes from 1 to 100
*/

#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm>
using namespace std; 

/* Solution: The set of container has to be 'sortable' via direct swaps. 
With x containers, we'll have x types of balls. As some containers have more balls than others, return 'Possible' if there's a relationship between the 'capacity' (initial number of balls in it) of each container and the number of each ball. Example: 
- Capacity of the containers: 2, 3, 7, 4
- Quantity of each ball:      7, 3, 4, 2
If all containers had the same amount of balls, checking if the quantity of balls are equal would suffice. 
*/

string organizingContainers(vector<vector<int>> container) {
    string res = "Possible"; 
    int n = container[0].size(); 
    if (n==1) return res; 

    // vector with the number of types of balls
    vector<int> countBalls(container[0].size()+1);    
    vector<int> countCont(countBalls.size());

    for (int i=0; i<container.size(); i++){     // for each container
        for (int j=0; j<container[0].size(); j++){  // for each type of ball in each container
            countBalls[j+1] += container[i][j];
            countCont[i+1] += container[i][j];
        }
    }

    sort(countBalls.begin()+1, countBalls.end());
    sort(countCont.begin()+1, countCont.end());

    for (int i=1; i<countBalls.size(); i++){
        if (countBalls[i]!=countCont[i]) res = "Impossible";
        return res;
    } 
    return res; 
}


int main(){
    vector<vector<int>> container2 {{1,4}, {2,3}};
    vector<vector<int>> container { {0,2,1}, {1,1,1}, {2,0,0} };
    vector<vector<int>> container3 {{0,2}, {1,1}};
    cout << "Result: " << organizingContainers(container);
}