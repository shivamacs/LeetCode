/* Source - https://leetcode.com/problems/search-in-rotated-sorted-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target, int i, int j) {
    while(i <= j) {
        int mid = i + (j - i) / 2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            j = mid - 1;
        else i = mid + 1;
    }
    
    return -1;
}

int search(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return -1;
    
    int n = nums.size(), i = 0, j = n - 1;
    
    while(i < j) {
        int mid = i + (j - i) / 2;
        
        if(nums[mid] > nums[j])
            i = mid + 1;
        else
            j = mid;
    }
    
    int start = j;
    
    if(target >= nums[start] && target <= nums[n - 1])
        return binarySearch(nums, target, start, n - 1);
    else
        return binarySearch(nums, target, 0, start - 1);
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

    int target;
    
    cout<<"Enter target: ";
    cin>>target;

    cout<<"Target found at index (if not found, we will get -1)? "<<search(nums, target)<<endl;
}