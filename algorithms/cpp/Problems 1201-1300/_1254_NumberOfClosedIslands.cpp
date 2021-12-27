/* Source - https://leetcode.com/problems/number-of-closed-islands/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};

bool dfs(int sr, int sc, vector< vector<int> >& grid) {
    grid[sr][sc] = 1;
    
    if(sr == 0 || sc == 0 || sr == grid.size() - 1 || sc == grid[0].size() - 1)
        return false;
    
    int falseCount = 0;
    
    for(int d = 0; d < 4; d++) {
        int a = sr + x[d];
        int b = sc + y[d];
        
        if(grid[a][b] == 1)
            continue;
        
        bool result = dfs(a, b, grid);
        
        if(result == false)
            falseCount++;
    }
    
    return falseCount == 0;
}

int number_of_closed_islands(vector< vector<int> >& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int result = 0;
    
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            if(grid[i][j] == 0)
                result += dfs(i, j, grid) ? 1 : 0;
        }
    }
    
    return result;
}

int main()
{
    int n, m;

    cout<<"Enter dimensions of the grid: ";
    cin>>n>>m;

    vector< vector<int> > grid(n, vector<int> (m));

    cout<<"Enter the values in the grid (1 - water, 0 - land) row-wise: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];
    }

    cout<<"Number of closed islands: "<<number_of_closed_islands(grid)<<endl;
}