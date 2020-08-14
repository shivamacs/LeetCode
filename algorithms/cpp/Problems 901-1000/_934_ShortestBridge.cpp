/* Source - https://leetcode.com/problems/shortest-bridge/
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

void dfs(int r, int c, vector<vector<int>>& A, queue<Element>& q) {
    A[r][c] = 2;
    q.push(Element(r, c, 0));
    
    for(int k = 0; k < 4; k++) {
        int i = r + xDir[k], j = c + yDir[k];
        
        if(i < 0 || i >= A.size() || j < 0 || j >= A.size() || A[i][j] != 1)
            continue;
        
        dfs(i, j, A, q);
    }
}

int shortestBridge(vector<vector<int>>& A) {
    int n = A.size();
    queue<Element> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 1) {
                dfs(i, j, A, q);
                goto bfs;
            }         
        }
    }
    
    bfs:
    while(!q.empty()) {
        Element front = q.front();
        q.pop();
        
        int r = front.x, c = front.y, flips = front.d;
                
        for(int k = 0; k < 4; k++) {
            int i = r + xDir[k], j = c + yDir[k];
            
            if(i < 0 || i >= n || j < 0 || j >= n || A[i][j] == 2)
                continue;
                
            if(A[i][j] == 1)
                return flips;
            
            A[i][j] = 2;
            q.push(Element(i, j, flips + 1));
        }
    }
    
    return 0;
}

int main()
{
    int n;

    cout<<"Enter value of n (for array dimensions): ";
    cin>>n;

    vector<vector<int>> A(n, vector<int> (n));

    cout<<"Enter values in array row-wise (0 or 1): "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin>>A[i][j];
    }

    cout<<"Smallest number of 0s to be flipped to connect the two islands: "<<shortestBridge(A)<<endl;
}