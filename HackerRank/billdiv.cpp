/* https://www.hackerrank.com/challenges/bon-appetit/problem

Determine if Anna and Brian calculation is correct. Ex: 
bill = [2,4,6]. Anna declines to eat item k = bill[2] = 6, so Brian calculates that Anna should pay (2+4)/2 = 3. 
If he includes the cost of bill[2], then he will calculate (2+4+6)/2=6, in which case he'll have to return 3 to Anna.

*/
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std; 

// Complete the bonAppetit function below.
void bonAppetit(vector<int> bill, int k, int b) {
    int sum=0;
    for (int i=0; i<bill.size(); i++){
        if (i!=k){
            sum+=bill[i];
        }
    }
    int totalAnna = sum/2; 
    if (totalAnna == b){
        cout << "Bon Appetit" << endl;
    } else {
        cout << b-totalAnna << endl; 
    }
}

int main() { 
    vector<int> bill;
    int n=0, k=0; 
    cin >> n >> k; 
    for (int i=0; i<n; i++){
        int item=0; cin >> item; 
        bill.push_back(item);
    }
    int moneyAnna; cin >> moneyAnna; 
    bonAppetit(bill, k, moneyAnna);
    return 0;
}