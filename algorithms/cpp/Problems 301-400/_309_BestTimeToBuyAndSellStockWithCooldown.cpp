/* Source - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0)
        return 0;
    
    int rest = 0, buy = prices[0], sell = 0;

    for (int i = 1; i < prices.size(); i++) {
        int temp = buy;

        buy = min(buy, prices[i] - rest);
        rest = max(rest, sell);
        sell = max(sell, prices[i] - temp);
    }

    return sell;
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
        
    cout<<"Maximum profit with cooldown and infinite transactions allowed: "<<maxProfit(prices)<<endl;
}