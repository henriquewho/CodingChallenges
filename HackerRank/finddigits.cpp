/* https://www.hackerrank.com/challenges/find-digits/problem?h_r=next-challenge&h_v=zen

d is a divisor of n if n%d = 0; 
GIven a integer, for each digit tha makes up the integer determine whether it is a divisor. 
Ex: 124. 1, 2 and 4 are divisors of 124, so return 3.

string st(n, char) = the string constructor can fill the string with n times char! Very useful to convert from char to string. 

Other info = you dont need to do string = stringstream.str(), you can just do  ss >> string.

*/

#include <iostream> 
#include <vector> 
#include <sstream>
#include <string> 

using namespace std; 

// Complete the findDigits function below.
int findDigits(int n) {
    string s =""; 
    stringstream ss(s); 
    ss << n; ss >> s;
    
    int count=0; 
    for (int i=0; i<s.size(); i++) {
        string dig(1,s[i]);
        int digit = stoi(dig);
        if ( (digit!=0)&&(n%digit==0) )  count++;
    }
    return count; 
}

// other version without strings
int findDigits2(int n){
    int count = 0, originalN = n; 

    while (n>0){

        int rest = n%10, mod=-99; 
        n = n /10;
        
        if ( (rest!=0) && (originalN%rest==0) ) {
            count++; 
        }
    }
    return count; 

}


int main(){
    cout << findDigits(10124);
    cout << endl; 
    cout << findDigits2(10124);
}