/* https://app.codesignal.com/arcade/intro/level-3/9DgaPsE2a7M6M2Hu6

Write a function that reverse chars between parentheses in the input string. There'll be nested parentheses.
*/

#include <iostream>
#include <string> 
#include <algorithm>
#include <stack> 
using namespace std; 

// Only passes one time in the string, O(N). Uses a stack to stack the '(' chars. If a ')' is found, reverse from the last '(' and then has to do i-=2 to account for the two chars removed. Used the built in reverse() from <algorithm> for simplicity but could have implemented it as well.
string reverseInParentheses(string inputString) {
    stack<int> stack;
    for (int i{}; i<inputString.size(); i++){
        if ( inputString[i] == '(') {
            stack.push(i);
        } else if (inputString[i] == ')') {
            reverse(inputString.begin()+stack.top()+1, inputString.begin()+i);
            inputString.replace(stack.top(),1,"");
            inputString.replace(i-1,1,"");
            stack.pop(); 
            i-=2; 
        }
    }
    return inputString; 
}


int main(){
    string str1 = "foo(bar(baz))blim"; // foobazrabblim
    string str2="foo(bar)baz(blim)";  // foorabbazmilb
    string str3="tes(te(oi))teste"; // tesoietteste

    cout << "Result: " << reverseInParentheses(str1); 
}
