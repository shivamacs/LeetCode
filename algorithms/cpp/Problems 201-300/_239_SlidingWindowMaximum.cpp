/* Source - https://leetcode.com/problems/sliding-window-maximum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    
    int n = nums.size();
    int leftMax[n], rightMax[n];
    
    vector<int> result;
    
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        if (i % k == 0) leftMax[i] = nums[i];
        else leftMax[i] = max(leftMax[i - 1], nums[i]);
        
        if (j == n - 1 || (j + 1) % k == 0)
            rightMax[j] = nums[j];
        else rightMax[j] = max(rightMax[j + 1], nums[j]);
    }
    
    for (int i = 0; i < n - k + 1; i++)
        result.push_back(max(leftMax[i + k - 1], rightMax[i]));
    
    return result;
}

int main()
{
    int n, k;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) cin>>nums[i];

    cout<<"Enter window size: ";
    cin>>k;

    vector<int> result = maxSlidingWindow(nums, k);

    cout<<"Array of sliding window maximum elements: ";
    for (int i = 0; i < result.size(); i++) cout<<result[i]<<" ";
    cout<<endl;
}