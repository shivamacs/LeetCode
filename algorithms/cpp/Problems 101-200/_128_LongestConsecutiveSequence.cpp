/* Source - https://leetcode.com/problems/longest-consecutive-sequence/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveUsingHashMap(vector<int>& nums) {
    unordered_map<int, int> lenMap;
    int longest = 0;
    
    for(int i = 0; i < nums.size(); i++) {       
        int val = nums[i];
        
        if(lenMap.find(val) == lenMap.end()) {
            int left = lenMap.find(val - 1) != lenMap.end() ? lenMap[val - 1] : 0;
            int right = lenMap.find(val + 1) != lenMap.end() ? lenMap[val + 1] : 0;
            
            lenMap[val] =  1 + left + right;
            lenMap[val - left] = lenMap[val];
            lenMap[val + right] = lenMap[val];
            
            longest = max(longest, lenMap[val]);
        }
    }
    
    return longest;
}

int longestConsecutiveUsingHashSet(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    unordered_set<int> seqSet(nums.begin(), nums.end());
    int maxSeqLen = 0;
    
    while (seqSet.size() > maxSeqLen) {
        int p = *seqSet.begin(), q = p + 1;
        
        while (seqSet.erase(p)) --p;
        
        while (seqSet.erase(q)) ++q;
        
        maxSeqLen = max(maxSeqLen, q - p - 1);
    }
    
    return maxSeqLen;
}

int main()
{
    int n;
    
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) cin>>nums[i];

    cout<<"Length of longest consecutive sequence (hashmap approach): "<<longestConsecutiveUsingHashMap(nums)<<endl;
    cout<<"Length of longest consecutive sequence (hashset approach): "<<longestConsecutiveUsingHashSet(nums)<<endl;
}