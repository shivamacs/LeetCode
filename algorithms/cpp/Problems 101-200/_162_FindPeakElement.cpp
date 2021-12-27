/* Source - https://leetcode.com/problems/find-peak-element/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
        
    int low = 0;
    int high = n - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1]))
            return mid;
        else if (mid > 0 && nums[mid] < nums[mid - 1])
            high = mid - 1;
        else if(mid < n - 1 && nums[mid] < nums[mid + 1])
            low = mid + 1;
    }
    
    return low;
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Index of peak element: "<<findPeakElement(nums)<<endl;
}