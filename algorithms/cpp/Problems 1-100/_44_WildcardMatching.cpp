/* Source - https://leetcode.com/problems/wildcard-matching/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int sl = s.length(), pl = p.length();
    bool dp[pl + 1][sl + 1];
    
    dp[0][0] = true;
    
    for(int i = 1; i <= pl; i++)
        dp[i][0] = (p[i - 1] == '*') ? dp[i - 1][0] : false;
        
    for(int j = 1; j <= sl; j++)
        dp[0][j] = false;
    
    for(int i = 1; i <= pl; i++) {
        for(int j = 1; j <= sl; j++) {
            if(p[i - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else if(p[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = (p[i - 1] == s[j - 1]) && dp[i - 1][j - 1];
        }
    }
            
    return dp[pl][sl];
}

int main()
{
    string s, p;

    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Enter pattern: ";
    cin>>p;

    cout<<"String matches the pattern? "<<boolalpha<<isMatch(s, p)<<endl;
}
