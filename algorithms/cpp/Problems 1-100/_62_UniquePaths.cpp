/* Source - https://leetcode.com/problems/unique-paths/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    int dp[n][m];
    
    memset(dp, 0, sizeof(dp));
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(i == n - 1 && j == m - 1) {
                dp[i][j] = 1;
                continue;
            }

            int paths = 0;

            if(j + 1 < m)
                paths += dp[i][j + 1];
            if(i + 1 < n)
                paths += dp[i + 1][j];

            dp[i][j] = paths;
        }
    }
    
    return dp[0][0];
}

int main()
{
    int n, m;

    cout<<"Enter grid dimensions: ";
    cin>>n>>m;

    cout<<"Count of unique paths from [0, 0] to ["<<n - 1<<", "<<m - 1<<"]: "<<uniquePaths(n, m)<<endl;
}