/* Source - https://leetcode.com/problems/edit-distance/
   Author - Shivam Arora
*/ 
#include <bits/stdc++.h>
using namespace std;

int minEdits(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    int dp[m + 1][n + 1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string word1, word2;

    cout<<"Enter string 1: ";
    cin>>word1;
    cout<<"Enter string 2: ";
    cin>>word2;

    cout<<"Minimum number of edits to modify "<<word1<<" to "<<word2<<": "<<minEdits(word1, word2)<<endl;
}