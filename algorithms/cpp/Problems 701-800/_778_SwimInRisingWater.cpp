/* Source - https://leetcode.com/problems/swim-in-rising-water/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

class Elevation {
    public:
        int val, x, y;
        
        Elevation(int a = -1, int b = -1, int c = -1) {
            val = a;
            x = b;
            y = c;
        }
        
        bool operator<(const Elevation& e1) const {
            return val > e1.val;
        }
};
    
int swimInWater(vector<vector<int>>& grid) {
    priority_queue<Elevation> minHeap;
    
    int N = grid.size();
    vector<vector<bool>> visited(N, vector<bool> (N));
    Elevation top;
    int eMax = 0;
    
    minHeap.push(Elevation(grid[0][0], 0, 0));
    visited[0][0] = 1;
    
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while(!minHeap.empty()) {
        top = minHeap.top();
        minHeap.pop();
        
        eMax = max(eMax, top.val);
        
        if (top.x == N - 1 && top.y == N - 1) break;
        
        for (int p = 0; p < directions.size(); p++) {
            int row = top.x + directions[p][0];
            int col = top.y + directions[p][1];
            
            if (row < N && row >= 0 && col < N && col >= 0 && !visited[row][col]) {
                minHeap.push(Elevation(grid[row][col], row, col));
                visited[row][col] = 1;
            }
        }
    }
    
    return eMax;
}

int main() {
    int N;

    cout<<"Enter the value of N: ";
    cin>>N;

    vector<vector<int>> grid(N, vector<int> (N));

    cout<<"Enter elevations: "<<endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin>>grid[i][j];

    cout<<"Least time to reach the bottom square: "<<swimInWater(grid)<<endl;
}