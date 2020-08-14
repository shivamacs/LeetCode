/* Source - https://leetcode.com/problems/as-far-from-land-as-possible/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

 struct Element {
    int x, y, d;
    
    Element(int a = -1, int b = -1, int c = -1) {
        x = a;
        y = b;
        d = c;
    }
};

int xDir[4] = {1, 0, -1, 0};
int yDir[4] = {0, 1, 0, -1};

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<Element> q;
    int maxDist = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1)
                q.push(Element(i, j, 0));
        }
    }
    
    while(!q.empty()) {
        Element front = q.front();
        q.pop();
        
        maxDist = max(maxDist, front.d);
                    
        for(int i = 0; i < 4; i++) {
            int r = front.x + xDir[i], c = front.y + yDir[i];
            
            if(r < 0 || r >= n || c < 0 || c >= n)
                continue;
            
            if(grid[r][c] == 0) {
                grid[r][c] = 1;
                q.push(Element(r, c, front.d + 1));
            }
        }
    }
    
    return maxDist == 0 ? -1 : maxDist;
}

int main()
{
    int n;

    cout<<"Enter the value of N (for grid dimensions): ";
    cin>>n;

    vector<vector<int>> grid(n, vector<int> (n));

    cout<<"Enter values in the grid row-wise (0 represents water, 1 represents land): "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin>>grid[i][j];
    }

    cout<<"Maximised Manhattan distance: "<<maxDistance(grid)<<endl;
}