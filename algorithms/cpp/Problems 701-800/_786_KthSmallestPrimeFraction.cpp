/* Source - https://leetcode.com/problems/k-th-smallest-prime-fraction/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Fraction {
    float val;
    int n;
    int d;
    
    Fraction (float x = 0.0, int a = 0, int b = 0) {
        val = x;
        n = a;
        d = b;
    }
    
    bool operator< (const Fraction& f) const {
        return val > f.val;
    }
};

vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    int n = A.size();
    
    priority_queue<Fraction> minHeap;
    Fraction top;
    
    float frac;
    
    for (int i = 0; i < n - 1; i++) {
        frac = float(A[i]) / float(A[n - 1]);
        minHeap.push(Fraction(frac, i, n - 1));
    }
    
    while (K--) {
        top = minHeap.top();
        minHeap.pop();
        
        if (K == 0)
        {
            int num = A[top.n];
            int den = A[top.d];

            vector<int> result;

            result.push_back(num);
            result.push_back(den);

            return result;
        }
        
        int nextNum = top.n;
        int nextDen = top.d - 1;
        
        if (nextNum < nextDen) {
            frac = float(A[nextNum]) / float(A[nextDen]);
            minHeap.push(Fraction(frac, nextNum, nextDen));
        }
    }
    
    return {};
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter sorted array of primes (including 1): ";
    for (int i = 0; i < n; i++) cin>>A[i];

    int k;
    
    cout<<"Enter the value of K: ";
    cin>>k;

    vector<int> result = kthSmallestPrimeFraction(A, k);
    cout<<"Kth smallest prime fraction in the given array: ";
    cout<<result[0]<<"/"<<result[1]<<endl;
}