/* Source - https://leetcode.com/problems/subarray-sum-equals-k/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int prefixSum = 0, kSumCount = 0;
    unordered_map<int, int> sumMap;

    sumMap[prefixSum]++;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        
        if (!(sumMap.find(prefixSum - k) == sumMap.end())) kSumCount += sumMap[prefixSum - k];
            
        sumMap[prefixSum]++;
    }

    return kSumCount;
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) cin>>nums[i];

    int k;
    cout<<"Enter the value of K: ";
    cin>>k;

    cout<<"Number of subarrays with sum K: "<<subarraySum(nums, k)<<endl;
}