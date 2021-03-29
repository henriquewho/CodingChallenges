/* https://www.hackerrank.com/challenges/encryption/problem

First remove the spaces from the text, then L is the length of the text. 
Then chars are written into a grid, whose rows and columns are: 
floor(sqrt(L)) <= row <= columns <= ceil(sqrt(L)) 
The output sould be obtained displaying the chars from each column, with a space between columns texts.

The tricks of the algorithm are:
a) you'll need to adjust the 'matrix' of rows and cols if row*col<size
b) the formula to readjust the chars is (col * index of row)+index of column, where col is the number of columns. 
c) sometimes the rows*cols will be bigger than needed, so check it when putting the chars in the new string

*/

#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath>
using namespace std; 

// Complete the encryption function below.
string encryption(string s) {
    string res; 
    int L = s.size(), row = floor(sqrt(L)), col = ceil (sqrt(L));
    if (row*col < L){
        if (row<col) row++; else col++; 
    }
    for (int i=0; i<col; i++){
        for (int j=0; j<row; j++){
            int index = (col*j)+i; 
            if (index < s.size()) {
                res+=s[index];
            }
        }
        res+=' ';
    } 
    return res; 
}

int main(){

    string str1 = "ifmanwasmeanttostayonthegroundgodwouldhavegivenusroots";
    string str2 = "chillout"; 
    string str3 = "haveaniceday"; 
    string str4 = "feedthedog";
    string str5 = "roqfqeylxuyxjfyqterizzkhgvngapvudnztsxeprfp";

    cout <<  encryption(str1) << endl; 
    cout <<  encryption(str2) << endl; 
    cout <<  encryption(str3) << endl; 
    cout <<  encryption(str4) << endl; 
    cout <<  encryption(str5) << endl; 


    //int v = str2.size(); 
    //cout << v << " " << floor(sqrt(v)) << " " << ceil(sqrt(v)) << endl;
}