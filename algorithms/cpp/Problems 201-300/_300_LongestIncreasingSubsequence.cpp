/* Source - https://leetcode.com/problems/longest-increasing-subsequence/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

// O(nlogn) approach
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), len = 0;
    int lis[n];

    memset(lis, 0, sizeof(lis));
    
    for(int val : nums) {
        int lo = 0, hi = len;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(lis[mid] < val)
                lo = mid + 1;
            else
                hi = mid;
        }
        
        lis[lo] = val;
    
        if(lo == len)
            len++;
    }
    
    return len;
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