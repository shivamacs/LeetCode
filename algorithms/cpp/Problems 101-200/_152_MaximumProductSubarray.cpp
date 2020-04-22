/* Source - https://leetcode.com/problems/maximum-product-subarray/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxProductKadaneType(vector<int>& nums) {
    int positive = nums[0], negative = nums[0], overallMax = nums[0]; 
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            positive = max(nums[i], positive * nums[i]);
            negative = min(nums[i], negative * nums[i]);
        }
        
        else {
            int temp = positive;
            
            positive = max(nums[i], negative * nums[i]);
            negative = min(nums[i], temp * nums[i]);
        }
        
        overallMax = max(overallMax, positive);
    }
    
    return overallMax;
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

    cout<<"Contiguous subarray with largest product using Kadane's type approach: "<<maxProductKadaneType(nums)<<endl;
    //cout<<"Contiguous subarray with largest product using prefix and suffix product: "<<maxProductPrefixSuffix(nums)<<endl;
}