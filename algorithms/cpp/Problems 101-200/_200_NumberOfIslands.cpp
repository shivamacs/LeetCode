/* Source - https://leetcode.com/problems/number-of-islands/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
void dfs(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = '0';
            
    for(int k = 0; k < dirs.size(); k++) {
        int x = i + dirs[k].first, y = j + dirs[k].second;
        
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1')
            dfs(grid, x, y);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == '1') {
                dfs(grid, i, j);
                islands++;
            }
        }
    }
    
    return islands;
}

int main()
{
    int n, m;
    
    cout<<"Enter grid dimensions: ";
    cin>>n>>m;

    vector<vector<char>> grid(n, vector<char> (m));

    cout<<"Enter values row-wise (1 - land, 0 - water): "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];
    }

    cout<<"Number of islands (4 - directionally): "<<numIslands(grid)<<endl;
}