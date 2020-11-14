/* Source - https://leetcode.com/problems/perfect-squares/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;
int numSquares(int n) {
    int dp[n + 1];
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i == 1)
            dp[i] = 1;
        else {
            int ans = (int)1e9;
            
            for(int cut = 1; cut * cut <= i; cut++)
                ans = min(ans, 1 + dp[i - (cut * cut)]);
            
            dp[i] = ans;
        }
    }
    
    return dp[n];
}


int main()
{
    int n;

    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Count of minimum number of squares that sum to "<<n<<" : "<<numSquares(n)<<endl;
}