/* Source - https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int ksum, pos;
    
    Pair(int k = 0, int p = -1) {
        ksum = k;
        pos = p;
    }
};

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size(), sum = 0;
    Pair left[n], right[n];
    
    for(int i = 0; i < k; i++)
        sum += nums[i];
    
    left[k - 1].ksum = sum;
    left[k - 1].pos = 0;
    
    for(int i = k; i < n; i++) {
        sum = sum - nums[i - k] + nums[i];
        
        if(sum > left[i - 1].ksum) {
            left[i].ksum = sum;
            left[i].pos = i - k + 1;
        } else {
            left[i].ksum = left[i - 1].ksum;
            left[i].pos = left[i - 1].pos;
        }
    }
            
    sum = 0;
    
    for(int i = n - 1; i > n - k - 1; i--)
        sum += nums[i];
    
    right[n - k].ksum = sum;
    right[n - k].pos = n - k;
    
    for(int i = n - k - 1; i >= 0; i--) {
        sum = sum - nums[i + k] + nums[i];
        
        if(sum >= right[i + 1].ksum) {
            right[i].ksum = sum;
            right[i].pos = i;
        } else {
            right[i].ksum = right[i + 1].ksum;
            right[i].pos = right[i + 1].pos;
        }
    }
            
    int currSum, maxSum = INT_MIN;
    vector<int> result;

    sum = 0;

    for(int i = k; i < 2 * k; i++)
        sum += nums[i];
    
    maxSum = left[k - 1].ksum + sum + right[2 * k].ksum;
    result = {left[k - 1].pos, k, right[2 * k].pos};
                    
    for(int i = 2 * k; i < n - k; i++) {
        sum = sum - nums[i - k] + nums[i];
        currSum = left[i - k].ksum + sum + right[i + 1].ksum;
                    
        if(currSum > maxSum) {
            maxSum = currSum;
            result = {left[i - k].pos, i - k + 1, right[i + 1].pos};
        }
    }
    
    return result;
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

    int k;

    cout<<"Enter the size for each subarray: ";
    cin>>k;

    vector<int> result = maxSumOfThreeSubarrays(nums, k);

    cout<<"Starting indices of 3 non-overlapping subarrays each of size "<<k<<" having maximum sum: [";
    for(int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<"]"<<endl;
}