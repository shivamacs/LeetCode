/* Source - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size(), start = 0, end = n - 1;
    
    while(start < n - 1 && nums[start] <= nums[start + 1])
        start++;
    
    if(start == n - 1)
        return 0;
    
    while(end > 0 && nums[end] >= nums[end - 1])
        end--;
    
    int maxEle = nums[start], minEle = nums[start];
    for(int i = start + 1; i <= end; i++) {
        maxEle = max(maxEle, nums[i]);
        minEle = min(minEle, nums[i]);
    }
    
    while(start > 0 && nums[start - 1] > minEle)
        start--;
    
    while(end < n - 1 && nums[end + 1] < maxEle)
        end++;
    
    return end - start + 1;
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

    cout<<"Length of shortest unsorted subarray: "<<findUnsortedSubarray(nums)<<endl;
}