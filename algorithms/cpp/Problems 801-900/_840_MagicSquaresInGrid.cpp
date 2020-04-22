/* Source - https://leetcode.com/problems/magic-squares-in-grid/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

#define SUM 15
#define MIDDLE 5

bool checkRowSum(vector<vector<int>>& grid, int i, int j) {
    for (int x = i; x < i + 3; x++) {
        int rowSum = 0;
        
        for (int y = j; y < j + 3; y++)
            rowSum += grid[x][y];
    
        if (rowSum != SUM)
            return false;
    }
    
    return true;
}

bool checkColSum(vector<vector<int>>& grid, int i, int j) {
    for (int y = j; y < j + 3; y++) {
        int colSum = 0;
        
        for (int x = i; x < i + 3; x++)
            colSum += grid[x][y];
        
        if (colSum != SUM)
            return false;
    }
    
    return true;
}

bool checkDiagSum(vector<vector<int>>& grid, int i, int j) {
    if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != SUM)
        return false;
    
    if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != SUM)
        return false;
    
    return true;
}

bool checkOneToNine(vector<vector<int>>& grid, int i, int j) {
    unordered_set<int> unique;
    
    for (int x = i; x < i + 3; x++) {
        for (int y = j; y < j + 3; y++) {
            if (grid[x][y] < 1 || grid[x][y] > 9 || unique.find(grid[x][y]) != unique.end())
                return false;
        
            unique.insert(grid[x][y]);
        }    
    }
    
    return true;
}

bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
    if (grid[i + 1][j + 1] != MIDDLE)
        return false;
    
    if (checkRowSum(grid, i, j) && checkColSum(grid, i, j) && checkDiagSum(grid, i, j) && checkOneToNine(grid, i, j))
        return true;
    
    return false;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    if (m * n < 9)
        return 0;

    int count = 0;

    for (int i = 0; i <= m - 3; i++) {
        for (int j = 0; j <= n - 3; j++)
            if (isMagicSquare(grid, i, j))
                count++;
    }
    
    return count;
}

int main() {
    int m, n;

    cout<<"Enter grid row size: ";
    cin>>m;

    cout<<"Enter grid column size: ";
    cin>>n;

    vector<vector<int>> grid(m, vector<int> (n));

    cout<<"Enter grid elements: "<<endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin>>grid[i][j];
    }

    cout<<"Number of magic squares in the grid: "<<numMagicSquaresInside(grid)<<endl;
}