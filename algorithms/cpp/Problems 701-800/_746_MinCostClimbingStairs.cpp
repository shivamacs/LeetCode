/* Source - https://leetcode.com/problems/min-cost-climbing-stairs/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1);
            
    dp[n] = 0;
                    
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        
        for (int j = 1; j <= 2 && i + j <= n; j++) {
            if (dp[i + j] + cost[i] < minCost)
                minCost = dp[i + j] + cost[i];
        }
                    
        dp[i] = minCost;
    }
    
    return min(dp[0], dp[1]);
}

int main()
{
    int n;
    
    cout<<"Enter number of steps: ";
    cin>>n;

    vector<int> cost(n);

    cout<<"Enter costs: ";
    for (int i = 0; i < n; i++)
        cin>>cost[i];

    cout<<"Minimum cost to reach the top: "<<minCostClimbingStairs(cost)<<endl;
}