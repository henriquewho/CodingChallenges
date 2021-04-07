/* https://www.hackerrank.com/challenges/chocolate-feast/problem

n = money to spend
c = cost of chocolat
m = number of wrappers to buy a chocolat

If n=15, c=3, m=2
He can buy 5 chocolate bars, and now have 5 wrappers. 
With the 5 wrappers, we turn 4 into 2 chocolates.
Now he have 3 wrappers. He turns 2 into 1 chocolate. 
Now he has 2 wrappers, which he turns into one chocolate. 
Now he has 1 wrapper, and cant do anything. 
Overall, he ate 5 + 2 + 1 + 1 = 9 chocolates. 
Return the number of bars he can eat with the parameters passed. 


Solved it with recursion (not needed to)
The recursive function receives the initial number of wrappers and the cost of a chocolate in wrappers. 
Base cases: if number of wrappers < cost, cant buy more, return 0. 
if number of wrappers == cost, can buy 1, return 1. 
Recursive calls: for each iteration, the recursive call is updated passing the number of wrappers the boy has after trading. 
The value of the function is updated in +init/m, as the number of chocolate he could buy in each round/recursive call. 
*/

#include <iostream> 
#include <vector> 
#include <cmath>
using namespace std; 

int recChoc(int init, int m){
    if (init<m) return 0; 
    if (init==m) return 1; 
    int possib = init/m + init%m; 
    return recChoc(possib, m)+init/m;   
}
int chocolateFeast(int n, int c, int m) {
    int init = n/c; 
    int rest = recChoc(init, m); 
    return init+rest; 
}

// 'Formulatic' solution I found
// w is the initial number of chocolates bought. The function then returns the initial amount + initial amout / cost in wrappers + 1. You will always receive 1 wrapper back, thats why (m-1) is the cost. 
int chocolateFeastO1 (int n, int c, int m){
    int w = n/c; 
    return w + ceil(w / (m-1)); 
}

int main(){
    cout << chocolateFeast(4893, 37, 921) << endl;
    cout << chocolateFeastO1(4893, 37, 921) << endl;

    cout << chocolateFeast(41894, 36, 640) << endl;    
    cout << chocolateFeastO1(41894, 36, 640) << endl;    

    cout << chocolateFeast(60217, 144, 24) << endl;    
    cout << chocolateFeastO1(60217, 144, 24) << endl;   
}

