/* Source - https://leetcode.com/problems/search-insert-position/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    
    while(i <= j) {
        int mid = i + (j - i) / 2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    
    return i;
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

    cout<<"Index in the array [if target is not found, output is the insert position of the target]: "<<searchInsert(nums, target)<<endl;
}