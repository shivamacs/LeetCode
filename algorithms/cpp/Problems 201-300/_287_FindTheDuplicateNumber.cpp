/* Source - https://leetcode.com/problems/find-the-duplicate-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int findDuplicate(vector<int>& nums) {
    int n = nums.size(), i = 0;
    
    while(i < n) {
        if(nums[i] != i + 1) {
            if(nums[i] != nums[nums[i] - 1])
                swap(nums, i, nums[i] - 1);   
            else
                return nums[i];
        } else
            i++;
    }
    
    return -1;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements (1 to n): ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Duplicate number: "<<findDuplicate(nums)<<endl;
}