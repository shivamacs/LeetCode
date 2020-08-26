#include <bits/stdc++.h>
using namespace std;

bool isScramble(string s1, string s2) {
    int n = s1.length();
    bool dp[n + 1][n][n];
            
    memset(dp, false, sizeof(dp));
            
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            for(int j = 0; j <= n - len; j++) {
                if(len == 1)
                    dp[len][i][j] = (s1[i] == s2[j]);
                else {                        
                    for(int cut = 1; cut < len && !dp[len][i][j]; cut++) {
                        dp[len][i][j] = (dp[cut][i][j] && dp[len - cut][i + cut][j + cut])
                                        || (dp[cut][i][j + len - cut] && dp[len - cut][i + cut][j]);
                    }
                }
            }
        }
    }
    
    return dp[n][0][0];
}

int main()
{
    string s1, s2;

    cout<<"Enter string 1: ";
    cin>>s1;

    cout<<"Enter string 2: ";
    cin>>s2;

    cout<<"Is "<<s2<<" a scramble string of "<<s1<<"?: "<<boolalpha<<isScramble(s1, s2)<<endl;
}