/* Source - https://leetcode.com/problems/palindromic-substrings/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    if (s.length() == 0)
        return 0;
    
    int n = s.length();

    vector<vector<bool>> dp(n, vector<bool> (n));
    int count = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0, j = i + k; i < n, j < n; i++, j++) {
            if (k == 0)
                dp[i][j] = true;

            else if (k == 1) {
                if (s[i] == s[j])
                    dp[i][j] = true;

                else dp[i][j] = false;
            }

            else {
                if (s[i] == s[j])
                    dp[i][j] = (dp[i + 1][j - 1] == true) ? true : false;

                else dp[i][j] = false;
            }

            if (dp[i][j] == true)
                count++;
        }
    }

    return count;
}

int main()
{
    string s;

    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Number of palindromic substrings: "<<countSubstrings(s)<<endl;
}