/* Source - https://leetcode.com/problems/count-different-palindromic-subsequences/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int countPalindromicSubsequences(string S) {
    int n = S.length();
    int left[n], right[n], index[4];
    
    memset(index, -1, sizeof(index));
    index[S[0] - 'a'] = 0;
    left[0] = -1;
    
    for(int i = 1; i < n; i++) {
        char ch = S[i] - 'a';
        
        if(index[ch] == -1)
            left[i] = -1;
        else
            left[i] = index[ch];
        
        index[ch] = i;
    }
    
    memset(index, -1, sizeof(index));
    index[S[n - 1] - 'a'] = n - 1;
    right[n - 1] = -1;
    
    for(int i = n - 2; i >= 0; i--) {
        char ch = S[i] - 'a';
        
        if(index[ch] == -1)
            right[i] = -1;
        else
            right[i] = index[ch];
        
        index[ch] = i;
    }
    
    int dp[n][n];
    
    memset(dp, 0, sizeof(dp));
    
    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(k == 0 || k == 1)
                dp[i][j] = k + 1;
            else if(S[i] == S[j]) {
                int l = right[i], r = left[j];
                                        
                if(l > r)
                    dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                else if(l == r)
                    dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                else
                    dp[i][j] = 2 * dp[i + 1][j - 1] - dp[l + 1][r - 1];
            } else
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            
            dp[i][j] = dp[i][j] < 0 ? dp[i][j] + M : dp[i][j] % M;
        }
    }
    
    return dp[0][n - 1];
}

int main()
{
    string S;

    cout<<"Enter a string: ";
    cin>>S;

    cout<<"Number of non-empty different subsequences of given string: "<<countPalindromicSubsequences(S)<<endl;
}