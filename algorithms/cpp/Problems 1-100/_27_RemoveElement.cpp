/* Source - https://leetcode.com/problems/remove-element/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size(), start = 0, end = 0, count = 0;
    
    while(end < n) {
        if(nums[end] != val)
            nums[start++] = nums[end];
        else
            count++;
            
        end++;
    }
    
    return n - count;
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

    int val;

    cout<<"Enter value to be removed: ";
    cin>>val;

    int len = removeElement(nums, val);

    cout<<"Array after removed elements (arbitary order): ";
    for(int i = 0; i < len; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}