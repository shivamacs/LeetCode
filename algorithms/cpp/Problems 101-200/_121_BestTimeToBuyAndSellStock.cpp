/* Source - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minsf = INT_MAX, maxDiff = 0;
    
    for (int i = 0; i < prices.size(); i++) {
        minsf = min(minsf, prices[i]);
        maxDiff = max(maxDiff, prices[i] - minsf);
    }
    
    return maxDiff;
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
        
    cout<<"Maximum profit with atmost one transaction allowed: "<<maxProfit(prices)<<endl;
}