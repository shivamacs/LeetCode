/* Source - https://leetcode.com/problems/fraction-to-recurring-decimal/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    if (prices.size() == 0)
        return 0;
    
    int n = prices.size();
    
    if (k >= n / 2) {
        int bp = 0, sp = 0, profit = 0;

        for(int i = 1; i < prices.size(); i++){
            if (prices[i] < prices[i - 1]) {
                profit += prices[sp] - prices[bp];
                bp = sp = i;
            } 

            else sp++;
        }

        profit += prices[sp] - prices[bp];

        return profit;
    }

    vector<vector<int>> dp(k + 1, vector<int> (n, 0));

    /* kn2 approach
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            int mxWithC = 0;
            
            for (int l = 0; l < j; l++)
                mxWithC = max(mxWithC, prices[j] - prices[l] + dp[i - 1][l]);
                
            dp[i][j] = max(dp[i][j - 1], mxWithC);
        }
    }
    */
    
    // kn approach
    for (int i = 1; i <= k; i++) {
        int dpDiff = INT_MIN;

        for (int j = 1; j < n; j++) {
            dpDiff = max(dpDiff, dp[i - 1][j - 1] - prices[j - 1]);

            dp[i][j] = max(dp[i][j - 1], prices[j] + dpDiff);
        }
    }

    return dp[k][n - 1];
}

int main()
{
    int n, k;

    cout<<"Enter number of days: ";
    cin>>n;

    cout<<"Enter number of transactions allowed: ";
    cin>>k;
    
    vector<int> prices(n);
    
    cout<<"Enter prices: ";
    for (int i = 0; i < n; i++)
        cin>>prices[i];
        
    cout<<"Maximum profit with "<<k<<" transactions allowed: "<<maxProfit(k, prices)<<endl;
}