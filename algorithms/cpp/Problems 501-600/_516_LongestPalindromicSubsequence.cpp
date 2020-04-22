/* Source - https://leetcode.com/problems/longest-palindromic-subsequence/
   Author - Shivam Arora
*/      
#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(string s) {
    if (s.length() == 0)
        return 0;
    
    int n = s.length();

    vector<vector<int>> dp(n, vector<int> (n));

    for (int k = 0; k < n; k++) {
        for (int i = 0, j = i + k; i < n, j < n; i++, j++) {
            if (k == 0)
                dp[i][j] = 1;

            else if (k == 1) {
                if (s[i] == s[j])
                    dp[i][j] = 2;

                else dp[i][j] = 1;
            }

            else {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];

                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    string s;
    
    cout<<"Enter a string: ";
    cin>>s;
    
    cout<<"Longest palindromic subsequence in the given string: "<<longestPalindromeSubseq(s)<<endl;
}