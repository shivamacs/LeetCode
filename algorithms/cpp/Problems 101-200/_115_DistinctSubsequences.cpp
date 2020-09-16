/* Source - https://leetcode.com/problems/distinct-subsequences/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    long dp[n + 1][m + 1];
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i < j) {
                dp[i][j] = 0;
                continue;
            }
            
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }
            
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[n][m];
}

int main()
{
    string s, t;

    cout<<"Enter string S: ";
    cin>>s;

    cout<<"Enter string T; ";
    cin>>t;

    cout<<"Count of distinct subsequences of "<<t<<" in "<<s<<": "<<numDistinct(s, t)<<endl;
}