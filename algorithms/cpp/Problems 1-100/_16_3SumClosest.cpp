/* Source - https://leetcode.com/problems/3sum-closest/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int result = INT_MAX, minDiff = INT_MAX;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i + 2 < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        
        int l = i + 1, r = n - 1;
        
        while(l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            
            if(abs(target - sum) < minDiff) {
                result = sum;
                minDiff = abs(target - sum);
            }
            
            if(sum == target) {
                while(l < r && nums[l] == nums[l + 1])
                    l++;
                while(l < r & nums[r] == nums[r - 1])
                    r--;
                
                l++;
                r--;
            } else if(sum < target)
                l++;
            else
                r--;
        }
    
    }
    
    return result;
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

    int target;

    cout<<"Enter target: ";
    cin>>target;

    cout<<"Triplet sum that is closest to target: "<<threeSumClosest(nums, target)<<endl; 
}