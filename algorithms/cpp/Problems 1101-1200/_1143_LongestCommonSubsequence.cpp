/* Source - https://leetcode.com/problems/longest-common-subsequence/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    if (text1.length() == 0 || text2.length() == 0)
        return 0;
    
    int n = text1.length(), m = text2.length();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n || j == m)
                dp[i][j] = 0;

            else if (text1[i] == text2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];

            else dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }

    return dp[0][0];
}

int main()
{
    string text1, text2;

    cout<<"Enter string 1: ";
    cin>>text1;
    
    cout<<"Enter string 2: ";
    cin>>text2;
    
    cout<<"Length of longest common Subsequence: "<<longestCommonSubsequence(text1, text2)<<endl;
}