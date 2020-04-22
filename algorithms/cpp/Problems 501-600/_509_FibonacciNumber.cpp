/* Source - https://leetcode.com/problems/fibonacci-number/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

void multiply(vector<vector<long>>& A, vector<vector<long>> B) {
    long w = ((A[0][0] * B[0][0]) % M + (A[0][1] * B[1][0]) % M) % M;
    long x = ((A[0][0] * B[0][1]) % M + (A[0][1] * B[1][1]) % M) % M;
    long y = ((A[1][0] * B[0][0]) % M + (A[1][1] * B[1][0]) % M) % M;
    long z = ((A[1][0] * B[0][1]) % M + (A[1][1] * B[1][1]) % M) % M;
    
    A[0][0] = w;
    A[0][1] = x;
    A[1][0] = y;
    A[1][1] = z;
}

void power(vector<vector<long>>& fibo, int n) {
    if (n == 0 || n == 1) return;
    
    vector<vector<long>> forOdd = {{1, 1}, {1, 0}};
   
    power(fibo, n/2);
    multiply(fibo, fibo);
    
    if (n % 2 != 0) multiply(fibo, forOdd);
}

long fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    
    vector<vector<long>> fibo = {{1, 1}, {1, 0}};
    
    power(fibo, N - 1);
    
    return fibo[0][0];
}

int main()
{
    int N;
    
    cout<<"Enter a number: ";
    cin>>N;
    
    cout<<N<<"th fibonacci number (modulo 10e9 + 7): "<<fib(N)<<endl;
}