/* Source - https://leetcode.com/problems/jump-game-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, currEnd = 0, currFarthest = 0;
    
    for (int i = 0; i < n - 1; i++) {
        currFarthest = max(currFarthest, i + nums[i]);
        
        if (i == currEnd) {
            jumps++;
            currEnd = currFarthest;
        }
    }
    
    return jumps;
}

int main()
{
    int n;

    cout<<"Enter number of elements in the array: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Minimum number of jumps to reach the last index of the array: "<<jump(nums)<<endl;
}