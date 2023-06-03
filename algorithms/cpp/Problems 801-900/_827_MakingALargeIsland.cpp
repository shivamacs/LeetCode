/*  Source - https://leetcode.com/problems/making-a-large-island/
    Author - Shivam Arora
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int xDir[4] = {0, 1, 0, -1};
int yDir[4] = {1, 0, -1, 0};

int dfs(int sr, int sc, int n, std::vector<std::vector<int>>& grid, int index) {
    grid[sr][sc] = index;
    int count = 1;

    for(int d = 0; d < 4; d++) {
        int x = sr + xDir[d];
        int y = sr + yDir[d];

        if(x < 0 || x == n || y < 0 || y == n || grid[x][y] != 1)
            continue;

        count += dfs(x, y, n, grid, index); 
    }

    return count;
}

int largestIsland(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    std::unordered_map<int, int> area;
    int index = 2;
    int maxArea = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                area[index] = dfs(i, j, n, grid, index);
                maxArea = std::max(maxArea, area[index++]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                int result = 1;
                std::unordered_set<int> visitedArea;

                for(int d = 0; d < 4; d++) {
                    int x = i + xDir[d];
                    int y = j + yDir[d];

                    if(x < 0 || x == n || y < 0 || y == n)
                        continue;

                    int index = grid[x][y];

                    if(visitedArea.find(index) == visitedArea.end()) {
                        visitedArea.insert(index);
                        result += area[index];
                    }
                }

                maxArea = std::max(maxArea, result);
            }
        }
    }

    return maxArea;
}

int main() {
    int n;

    std::cout<<"Enter the value of n to define size of grid: ";
    std::cin>>n;

    std::vector<std::vector<int>> grid(n, std::vector<int>(n));

    std::cout<<"Enter the binary values in the grid: "<<std::endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            std::cin>>grid[i][j];
    }

    std::cout<<"Size of largest island after changing atmost one zero to one: "<<largestIsland(grid)<<std::endl;
}