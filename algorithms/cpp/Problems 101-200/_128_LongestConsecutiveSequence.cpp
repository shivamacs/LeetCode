/* Source - https://leetcode.com/problems/longest-consecutive-sequence/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveUsingHashMap(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    unordered_map<int, int> seqMap;
    int start = 0, end = 0, maxSeqLen = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (seqMap.find(nums[i]) == seqMap.end()) {
            seqMap[nums[i]]++;
        
            start = nums[i] - ((seqMap.find(nums[i] - 1) != seqMap.end()) ? seqMap[nums[i] - 1] : 0);
            end = nums[i] + ((seqMap.find(nums[i] + 1) != seqMap.end()) ? seqMap[nums[i] + 1] : 0);

            if (start != end) {
                if (start == nums[i]) {
                    seqMap[end] += seqMap[nums[i]];
                    seqMap[start] = seqMap[end];
                }

                else {
                    seqMap[start] += (end == nums[i]) ? seqMap[nums[i]] : seqMap[end] + seqMap[nums[i]];
                    seqMap[end] = seqMap[start];
                }
            }
                            
            if (seqMap[end] > maxSeqLen) maxSeqLen = seqMap[end];
        }
    }
    
    return maxSeqLen;
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