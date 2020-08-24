/* Source - https://leetcode.com/problems/cherry-pickup/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int pickMaxCherries(int r1, int c1, int r2, vector<vector<int>>& grid, int N, int ***dp) {
    int c2 = r1 + c1 - r2;
    
    if(r1 >= N || c1 >= N || r2 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        return INT_MIN;
    
    if(dp[r1][c1][r2] != -1)
        return dp[r1][c1][r2];
    
    if(r1 == N - 1 && c1 == N - 1)
        return grid[r1][c1];
    
    if(r2 == N - 1 && c2 == N - 1)
        return grid[r2][c2];
    
    int answer = 0;
    
    if(r1 == r2 && c1 == c2)
        answer += grid[r1][c1];
    else 
        answer += grid[r1][c1] + grid[r2][c2];
    
    int hh = pickMaxCherries(r1, c1 + 1, r2, grid, N,  dp);
    int vv = pickMaxCherries(r1 + 1, c1, r2 + 1, grid, N, dp);
    int hv = pickMaxCherries(r1, c1 + 1, r2 + 1, grid, N, dp);
    int vh = pickMaxCherries(r1 + 1, c1, r2, grid, N, dp);
    
    answer += max(max(hh, vv), max(hv, vh));
            
    dp[r1][c1][r2] = answer;
    
    return answer;
}

int cherryPickup(vector<vector<int>>& grid) {
    int N = grid.size();
    int ***dp;
    
    dp = new int**[N];
    for(int i = 0; i < N; i++) {
        dp[i] = new int*[N];
        
        for(int j = 0; j < N; j++) {
            dp[i][j] = new int[N];
            
            for(int k = 0; k < N; k++)
                dp[i][j][k] = -1;
        }
    }
            
    int answer = pickMaxCherries(0, 0, 0, grid, N, dp);
    
    return (answer < 0) ? 0 : answer;
}

int main()
{
    int n;

    cout<<"Enter the value of N (for dimensions of matrix): ";
    cin>>n;

    vector<vector<int>> grid(n, vector<int> (n));

    cout<<"Enter values in the matrix row-wise (0 -> Empty cell, 1 -> Cell contains cherry, -1 -> Cell contains thorn): "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin>>grid[i][j];
    }

    cout<<"Maximum number of cherries collected from [0, 0] to ["<<n - 1<<", "<<n - 1<<"] and ["<<n - 1<<", "<<n - 1<<"] to [0, 0]: "<<cherryPickup(grid)<<endl;

}