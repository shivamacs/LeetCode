/* Source - https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    int n = A.size(), lMax = 0, mMax = 0, result = 0;
        
    for(int i = 1; i < n; i++)
        A[i] += A[i - 1];
    
    for(int i = (L + M) - 1; i < n; i++) {
        lMax = max(lMax, i == (L + M) - 1 ? A[i - M] : A[i - M] - A[i - (L + M)]);
        mMax = max(mMax, i == (L + M) - 1 ? A[i - L] : A[i - L] - A[i - (L + M)]);
        
        result = max(result, max(A[i] - A[i - M] + lMax, A[i] - A[i - L] + mMax));
    }
    
    return result;
}

int main()
{
    int n;
    
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>A[i];

    int L, M;

    cout<<"Enter value of L and M: ";
    cin>>L>>M;

    cout<<"Maximum sum of two non-overlapping subarrays: "<<maxSumTwoNoOverlap(A, L, M)<<endl;
}