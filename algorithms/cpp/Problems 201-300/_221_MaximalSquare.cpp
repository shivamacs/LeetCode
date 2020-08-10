/* Source - https://leetcode.com/problems/maximal-square/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    
    int m = matrix.size(), n = matrix[0].size();
    int dp[m][n];
    int maxSize = 0;
    
    memset(dp, 0, sizeof(dp));
    
    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == m - 1 || j == n - 1)
                dp[i][j] = matrix[i][j] - '0';
            else if(matrix[i][j] == '1')
                dp[i][j] = min(min(dp[i][j + 1], dp[i + 1][j]), dp[i + 1][j + 1]) + 1;
                            
            maxSize = max(maxSize, dp[i][j]);
        }
    }
    
    return maxSize * maxSize;
}

int main()
{
    int m, n;

    cout<<"Enter dimensions of matrix: ";
    cin>>m>>n;
    
    vector<vector<char>> matrix(m, vector<char> (n));
        
    cout<<"Enter values in the matrix row-wise (0 or 1): "<<endl; 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin>>matrix[i][j];
    }
    
    cout<<"Maximum size square sub-matrix: "<<maximalSquare(matrix)<<endl;
}