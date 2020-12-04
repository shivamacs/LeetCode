/* Source - https://leetcode.com/problems/minimum-size-subarray-sum/
   Author - Shivam Arora
*/ 
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size(), start = 0, sum = 0, minLen = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        
        while(sum >= s) {
            minLen = min(minLen, i - start + 1);
            sum -= nums[start];
            start++;
        }
    }
    
    return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
    int s, n;

    cout<<"Enter sum: ";
    cin>>s;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Minimum length of subarray having sum greater than or equal to "<<s<<": "<<minSubArrayLen(s, nums)<<endl;
}