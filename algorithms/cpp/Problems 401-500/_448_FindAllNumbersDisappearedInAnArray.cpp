/* Source - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size(), i = 0;
    
    while(i < n) {
        if(nums[i] != nums[nums[i] - 1])
            swap(nums, i, nums[i] - 1);
        else
            i++;
    }
    
    vector<int> result;
    
    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1)
            result.push_back(i + 1);
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

    vector<int> result = findDisappearedNumbers(nums);

    cout<<"Disappeared numbers: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}