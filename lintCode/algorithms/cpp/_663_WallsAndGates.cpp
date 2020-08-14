/* Source - https://www.lintcode.com/problem/walls-and-gates/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

 struct Element {
    int x, y;
    
    Element(int a, int b) {
        x = a;
        y = b;
    }
};

int xDir[4] = {1, 0, -1, 0};
int yDir[4] = {0, 1, 0, -1};

void wallsAndGates(vector<vector<int>> &rooms) {
    int m = rooms.size(), n = rooms[0].size();
    queue<Element> q;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(rooms[i][j] == 0)
                q.push(Element(i, j));
        }
    }
    
    while(!q.empty()) {
        Element front = q.front();
        q.pop();
        
        int r = front.x, c = front.y;
        
        for(int k = 0; k < 4; k++) {
            int i = r + xDir[k], j = c + yDir[k];
            
            if(i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] != INT_MAX)
                continue;
                
            rooms[i][j] = rooms[r][c] + 1;
            q.push(Element(i, j));
        }
    }
}

int main()
{
    int m, n;

    cout<<"Enter dimensions of grid: ";
    cin>>m>>n;

    vector<vector<int>> rooms(m, vector<int> (n));

    cout<<"Enter values in grid (-1 - A wall or an obstacle, 0 - A gate, 2147483647(INT_MAX) - empty room): "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin>>rooms[i][j];
    }

    wallsAndGates(rooms);

    cout<<"Updated grid: "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout<<rooms[i][j]<<" ";
        cout<<endl;
    }
}