/* Source - https://leetcode.com/problems/brick-wall/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> edges;
    int x, maxEdges = 0;
    
    for (int i = 0; i < wall.size(); i++) {
        x = 0;
        
        for (int j = 0; j < wall[i].size() - 1; j++) {
            x += wall[i][j];
            edges[x]++;
            
            if (edges[x] > maxEdges) maxEdges = edges[x];
        }
    }
    
    return wall.size() - maxEdges;
}

int main()
{
    int n, k, a;

    cout<<"Enter height of the wall: ";
    cin>>n;

    vector<vector<int>> wall(n);

    for (int i = 0; i < n; i++) {
        cout<<"Enter number of bricks in the current row: ";
        cin>>k;

        cout<<"Enter brick widths in the current row: ";
        for (int j = 0; j < k; j++) {
            cin>>a;
            wall[i].push_back(a);
        }
    }

    cout<<"Least number of bricks crossed: "<<leastBricks(wall)<<endl;
}