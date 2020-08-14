/* Source - https://leetcode.com/problems/coloring-a-border/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int xDir[4] = {1, 0, -1, 0};
int yDir[4] = {0, 1, 0, -1};

void dfs(int r, int c, vector<vector<int>>& grid, bool **visited, int color) {
    visited[r][c] = true;
    
    int same = 0;
    
    for(int k = 0; k < 4; k++) {
        int i = r + xDir[k], j = c + yDir[k];
            
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            continue;
        
        if(visited[i][j]) {
            same++;
            continue;
        }
                        
        if(grid[i][j] == grid[r][c]) {
            dfs(i, j, grid, visited, color);
            same++;
        }
    }
    
    if(same < 4)
        grid[r][c] = color;
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    bool **visited;
    visited = new bool*[grid.size()];
    
    for(int i = 0; i < grid.size(); i++) {
        visited[i] = new bool[grid[0].size()];
        
        for(int j = 0; j < grid[0].size(); j++)
            visited[i][j] = false;
    }
    
    dfs(r0, c0, grid, visited, color);
    
    return grid;
}

int main()
{
    int n, m;

    cout<<"Enter the dimensions of the grid: ";
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int> (m));

    cout<<"Enter color values in the grid row-wise: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];
    }

    int r0, c0;

    cout<<"Enter a location (row, column): ";
    cin>>r0>>c0;

    int color;

    cout<<"Enter the value of color: ";
    cin>>color;

    vector<vector<int>> result = colorBorder(grid, r0, c0, color);

    cout<<"Updated grid: "<<endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}