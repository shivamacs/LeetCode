/* Source - https://www.lintcode.com/problem/paint-house-ii/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minCostII(vector<vector<int>> &costs) {
    if (costs.size() == 0)
        return 0;
        
    int n = costs.size();
    int k = (n == 0) ? 0 : costs[0].size();
    
    vector<int> dp(k);
    
    int firstmin, secondmin;
    
    for (int i = 0; i < n; i++) {
        int prefmin = (i == 0) ? 0 : firstmin, presmin = (i == 0) ? 0 : secondmin;
        firstmin = INT_MAX, secondmin = INT_MAX;
        
        for (int j = 0; j < k; j++) {
            if (dp[j] != prefmin || prefmin == presmin)
                dp[j] = costs[i][j] + prefmin;
                
            else dp[j] = costs[i][j] + presmin;
                    
            if (firstmin <= dp[j])
                secondmin = min(secondmin, dp[j]);
                
            else {
                secondmin = firstmin;
                firstmin = dp[j];
            }
        }
    }
    
    return firstmin;
}

int main()
{
    int n, k;

    cout<<"Enter number of houses: ";
    cin>>n;
    
    cout<<"Enter number of colors: ";
    cin>>k;
    
    vector<vector<int>> costs(n, vector<int> (k));
    
    cout<<"Enter costs row-wise: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cin>>costs[i][j];
    }
    
    cout<<"Minimum cost to paint the houses with k colors such that no two consecutive houses have same color: "<<minCostII(costs)<<endl;
}