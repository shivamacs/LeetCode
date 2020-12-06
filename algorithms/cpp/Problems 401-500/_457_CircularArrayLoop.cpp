/* Source - https://leetcode.com/problems/circular-array-loop/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int getNextIndex(int curr, vector<int>& nums, bool isForward) {
    bool dir = nums[curr] >= 0;
    int n = nums.size();
            
    if(dir != isForward)
        return -1;
                
    int next = (curr + nums[curr]) % n;
            
    if(next < 0)
        next += n;
    
    if(next == curr)
        return -1;
    
    return next;
}

bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        bool isForward = nums[i] >= 0;
        int slow = i, fast = i;
        
        do {
            slow = getNextIndex(slow, nums, isForward);
            fast = getNextIndex(fast, nums, isForward);

            if(fast != -1)
                fast = getNextIndex(fast, nums, isForward);
            
        } while(slow != -1 && fast != -1 && slow != fast);
        
        if(slow != -1 && slow == fast)
            return true;
    }
    
    return false;
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

    cout<<"Is there a cycle in the given array? "<<boolalpha<<circularArrayLoop(nums)<<endl;
}