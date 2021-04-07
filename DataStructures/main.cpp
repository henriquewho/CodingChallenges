#include <iostream> 
#include <vector> 
#include "LList.h"
using namespace std; 

void testLList(){
    List<int> a;

    cout << "Pushing Front, enter a number: "; 
    int num; cin>>num; 
    a.push_front(num);

    cout << "Return front: " << a.front() << endl;

    cout << "Pushing Back, enter a number: "; 
    cin >> num; 
    a.push_back(num); 

    cout << "Return back: " << a.back() << endl; 

    cout << "Size: " << a.size() << endl; 
}

void printLList(){
    List<int> a; 

    cout << "Enter 5 numbers: "; 
    for (int i{}; i<5; i++){
        int num;
        cin >> num; 
        a.push_back(num); 
    }

    a.pop_front(); a.pop_back(); 

    cout << "Printing: "; a.print(); 

    cout << "Is empty? " << a.isEmpty() << endl; 

    while (a.isEmpty()!=1 ) { a.pop_front(); }

    cout << "Is empty? " << a.isEmpty() << endl; 

}

int main(){
    //testLList();
    printLList(); 
}
