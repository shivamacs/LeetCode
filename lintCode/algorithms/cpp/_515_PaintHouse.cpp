/* Source - https://www.lintcode.com/problem/paint-house/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

 int minCost(vector<vector<int>> &costs) {
    if (costs.empty())
        return 0;
        
    int n = costs.size();

    int minCost = 0, red = costs[0][0], blue = costs[0][1], green = costs[0][2];
    
    for (int i = 1; i < n; i++) {
        int j = 0, rtemp = red, btemp = blue, gtemp = green;
        
        red = costs[i][j++] + min(btemp, gtemp);
        blue = costs[i][j++] + min(rtemp, gtemp);
        green = costs[i][j++] + min(rtemp, btemp);
    }
    
    return min(red, min(blue, green));
}

int main()
{
    int n;

    cout<<"Enter number of houses: ";
    cin>>n;
    
    vector<vector<int>> costs(n, vector<int> (3));
    
    cout<<"Enter costs row-wise: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin>>costs[i][j];
    }
    
    cout<<"Minimum cost to paint the houses with 3 colors such that no two consecutive houses have same color: "<<minCost(costs)<<endl;
}