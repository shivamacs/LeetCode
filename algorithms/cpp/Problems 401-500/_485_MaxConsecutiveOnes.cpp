/* Source - https://leetcode.com/problems/max-consecutive-ones/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int onesCount = 0, maxCount = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            onesCount++;
            if (onesCount > maxCount) maxCount = onesCount;
        }
        else onesCount = 0;
    }

    return maxCount;
}

int main()
{
    int n;
    cout<<"Enter number of elements in a binary array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) cin>>nums[i];

    cout<<"Maximum number of consecutive ones: "<<findMaxConsecutiveOnes(nums)<<endl;
}