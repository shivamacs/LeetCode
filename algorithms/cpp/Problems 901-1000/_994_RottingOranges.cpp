/* Source - https://leetcode.com/problems/rotting-oranges/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Element {
    int x, y, time;
    
    Element(int a, int b, int t) {
        x = a;
        y = b;
        time = t;
    }
};

int orangesRotting(vector<vector<int>>& grid) {
    queue<Element> q;
    int count1 = 0;
    
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1)
                count1++;
            
            if(grid[i][j] == 2)
                q.push(Element(i, j, 0));
        }
    }
    
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int visited = 0, minTime = 0;
    
    while(!q.empty()) {
        Element front = q.front();
        q.pop();
        
        for(int i = 0; i < dirs.size(); i++) {
            int x = front.x + dirs[i].first;
            int y = front.y + dirs[i].second;
            
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1) {
                grid[x][y] = 2;
                q.push(Element(x, y, front.time + 1));
                visited++;
            }
        }
        
        if(q.empty())
            minTime = front.time;
    }
    
    return (visited == count1) ? minTime : -1;
}

int main()
{
    int n, m;

    cout<<"Enter grid dimensions: ";
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int> (m));

    cout<<"Enter values row-wise (0 - empty cell, 1 - fresh orange, 2 - rotten orange): "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];
    }

    cout<<"Minimum number of minutes that must elapse until no cell has fresh orange: "<<orangesRotting(grid)<<endl;
}