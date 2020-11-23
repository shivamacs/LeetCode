/* Source - https://leetcode.com/problems/first-missing-positive/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
        
    for(int i = 0; i < n; ++ i)
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    
    for(int i = 0; i < n; ++ i)
        if(nums[i] != i + 1)
            return i + 1;
    
    return n + 1;
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
        
    cout<<"First missing positive integer: "<<firstMissingPositive(nums)<<endl;
}