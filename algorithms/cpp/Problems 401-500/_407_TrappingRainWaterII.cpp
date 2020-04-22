/* Source - https://leetcode.com/problems/trapping-rain-water-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Position {
    int x;
    int y;
    
    Position (int a = 0, int b = 0) {
        x = a;
        y = b;
    }
};

class Height {
    public:
        int h;
        Position position;
    
        Height(int p = -1, int a = -1, int b = -1) {
            h = p;
            position.x = a;
            position.y = b;
        }
    
        bool operator<(const Height& h1) const {
            return h > h1.h;
        }
};

int trappedRainWaterInMatrix(vector<vector<int>>& heightMap) {
    priority_queue<Height> minHeap;
    Height top;
    
    int m = heightMap.size();
    int n = heightMap.size() == 0 ? 0 : heightMap[0].size();
    
    vector<vector<bool>> visited(m, vector<bool> (n, 0));
    
    int water = 0;
    
    for (int i = 0; i < n; i++) {
        minHeap.push(Height(heightMap[0][i], 0, i));
        visited[0][i] = 1;
        
        minHeap.push(Height(heightMap[m - 1][i], m - 1, i));
        visited[m - 1][i] = 1;
    }
    
    for (int j = 1; j < m - 1; j++) {
        minHeap.push(Height(heightMap[j][0], j, 0));
        visited[j][0] = 1;
        
        minHeap.push(Height(heightMap[j][n - 1], j, n - 1));
        visited[j][n - 1] = 1;
    }
        
    while (!minHeap.empty()) {
        top = minHeap.top();
        minHeap.pop();
                    
        int x = top.position.x, y = top.position.y;            
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int p = 0; p < 4; p++) {
            int row = x + d[p][0];
            int col = y + d[p][1];
            
            if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                Height next(heightMap[row][col], row, col);
                
                if (next.h < top.h) {
                    water += top.h - next.h;                                                
                    next.h = max(next.h, top.h);
                }

                minHeap.push(next);
                visited[row][col] = 1;
            }   
        }
    }
    
    return water;
}

int main()
{
    int m, n;
    
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> heightMap(m, vector<int> (n));
    int a;

    for (int i = 0; i < m; i++) {
        cout<<"Enter heights for row "<<i + 1<<": ";
        for (int j = 0; j < n; j++)
            cin>>heightMap[i][j];
    }

    cout<<"Units of water that can be trapped in the matrix: "<<trappedRainWaterInMatrix(heightMap)<<endl;
}