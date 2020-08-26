/* Source - https://leetcode.com/problems/2-keys-keyboard/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    if(n == 1)
        return 0;
        
    int sieve[n + 1];
        
    for(int i = 0; i <= n; i++)
        sieve[i] = i;
    
    for(int i = 2; i * i <= n; i++) {
        if(sieve[i] == i) {
            for(int j = i * i; j <= n; j++) {
                if(j % i == 0)
                    sieve[j] = i;
            }
        }
    }
        
    int operations = 0;
    
    while(n != 1) {
        operations += sieve[n];
        n /= sieve[n];
    }
    
    return operations;
}

int getLargestFactor(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return (n / i);
    }   
    
    return n;
}

int minStepsDP(int n) {
    if(n == 1)
        return 0;
    
    if(n == 2)
        return 2;
    
    int dp[n + 1];
    
    dp[1] = 0;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        int lf = getLargestFactor(i);
        
        if(lf == i)
            dp[i] = i;
        else
            dp[i] = dp[lf] + (i / lf);
    }
    
    return dp[n];
}

int main()
{
    int N;
    
    cout<<"Enter the value of N: ";
    cin>>N;

    cout<<"Minimum number of operations to get "<<N<<" 'A' on the notepad: "<<minSteps(N)<<endl;
    cout<<"Minimum number of operations to get "<<N<<" 'A' on the notepad (using DP): "<<minStepsDP(N)<<endl;
}