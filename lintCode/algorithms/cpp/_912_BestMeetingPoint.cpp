/* Source - https://www.lintcode.com/problem/best-meeting-point/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minTotalDistance(vector<vector<int>> &grid) {
    vector<int> x, y;
    int n = grid.size();
    int m = n == 0 ? 0 : grid[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1)
                x.push_back(i);
        }
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 1)
                y.push_back(j);
        }
    }
    
    int xMedian = x[x.size() / 2], yMedian = y[y.size() / 2];
    int totalDistance = 0;
    
    for (int i = 0; i < x.size(); i++)
        totalDistance += abs(x[i] - xMedian) + abs(y[i] - yMedian);

    return totalDistance;
}

int main()
{
    int n, m;

    cout<<"Enter number of rows and columns: ";
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int> (m));

    cout<<"Enter elements: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin>>grid[i][j];
    }

    cout<<"Total Manhattan distance travelled to reach best meeting point: "<<minTotalDistance(grid)<<endl;
}