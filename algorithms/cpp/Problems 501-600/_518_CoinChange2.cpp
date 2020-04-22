/* Source - https://leetcode.com/problems/coin-change-2/
   Author - Shivam Arora
*/
/* GeeksForGeeks -> Coin Change
   Leetcode -> 518. Coin Change 2
   Pep -> Coin Change Combination
*/

#include <bits/stdc++.h>
using namespace std;

int coinChangeCombination(vector<int>& arr, int amt) {
    int n = arr.size();
    vector<int> dp(amt + 1, 0);
    
    dp[0] = 1;
    
    for (int k = 0; k < n; k++) {
        for (int i = arr[k]; i <= amt; i++)
            dp[i] += dp[i - arr[k]];
    }
    
    return dp[amt];
}

int main()
{
    int n;

    cout<<"Enter number of coins: ";
    cin>>n;
    
    vector<int> arr(n);
    
    cout<<"Enter denominations: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];
        
    int amt;

    cout<<"Enter amount: ";
    cin>>amt;
        
    cout<<"Number of combinations of coins to pay the amount: "<<coinChangeCombination(arr, amt)<<endl;
}