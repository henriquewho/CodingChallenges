/*  https://www.hackerrank.com/challenges/lisa-workbook/problem


n = number of chapters in the book, from 1 to n
The i-th chapter has arr[i] problems, numbered from 1 to arr[i]
k = number of problems a page can hold. Only a chapter's last page of exercises may contain <= k problems. 
Each new chapter starts on a new page, so a page will never contain problems from more than one chapter. Each Page number indexing starts at 1. Count the number of special problems.

Solution: Run a for loop through the chapters in arr. 
For each chapter, we'll put problems (prob) in pages until there are no more problems. 
int first and last are the first and last problems in a page. 
The first element in each page is 1, 1+k, 1+k*2, ... 
The last element in each page is first + k-1 if the problems fill the page, or first + the rest of the problems (prob%k-1) otherwise. 
Each page can have one or zero special problem. A page has a special problem if its number is between first and last.
*/

#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 

int workbook(int n, int k, vector<int> arr) {
    int pagecounter=0, special=0; 
    for (int i=0; i<arr.size(); i++){
        int prob = arr[i], first=1;
        int last = (prob<k) ? first+prob%k-1: first+k-1;

        while (prob>0){  
            pagecounter++; 
            if (pagecounter>=first && pagecounter<=last) special++; 
            prob-=k; 
            first = first +k; 
            last = (prob<k) ? first+prob%k-1: first+k-1;
        }
    }
    return special; 
}

int main(){
    vector<int> arr {3, 8, 15, 11, 14, 1, 9, 2, 24, 31};
    int n=2, k=5; 
    int res = workbook(n, k, arr);

    cout << endl << "special problems: " << res; 
}