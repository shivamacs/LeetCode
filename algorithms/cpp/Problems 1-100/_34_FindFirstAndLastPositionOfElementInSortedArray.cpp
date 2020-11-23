/* Source - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int fi = -1, li = -1, i = 0, j = nums.size() - 1;
    vector<int> result;
    
    while(i <= j) {
        int mid = i + (j - i) / 2;
        
        if(nums[mid] == target) {
            fi = mid;
            j = mid - 1;
        } else if(nums[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    
    result.push_back(fi);
    
    i = 0, j = nums.size() - 1;
    
    while(i <= j) {
        int mid = i + (j - i) / 2;
        
        if(nums[mid] == target) {
            li = mid;
            i = mid + 1;
        } else if(nums[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    
    result.push_back(li);
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;
    
    vector<int> nums(n);
    
    cout<<"Enter elements (ascending order): ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];
        
    cout<<"Enter a number whose first and last index are to be found: ";
    int target;
    cin>>target;

    vector<int> result = searchRange(nums, target);

    cout<<"First index and last index of given target (-1 if not found): "<<result[0]<<" "<<result[1]<<endl;  
}