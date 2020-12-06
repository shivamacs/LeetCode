/* Source - https://leetcode.com/problems/find-all-duplicates-in-an-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size(), i = 0;
    vector<int> result;
    
    while(i < n) {
        if(nums[i] != nums[nums[i] - 1])
            swap(nums, i, nums[i] - 1);
        else
            i++;
    }
    
    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1)
            result.push_back(nums[i]);
    }
    
    return result;
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

    vector<int> result = findDuplicates(nums);

    cout<<"Duplicates in the given array: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}