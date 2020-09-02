/* Source - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string S) {
    int n = S.length(), oc = 0, cc = 0;
        
    for(int i = 0; i < n; i++) {
        if(S[i] == '(')
            oc++;
        else if(oc > 0)
            oc--;
        else
            cc++;
    } 
    
    return oc + cc;
}

int main()
{
    string S;
    cout<<"Enter parentheses expression: ";
    cin>>S;

    int result = minAddToMakeValid(S);
    cout<<"Minimum number of parentheses to be added to make the expression valid: "<<result<<endl;
}