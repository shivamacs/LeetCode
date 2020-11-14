/* Source - https://leetcode.com/problems/super-egg-drop/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int superEggDrop(int K, int N) {
    int dp[N + 1][K + 1];
    memset(dp, 0, sizeof(dp));
    
    int m = 0;
    while (dp[m][K] < N) {
        m++;
        
        for (int k = 1; k <= K; k++)
            dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
    }
    
    return m;
}

int main()
{
    int n, k;

    cout<<"Enter number of floors: ";
    cin>>n;

    cout<<"Enter number of eggs: ";
    cin>>k;

    cout<<"Minimum number of attempts taken to find the critical floor: "<<superEggDrop(n, k)<<endl;
}