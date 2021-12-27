/* Source - https://leetcode.com/problems/summary-ranges/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    
    if(n == 0) {
        vector<string> result;
        return result;
    }
    
    string rangeString = to_string(nums[0]);
    int rangeLength = 1;
    vector<string> result;
    
    for(int i = 1; i < n; i++) {
        if(nums[i] == nums[i - 1] + 1)
            rangeLength += 1;
        else {
            if(rangeLength > 1) {
                result.push_back(rangeString + "->" + to_string(nums[i - rangeLength] + (rangeLength - 1)));
            } else
                result.push_back(rangeString);
            rangeString = to_string(nums[i]);
            rangeLength = 1;
        }
    }
    
    if(rangeLength > 1)
        result.push_back(rangeString + "->" + to_string(nums[n - rangeLength] + (rangeLength - 1)));
    else
        result.push_back(rangeString);
    
    return result;
}

int main()
{
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    vector<string> result = summaryRanges(nums);
    cout<<"Summary ranges: ";
    for(int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<endl;
}