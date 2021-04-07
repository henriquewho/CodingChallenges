/* https://www.hackerrank.com/challenges/sherlock-and-squares/problem

task = determine the number of square integers (x =y*y) between a and b, included. 
*/

#include <iostream> 
#include <vector> 
#include <cmath> 
#include <fstream> 
#include <string> 
using namespace std; 

// Complete the squares function below.
// a = x*x and b = y*y. So I need to determine how many numbers are between x and y!
int squares(int a, int b) {
    auto sq_b = sqrt(b); auto sq_a = sqrt(a); 
    if (  (floor(sq_b)==floor(sq_a)) && (fmod(sq_a,1))  )  return 0; 
    int between = floor(sq_b) - floor(sq_a);
    if ( !fmod(sq_a,1) ) {
        between++; 
    }
    return between; 
}

int main(){

    std::string myText; 
    std::ifstream MyFile("file.txt");
    while (std::getline(MyFile, myText)){
        int a, b; 
        MyFile >> a >> b; 
        //cout << squares(a,b); cout << endl; 
    }

    cout << squares(4,4);
}