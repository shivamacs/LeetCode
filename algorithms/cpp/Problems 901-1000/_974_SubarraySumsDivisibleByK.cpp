/* Source - https://leetcode.com/problems/subarray-sums-divisible-by-k/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& A, int k) {
    int prefixSum = 0, prefixMod = 0, kDivCount = 0;
    map<int, int> modMap;

    modMap[prefixMod]++;

    for (int i = 0; i < A.size(); i++) {
        prefixSum += A[i];
        prefixMod = prefixSum % k;

        if (prefixMod < 0) prefixMod += k;
        
        if (!(modMap.find(prefixMod) == modMap.end())) kDivCount += modMap[prefixMod];
      
        modMap[prefixMod]++;
    }

    return kDivCount;
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) cin>>A[i];

    int k;
    cout<<"Enter the value of K: ";
    cin>>k;

    cout<<"Number of subarrays with sum divisible by K: "<<subarraysDivByK(A, k)<<endl;
}