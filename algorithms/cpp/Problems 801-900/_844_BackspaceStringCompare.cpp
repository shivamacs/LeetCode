/* Source - https://leetcode.com/problems/backspace-string-compare/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare (string S, string T) {
    int i = S.length() - 1, j = T.length() - 1, count1 = 0, count2 = 0;    
    
    while(i >= 0 || j >= 0) {
        while(i >= 0) {
            if(S[i] == '#') {
                count1++;
                i--;
            } else if(count1 > 0) {
                count1--;
                i--;
            } else
                break;
        }
        
        while(j >= 0) {
            if(T[j] == '#') {
                count2++;
                j--;
            } else if(count2 > 0) {
                count2--;
                j--;
            } else
                break;
        }
                    
        if((i < 0 && j >= 0) || (i >= 0 && j < 0))
            return false;
            
        if(i >= 0 && j >= 0 && S[i] != T[j])
            return false;
        
        i--;
        j--;
    }
    
    return true;
}

int main()
{
    string S, T;

    cout<<"Enter expression 1: ";
    cin>>S;

    cout<<"Enter expression 2: ";
    cin>>T;

    cout<<"Are given strings equal after backspace compare? "<<boolalpha<<backspaceCompare(S, T)<<endl;
}