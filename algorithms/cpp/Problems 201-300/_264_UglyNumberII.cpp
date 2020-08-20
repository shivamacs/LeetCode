/* Source - https://leetcode.com/problems/ugly-number-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {
    int p2 = 0, p3 = 0, p5 = 0;
    int dp[n];
    
    dp[0] = 1;
    
    for(int i = 1; i < n; i++) {
        int c1 = dp[p2] * 2, c2 = dp[p3] * 3, c3 = dp[p5] * 5;
        
        dp[i] = min(c1, min(c2, c3));
        
        if(dp[i] == c1)
            p2++;
        
        if(dp[i] == c2)
            p3++;
        
        if(dp[i] == c3)
            p5++;
    }
    
    return dp[n - 1];
}

int main()
{
    int n;

    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"nth ugly number: "<<nthUglyNumber(n)<<endl;
}