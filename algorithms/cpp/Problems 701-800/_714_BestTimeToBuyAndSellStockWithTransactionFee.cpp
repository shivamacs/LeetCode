/* Source - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    if (prices.size() == 0)
        return 0;
    
    int bp = prices[0], sp = 0;

    for (int i = 1; i < prices.size(); i++) {
        int temp = bp;
        bp = min(bp, prices[i] - sp);
        sp = max(sp, prices[i] - temp - fee);
    }

    return sp;
}

int main()
{
    int n;

    cout<<"Enter number of days: ";
    cin>>n;
    
    vector<int> prices(n);
    
    cout<<"Enter prices: ";
    for (int i = 0; i < n; i++)
        cin>>prices[i];
        
    int fee;

    cout<<"Enter transaction fee: ";
    cin>>fee;
        
    cout<<"Maximum profit with transaction fee and infinite transactions allowed: "<<maxProfit(prices, fee)<<endl;
}