/* Source - https://leetcode.com/problems/minimum-path-sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = m == 0 ? 0 : grid[0].size();

    vector<vector<int>> dp(m, vector<int> (n));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1)
                dp[i][j] = grid[i][j];

            else if (i == m - 1)
                dp[i][j] = grid[i][j] + dp[i][j + 1];

            else if (j == n - 1)
                dp[i][j] = grid[i][j] + dp[i + 1][j];

            else dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
        }
    }

    return dp[0][0];
}

int main()
{
    int m, n;

    cout<<"Enter dimensions of the grid: ";
    cin>>m>>n;
    
    vector<vector<int>> grid(m, vector<int> (n));
    
    cout<<"Enter values  rowwise: "<<endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin>>grid[i][j];
    }
    
    cout<<"Minimum path sum: "<<minPathSum(grid)<<endl;
}