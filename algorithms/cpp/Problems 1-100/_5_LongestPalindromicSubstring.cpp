/* Source - https://leetcode.com/problems/longest-palindromic-substring/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    
    if(n == 0)
        return "";
    
    bool dp[n][n];
    int si = 0, len = 0;
    
    memset(dp, false, sizeof(dp));
    
    for(int gap = 0; gap < n; gap++) {
        for(int i = 0, j = gap; j < n; i++, j++) {
            if(gap == 0)
                dp[i][j] = true;
            else if(gap == 1)    
                dp[i][j] = (s[i] == s[j]) ? true : false;
            else if(s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];

            if(dp[i][j]) {
                si = i;
                len = gap + 1;
            }
        }
    }
    
    return s.substr(si, len);
}

int main()
{
    string s;

    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Longest palindrome: "<<longestPalindrome(s)<<endl;
}