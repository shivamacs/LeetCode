/* Source - https://leetcode.com/problems/top-k-frequent-elements/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> numsMap;
    vector<vector<int>> freqBucket(n + 1);
    vector<int> result;
    
    for(int num : nums)
        numsMap[num]++;
    
    for(auto it = numsMap.begin(); it != numsMap.end(); it++)
        freqBucket[it->second].push_back(it->first);
    
    for(int i = n; i >= 0 && k > 0; i--) {
        int s = freqBucket[i].size();
        
        while(s-- && k--) {
            int element = freqBucket[i][s];
            result.push_back(element);
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
    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    vector<int> result = topKFrequent(nums, k);
    cout<<"Top "<<k<<" frequent elements: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}