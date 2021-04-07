/* https://www.hackerrank.com/challenges/designer-pdf-viewer/problem

There is a list of 26 char heights aligned by index to their letters. 'a' index is 0 and 'z' index is 25. 
There will also be a string.
Determine the area of the rectangle hightligh in mm2 assuming all letters are 1 mm wide. 
*/

#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    vector<int> lettersValues; 
    int biggest=0; 
    for (int i=0; i<word.size(); i++){
        int letterNumber = (int)word[i]-97;
        if (h[letterNumber]>biggest) biggest = h[letterNumber];
    }
    return biggest*word.size();
}

int main(){
    vector<int> h {1, 3, 1, 3, 1 ,4 ,1 ,3, 2 ,5, 5 ,5 ,5 ,5 ,5, 5 ,5, 5, 5, 5, 5, 5, 5, 5 ,5, 7}; 
    string word = "zaba"; 
    cout << designerPdfViewer(h, word);
}