/* Source - https://leetcode.com/problems/largest-number-at-least-twice-of-others/
   Author - Shivam Arora
*/
// Leetcode -> 747. Largest Number Atleast Twice of Others
#include <bits/stdc++.h>
using namespace std;

int dominantIndex(vector<int>& nums) {
    if (nums.size() == 1)
        return 0;
    
    int firstMax = INT_MIN, secondMax = INT_MIN, domIndex;
    
    for (int i = 0; i < nums.size(); i++) {
        if (firstMax > nums[i])
            secondMax = max(secondMax, nums[i]);
        
        else if (firstMax < nums[i]) {
            secondMax = firstMax;
            firstMax = nums[i];
            domIndex = i;
        }
    }
    
    if (firstMax >= secondMax * 2)
        return domIndex;
    
    else return -1;
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

    cout<<"Index of largest number which is atleast twice of others: "<<dominantIndex(nums)<<endl;
}