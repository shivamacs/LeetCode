/* Source - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size(), maxEle = 0, minDiv = INT_MAX;

    for(int i = 0; i < n; i++)
        maxEle = max(maxEle, nums[i]);
    
    int start = 1, end = maxEle;
    
    while(start <= end) {
        int mid = start + (end - start) / 2;
        int sum = 0;
        
        for(int i = 0; i < n; i++)
            sum += ceil(float(nums[i]) / mid);
        
        if(sum <= threshold) {
            minDiv = min(minDiv, mid);
            end = mid - 1;
        } else
            start = mid + 1;
    }
    
    return minDiv;
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

    int threshold;

    cout<<"Enter threshold sum: ";
    cin>>threshold;

    cout<<"Smallest divisor: "<<smallestDivisor(nums, threshold)<<endl;
}