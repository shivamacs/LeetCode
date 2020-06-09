/* Source - https://leetcode.com/problems/number-of-enclaves/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
void dfs(vector<vector<int>>& A, int x, int y) {
    A[x][y] = 0;
    
    for(int i = 0; i < dirs.size(); i++) {
        int a = x + dirs[i].first, b = y + dirs[i].second;
        
        if(a >= 0 && a < A.size() && b >= 0 && b < A[0].size() && A[a][b] == 1)
            dfs(A, a, b);
    }
}

int numEnclaves(vector<vector<int>>& A) {
    int n = A.size(), m = (n == 0) ? 0 : A[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && A[i][j] == 1)
                dfs(A, i, j);
        }
    }
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 1)
                count++;
        }
    }
    
    return count;
}

int main()
{
    int n, m;

    cout<<"Enter grid dimensions: ";
    cin>>n>>m;

    vector<vector<int>> A(n, vector<int> (m));

    cout<<"Enter values row-wise (0 - sea, 1 - land): "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin>>A[i][j];
    }

    cout<<"Number of land squares for which we cannot walk off the boundary: "<<numEnclaves(A)<<endl;
}