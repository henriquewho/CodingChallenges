/* https://app.codesignal.com/challenge/pRuhLib5DdetsY4E7
prices = array of prices, notes = array of price changes, x = amount
that the customer admits to 'overpay'
*/
#include <iostream> 
#include <vector> 
#include <string> 
#include <climits>
using namespace std; 

bool isAdmissibleOverpayment(vector<double> prices, vector<string> notes, double x) {
    double balance=0.0; 
    for (int i{}; i<notes.size(); i++){
        if (notes[i][0]!='S'){
            double value = prices[i];
            if (notes[i][notes[i].find("%")+2] == 'l') {
                value = (value*100) / (100 - (stod(notes[i].substr(0, notes[i].find("%")))));
            } else {
                value = (value*100) / (100 + (stod(notes[i].substr(0, notes[i].find("%")))));
            }
            balance += prices[i]-value; 
        }
    }
    return (balance>x) ? false : true; 
}

int main(){
    vector<double> prices {110, 95, 70}; 
    vector<string> notes {"10.0% higher than in-store", 
         "5.0% lower than in-store", 
         "Same as in-store"}; 
    double x = 5; 
    cout << "Result: " << isAdmissibleOverpayment(prices, notes, x);
}