/* https://app.codesignal.com/arcade/intro/level-9/xHvruDnQCx7mYom3T
Given speed of growth and decreasing by day, determine how many days 
it'll take for a plant to grow to the desired height.
*/

#include <iostream> 
using namespace std; 

int growingPlant(int upSpeed, int downSpeed, int desiredHeight) {
    
    int current = upSpeed;
    int days = 1; 

    // If the plant is already at the desired height in the first 'half day', 
    // no calculation is needed and the program skips the while loop
    while (current<desiredHeight){
        days++; 
        current-=downSpeed; 
        current+=upSpeed; 
        if (current >= desiredHeight) {
            return days; 
        }
    }

    return days; 
}

int main(){
    cout << "Result: " << growingPlant(6,5,10);
}