/* Source - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0)
        return 0;
    
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

int main()
{
    int n;

    cout<<"Enter number of days: ";
    cin>>n;
    
    vector<int> prices(n);
    
    cout<<"Enter prices: ";
    for (int i = 0; i < n; i++)
        cin>>prices[i];
        
    cout<<"Maximum profit with infinite transaction allowed: "<<maxProfit(prices)<<endl;
}