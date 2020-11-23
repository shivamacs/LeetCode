/* Source - https://leetcode.com/problems/next-permutation/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, int i, int j) {
    while(i < j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            int nge = i + 1;
            int j = i + 2;
            
            while(j < n && nums[j] <= nums[nge] && nums[j] > nums[i]) {
                nge = j;
                j++;
            }
            
            int temp = nums[i];
            nums[i] = nums[nge];
            nums[nge] = temp;
            
            reverse(nums, i + 1, n - 1);
            
            return;
        }
    }
    
    reverse(nums, 0, n - 1);
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

    nextPermutation(nums);

    cout<<"Next permutation: ";
    for(int i = 0; i < n; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}