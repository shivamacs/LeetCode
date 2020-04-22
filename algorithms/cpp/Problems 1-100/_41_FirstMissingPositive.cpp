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
    if (nums.size() == 0)
        return 1;
    
    nums.push_back(-1);
    
    int n = nums.size(), i = 0;
    
    while(i < n) {
        if (nums[i] != i && nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i]])
            swap(nums[nums[i]], nums[i]);
        else 
            i++;
    }
            
    for(int i = 1; i < n; i++) {
        if (nums[i] != i)
            return i;
    }
    
    return n;
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