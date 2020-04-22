/* Source - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0)
        return 0;
    
    int n = prices.size();

    int minsf = INT_MAX, maxsf = INT_MIN;
    vector<int> ps(n), pb(n);

    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        if (prices[i] < minsf)
            minsf = prices[i];

        if (prices[j] > maxsf)
            maxsf = prices[j];

        ps[i] = (i == 0) ? prices[i] - minsf : max(ps[i - 1], prices[i] - minsf);
        pb[j] = (j == n - 1) ? maxsf - prices[j] : max(pb[j + 1], maxsf - prices[j]);
    }

    int ttaprofit = 0;

    for (int i = 0; i < n; i++)
        ttaprofit = max(ttaprofit, ps[i] + pb[i]);    

    return ttaprofit;
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
        
    cout<<"Maximum profit with atmost two transactions allowed: "<<maxProfit(prices)<<endl;
}