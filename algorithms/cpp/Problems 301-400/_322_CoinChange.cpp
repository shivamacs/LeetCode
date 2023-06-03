/* Source - https://leetcode.com/problems/coin-change/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    
    dp[0] = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= amount; j++) {
            if(dp[j - coins[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{
    int n;
    cout<<"Enter number of coins: ";
    cin>>n;

    vector<int> coins(n);
    cout<<"Enter the denominations: ";
    for(int i = 0; i < n; i++)
        cin>>coins[i];
    
    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;

    cout<<"Minimum number of denominations to represent the given amount: "<<coinChange(coins, amount)<<endl;
}