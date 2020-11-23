/* Source - https://leetcode.com/problems/two-sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> idxMap;
    vector<int> result;
        
    for(int i = 0; i < n; i++) {
        if(idxMap.find(target - nums[i]) != idxMap.end() && i != idxMap[target - nums[i]]) {
            result.push_back(i);
            result.push_back(idxMap[target - nums[i]]);
            return result;
        } else
            idxMap[nums[i]] = i;
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

    cout<<"Enter the target: ";
    cin>>target;

    vector<int> result = twoSum(nums, target);

    cout<<"Indices of two elements that sums to given target: ["<<result[0]<<", "<<result[1]<<"]"<<endl;
}