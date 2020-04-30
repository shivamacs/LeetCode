/* Source - https://leetcode.com/problems/maximum-product-subarray/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

// approach 1
int maxProductUsingKadane(vector<int>& nums) {
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

// approach 2
int maxProductUsingPrefixSuffixProduct(vector<int>& nums) {
    int n = nums.size(), prefixProd = 1, suffixProd = 1, maxProd = INT_MIN;
    
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        prefixProd = (nums[i] == 0) ? 1 : prefixProd * nums[i]; 
        suffixProd = (nums[j] == 0) ? 1 : suffixProd * nums[j];
        
        maxProd = max({maxProd, 
                        ((nums[i] == 0) ? INT_MIN : prefixProd), 
                        ((nums[j] == 0) ? INT_MIN : suffixProd), 
                        nums[i], 
                        nums[j]}
                        );
    }
    
    return maxProd;
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

    cout<<"Contiguous subarray with largest product using Kadane's type approach: "<<maxProductUsingKadane(nums)<<endl;
    cout<<"Contiguous subarray with largest product using prefix and suffix product: "<<maxProductUsingPrefixSuffixProduct(nums)<<endl;
}