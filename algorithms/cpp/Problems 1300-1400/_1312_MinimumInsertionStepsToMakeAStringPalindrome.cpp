/* Source - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s) {
    int n = s.length();
    int lps[n][n];
    
    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(k == 0)
                lps[i][j] = 1;
            else if(k == 1)
                lps[i][j] = (s[i] == s[j]) ? 2 : 1;
            else 
                lps[i][j] = (s[i] == s[j]) ? 2 + lps[i + 1][j - 1] : max(lps[i][j - 1], lps[i + 1][j]);
        }
    }
    
    return n - lps[0][n - 1];
} 

int main()
{
    string s;

    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Min insertions to make "<<s<<" a palindrome: "<<minInsertions(s)<<endl;
}