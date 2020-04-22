/* Source - https://leetcode.com/problems/longest-increasing-subsequence/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    
    int n = nums.size(), longIncSub = 1;
    vector<int> dp(n);

    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        int subLen = 0;

        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] > nums[j])
                subLen = max(subLen, dp[j]);
        }

        dp[i] = subLen + 1;

        longIncSub = max(longIncSub, dp[i]);
    }

    return longIncSub;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;
    
    vector<int> nums(n);
    
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];
    
    cout<<"Length of longest increasing subsequence: "<<lengthOfLIS(nums)<<endl;
}