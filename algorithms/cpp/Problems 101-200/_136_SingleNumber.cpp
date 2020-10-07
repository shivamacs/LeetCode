/* Source - https://leetcode.com/problems/single-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int unique = 0;
    
    for(int i = 0; i < nums.size(); i++)
        unique ^= nums[i];
    
    return unique;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements (all repeating exactly twice except one): ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Non-repeating number: "<<singleNumber(nums)<<endl;
}