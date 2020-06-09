/* Source - https://leetcode.com/problems/regions-cut-by-slashes/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int dsFind(int i, vector<int>& parent) {
    if(parent[i] == i)
        return i;
    
    int result = dsFind(parent[i], parent);
    parent[i] = result;
    
    return result;
}

void dsUnion(int x, int y, vector<int>& parent, vector<int>& rank, int& regions) {
    int px = dsFind(x, parent);
    int py = dsFind(y, parent);
    
    if(px != py) {
        if(rank[px] > rank[py])
            parent[py] = px;
        else if(rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    } else
        regions++;
}

// approach 1
int regionsBySlashesUsingDSU(vector<string>& grid) {
    int n = grid.size() + 1;
    
    vector<int> parent(n * n, -1), rank(n * n, 1);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                int p = (i * n) + j;
                
                if(parent[p] == -1) { 
                    parent[p] = 0;
                    rank[p] = 1;
                }
            }
        }
    }
    
    int regions = 1;
    
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid.size(); j++) {
            int p1, p2;
        
            if(grid[i][j] == '/') {
                p1 = ((i + 1) * n) + j;
                p2 = (i * n) + (j + 1);
            } else if(grid[i][j] == '\\') {
                p1 = (i * n) + j;
                p2 = ((i + 1) * n) + (j + 1);
            } else
                continue;
    
            if(parent[p1] == -1) {
                parent[p1] = p1;
                rank[p1] = 1;
            } 

            if(parent[p2] == -1) {
                parent[p2] = p2;
                rank[p2] = 1;
            }
                
            dsUnion(p1, p2, parent, rank, regions);
        }
    }
                        
    return regions;
}

int xDir[4] = {0, 1, 0, -1};
    int yDir[4] = {1, 0, -1, 0};
    
void dfs(vector<vector<int>>& matrix, int x, int y) {
    matrix[x][y] = 1;
    
    for(int i = 0; i < 4; i++) {
        int a = x + xDir[i], b = y + yDir[i];
        
        if(a >= 0 && a < matrix.size() && b >= 0 && b < matrix.size() && matrix[a][b] == 0)
            dfs(matrix, a, b);
    }
}

// approach 2
int regionsBySlashesUsingDFS(vector<string>& grid) {
    int n = grid.size();
    vector<vector<int>> matrix(3 * n, vector<int> (3 * n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x = i * 3, y = j * 3;
            
            if(grid[i][j] == '/') {
                matrix[x][y + 2] = 1;
                matrix[x + 1][y + 1] = 1;
                matrix[x + 2][y] = 1;
            } else if(grid[i][j] == '\\') {
                matrix[x][y] = 1;
                matrix[x + 1][y + 1] = 1;
                matrix[x + 2][y + 2] = 1;
            }
        }
    }
                            
    int regions = 0;
                        
    for(int i = 0; i < 3 * n; i++) {
        for(int j = 0; j < 3 * n; j++) {
            if(matrix[i][j] == 0) {
                dfs(matrix, i, j);
                regions++;
            }
        }
    }
                        
    return regions;
}

int main()
{
    int N;

    cout<<"Enter grid size: ";
    cin>>N;

    vector<string> grid(N);

    cout<<"Enter string for each row('_' for white-space, no need of escaped backslash ('\')): "<<endl;
    for(int i = 0; i < N; i++)
        cin>>grid[i];

    cout<<"Number of regions cut by slashes (using DSU approach): "<<regionsBySlashesUsingDSU(grid)<<endl;
    cout<<"Number of regions cut by slashes (using DFS approach): "<<regionsBySlashesUsingDFS(grid)<<endl;
}