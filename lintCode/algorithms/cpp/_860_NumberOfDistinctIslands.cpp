/* Leetcode Premium -> 694. Number of Distinct Islands
   Lintcode -> 860. Number of Distinct Islands
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int x, int y, string d, string& path) {
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
        return;
    
    if(grid[x][y] == 2) {
        path += "B";
        return;
    }
    
    grid[x][y] = 2;
    path += d;
    
    dfs(grid, x, y + 1, "R", path);
    dfs(grid, x + 1, y, "D", path);
    dfs(grid, x, y - 1, "L", path);
    dfs(grid, x - 1, y, "U", path);
} 

int numberofDistinctIslands(vector<vector<int>> &grid) {
    int islands = 0;
    string path = "";
    unordered_set<string> distinct;
    
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1) {
                path = "X";
                dfs(grid, i, j, "", path);

                if(distinct.find(path) == distinct.end()) {
                    distinct.insert(path);   
                    islands++;
                }                    
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

    vector<vector<int>> grid(n, vector<int> (m));

    cout<<"Enter values row-wise (0 - water, 1 - land): "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];
    }

    cout<<"Number of distinct islands: "<<numberofDistinctIslands(grid)<<endl;
}