/* Source - https://leetcode.com/problems/super-ugly-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int k = primes.size();
    int pointers[k];
    int dp[n];
    
    memset(pointers, 0, sizeof(pointers));
    
    dp[0] = 1;
    
    for(int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        
        for(int j = 0; j < k; j++)
            dp[i] = min(dp[i], dp[pointers[j]] * primes[j]);
            
        for(int j = 0; j < k; j++) {
            if(dp[i] == dp[pointers[j]] * primes[j])
                pointers[j]++;
        }
    }
    
    return dp[n - 1];
}

int main()
{
    int n;

    cout<<"Enter the value of n: ";
    cin>>n;

    int k;

    cout<<"Enter number of primes: ";
    cin>>k;

    vector<int> primes(k);

    cout<<"Enter primes: ";
    for(int i = 0; i < k; i++)
        cin>>primes[i];

    cout<<"nth super ugly number: "<<nthSuperUglyNumber(n, primes)<<endl;
}