/* Source - https://leetcode.com/problems/island-perimeter/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n = grid.size();
    int m = n == 0 ? 0 : grid[0].size();

    int perimeter = 0;
    
    for (int i = 0; i < n; i++) {            
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                perimeter += 4;
                
                for (int p = 0; p < directions.size(); p++) {
                    int row = i + directions[p][0];
                    int col = j + directions[p][1];
                    
                    if (row >= 0 && row < n && col >= 0 && col < m)
                        if (grid[row][col] == 1) perimeter -= 1; 
                }
            }
        }
    }
    
    return perimeter;
}

int main()
{
    int n, m;

    cout<<"Enter number of grid rows and columns: ";
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        cout<<"Enter values in the grid for row "<<i + 1<<": ";
        for (int j = 0; j < m; j++)
            cin>>grid[i][j];
    }

    cout<<"Perimeter of the island formed: "<<islandPerimeter(grid)<<endl;
}