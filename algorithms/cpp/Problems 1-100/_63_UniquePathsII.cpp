/* Source - https://leetcode.com/problems/unique-paths-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    long dp[m][n];
    
    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == m - 1 && j == n - 1) {
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : 1;
                continue;
            }
            
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }

            long paths = 0;

            if(j + 1 < n)
                paths += dp[i][j + 1];
            if(i + 1 < m)
                paths += dp[i + 1][j];

            dp[i][j] = paths;
        }
    }
    
    return dp[0][0];
}

int main()
{
    int m, n;

    cout<<"Enter grid dimensions: ";
    cin>>m>>n;

    vector<vector<int>> obstacleGrid(m, vector<int> (n));

    cout<<"Enter values in grid row-wise(0 - empty space, 1 - obstacle): "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin>>obstacleGrid[i][j];
    }

    cout<<"Count of unique paths from [0, 0] to ["<<m - 1<<", "<<n - 1<<"]: "<<uniquePathsWithObstacles(obstacleGrid)<<endl;
}