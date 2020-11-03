/* Source - https://leetcode.com/problems/palindrome-partitioning-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minCut(string s) {
    int n = s.length();
    bool pre[n][n];
    memset(pre, false, sizeof(pre));
    
    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(k == 0)
                pre[i][j] = true;
            else if(k == 1)
                pre[i][j] = s[i] == s[j];
            else if(s[i] == s[j])
                pre[i][j] = pre[i + 1][j - 1];
        }
    }
    
    if(pre[0][n - 1])
        return 0;
    
    int dp[n];
    
    for(int i = 0; i < n; i++) {
        if(pre[0][i])
            dp[i] = 0;
        else {
            dp[i] = INT_MAX;
            
            for(int j = i; j > 0; j--) {
                if(pre[j][i])
                    dp[i] = min(dp[i], 1 + dp[j - 1]);
            }
        }
    }
    
    return dp[n - 1];
}

int main()
{
    string s;

    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Minimum cuts in the string such that each part is a palindrome: "<<minCut(s)<<endl;
}