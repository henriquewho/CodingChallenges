/*https://app.codesignal.com/arcade/intro/level-9/6M57rMTFB9MeDeSWo
Given the positions of a white bishop and a black pawn in a chess board, 
determine wether the bichop can capture the pawn in one move. 
The bishop can only move to the 4 diagonals from its place. 
*/

#include <string> 
#include <iostream> 
#include <vector> 
using namespace std; 

// Logical Solution. If the difference between the positions and the 
// heights is the same, the pieces are in the same diagonal. 
// Ex: pawn at G1 and bishop at C5. G-C == 5-1, so return 1. 
bool bishopAndPawn(string bishop, string pawn) {
    int difPosition = abs(pawn[0]-bishop[0]);
    int difHeight = abs(pawn[1]-bishop[1]);
    int dif = difPosition - difHeight; 
    if (dif == 0) return true;
    return false; 
}


// Brute force solution, look for which direction to search and 
// then goes on until the end of the board.
bool bishopAndPawn2(string bishop, string pawn) {
    int pawnPos = (int)pawn[0], pawnHei = (int)pawn[1]; 
    int bisPos = (int)bishop[0], bisHei = (int)bishop[1]; 

    if (pawnPos > bisPos) {
        if (pawnHei > bisHei ){
            while (bisPos!=105 && bisHei!=57){
                bisPos++, bisHei++; 
                if (pawnPos==bisPos && pawnHei==bisHei) return 1; 
            }
        } else if (pawnHei < bisHei){
            while(bisPos!=105  && bisHei!=48 ){
                bisPos++, bisHei--; 
                if (pawnPos==bisPos && pawnHei==bisHei) return 1; 
            }
        }
    } else if (pawnPos < bisPos) {
        if (pawnHei > bisHei){
            while (bisPos!=96 && bisHei!=57){
                bisPos--, bisHei++; 
                if (pawnPos==bisPos && pawnHei==bisHei) return 1; 
            }
        } else if (pawnHei < bisHei){
            while (bisPos!=96 && bisHei!=48){
                bisPos--, bisHei--; 
                if (pawnPos==bisPos && pawnHei==bisHei) return 1; 
            }
        }
    }
    return 0;     
}

int main(){
    string bishop, pawn; 
    cin >> bishop >> pawn; 
    bool res = bishopAndPawn(bishop, pawn);
    cout << "Result: " << res; 
}