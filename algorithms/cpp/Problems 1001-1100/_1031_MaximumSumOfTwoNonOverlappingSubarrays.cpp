/* Source - https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    int lMax, mMax, result;
    vector<int> prefixSum(A.size());
    
    for(int i = 0; i < A.size(); i++) {
        prefixSum[i] = (i == 0) ? A[i] : prefixSum[i - 1] + A[i];
    }
    
    lMax = mMax = result = INT_MIN;
    
    for(int i = (L + M); i <= A.size(); i++) {
        lMax = (i == (L + M)) ? prefixSum[L - 1] : max(lMax, prefixSum[i - M - 1] - prefixSum[i - L - M - 1]);
        mMax = (i == (L + M)) ? prefixSum[M - 1] : max(mMax, prefixSum[i - L - 1] - prefixSum[i - L - M - 1]);
        
        result = max({result, 
                        prefixSum[i - 1] - prefixSum[i - L - 1] + mMax,
                        prefixSum[i - 1] - prefixSum[i - M - 1] + lMax
                    });
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