/* Source - https://leetcode.com/problems/burst-balloons/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    
    int n = nums.size(), dp[n][n];
    
    memset(dp, 0, sizeof(dp));
    
    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            int lval = (i == 0) ? 1 : nums[i - 1];
            int rval = (j == n - 1) ? 1 : nums[j + 1];
            dp[i][j] = INT_MIN;

            for(int cut = i; cut <= j; cut++) {
                int left = (cut == i) ? 0 : dp[i][cut - 1];
                int right = (cut == j) ? 0 : dp[cut + 1][j];

                dp[i][j] = max(dp[i][j], left + (lval * nums[cut] * rval) + right);
            }
        }
    }
    
    return dp[0][n - 1];
}

int main()
{
    int n;

    cout<<"Enter number of balloons: ";
    cin>>n;
    
    vector<int> nums(n);

    cout<<"Enter numbers on the balloons: ";
    for(int i = 0; i < n; i++)  
        cin>>nums[i];

    cout<<"Maximum coins collected by bursting all the balloons: "<<maxCoins(nums)<<endl;  
}