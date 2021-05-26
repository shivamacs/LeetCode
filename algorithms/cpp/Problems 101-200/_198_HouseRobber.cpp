/* Source - https://leetcode.com/problems/house-robber/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int rob_approach_1(vector<int>& nums) {
    int n = nums.size();

    if (n == 0)
        return 0;
        
    if (n == 1)
        return nums[0];
        
    if (n == 2)
        return max(nums[0], nums[1]);
        
    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for(int i = 2; i < n; i++)
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        
    return dp[n - 1];
}

int rob_approach_2(vector<int>& nums) {
    int n = nums.size(), v1 = 0, v2 = 0, stolen = 0;
        
    for(int i = 0; i < n; i++) {
        stolen = max(v1 + nums[i], v2);
        v1 = v2;
        v2 = stolen;
    }
    
    return stolen;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Max money that can be stolen such that no two houses robbed are adjacent (approach 1): "<<rob_approach_1(nums)<<endl;
    cout<<"Max money that can be stolen such that no two houses robbed are adjacent (approach 2): "<<rob_approach_2(nums)<<endl;
}