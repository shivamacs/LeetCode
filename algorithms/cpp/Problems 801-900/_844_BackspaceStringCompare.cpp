/* Source - https://leetcode.com/problems/backspace-string-compare/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

bool backspaceStringCompare (string exp1, string exp2) {
    int count1 = 0, count2 = 0, i = exp1.length() - 1, j = exp2.length() - 1;
    
    while (i>=0 || j>=0) {
        while (i >= 0) {
            if (exp1[i] == '#') {i--; count1++;}
            else if (count1 > 0) {count1--; i--;} 
            else break;
        }
        
        while (j >= 0) {
            if (exp2[j] == '#') {count2++; j--;}
            else if (count2 > 0) {count2--; j--;} 
            else break;
        }

        if (i >= 0 && j >= 0 && exp1[i] != exp2[j]) return false;
        if ((i >= 0) != (j >= 0)) return false;
        i--; 
        j--;
    }
    return true;
}

int main()
{
    string exp1, exp2;
    cout<<"Enter expression 1: ";
    getline(cin, exp1);
    cout<<"Enter expression 2: ";
    getline(cin, exp2);

    if (backspaceStringCompare(exp1, exp2)) cout<<"True";
    else cout<<"False";
    cout<<endl; 
}