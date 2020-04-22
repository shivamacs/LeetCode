/* Source - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    
    int i = 0, j = 1, length = 1;
    
    while(j < nums.size()) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
            length++;
        }
        
        j++;
    }
    
    return length;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];

    int length = removeDuplicates(nums);

    cout<<"Array without duplicates (duplicates are not actually removed in memory): ";
    for (int i = 0; i < length; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
