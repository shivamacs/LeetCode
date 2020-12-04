/* Source - https://leetcode.com/problems/maximum-average-subarray-i/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double maxAvg = -10000;
    int sum = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        
        if(i >= k - 1) {
            maxAvg = max(maxAvg, double(sum) / k);
            sum -= nums[i - k + 1];
        }
    }
    
    return maxAvg;
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

    int k;

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Maximum average value of a subarray of size "<<k<<": "<<findMaxAverage(nums, k)<<endl;
}