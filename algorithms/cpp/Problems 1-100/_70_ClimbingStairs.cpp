/* Source - https://leetcode.com/problems/climbing-stairs/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[n] = 1;
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= 2 && i + j <= n; j++)
            dp[i] += dp[i + j];
    }
    
    return dp[0];
}

int main()
{
    int n;

    cout<<"Enter Number of stairs: ";
    cin>>n;

    cout<<"Number of distinct ways to climb to the top: "<<climbStairs(n)<<endl;
}