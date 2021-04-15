/* https://app.codesignal.com/arcade/intro/level-10/TXFLopNcCNbJLQivP
FInd the domain part of an email address. 
*/

#include <iostream> 
#include <string> 
using namespace std; 

/* Find the first @ from the right and returns what comes after it */
string findEmailDomain(string address) {
    int index=0; 
    for (int i=address.size()-1; i>=0; i--){
        if (address[i]=='@') {
            index=i; 
            break; 
        }
    }
    return address.substr(index+1, address.size());
}

int main(){
    string str  = "\"very.unusual.@.unusual.com\"@usual.com";
    cout << "Result: " << findEmailDomain(str); 
}