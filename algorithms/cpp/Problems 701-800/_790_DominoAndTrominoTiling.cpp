/* Source - https://leetcode.com/problems/domino-and-tromino-tiling/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int numTilings(int N) {
    if(N == 1 || N == 2)  
        return N;
    
    if(N == 3)
        return 5;
    
    int dp[N + 1];
    
    dp[1] = 1, dp[2] = 2, dp[3] = 5;
    
    for(int i = 4; i <= N; i++)
        dp[i] = (2 * (dp[i - 1] % M) % M + (dp[i - 3] % M)) % M;
    
    return dp[N];
}

int main()
{
    int N;

    cout<<"Enter the value of N: ";
    cin>>N;

    cout<<"Number of ways to tile 2 X "<<N<<" dimensional floor: "<<numTilings(N)<<endl;
}