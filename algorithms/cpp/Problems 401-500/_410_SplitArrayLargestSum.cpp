/* Source - https://leetcode.com/problems/split-array-largest-sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int>& nums, int m) {
    int n = nums.size(), maxElement = 0;
    long sum = 0;
    
    for(int i = 0; i < n; i++) {
        maxElement = max(maxElement, nums[i]);
        sum += nums[i];
    }
    
    long i = maxElement, j = sum;
    int minLargest = INT_MAX;
    
    while(i <= j) {
        int mid = i + (j - i) / 2;
        int k = 0, subs = 0;
        
        while(k < n) {
            sum = 0;
            
            for(k; k < n; k++) {   
                sum += nums[k];
                
                if(sum > mid)
                    break;
            }
            
            subs++;
        }
        
        if(subs > m)
            i = mid + 1;
        else {
            j = mid - 1;
            minLargest = min(minLargest, mid);
        }
    }
    
    return minLargest;
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

    int m;
    cout<<"Enter number of subarrays: ";
    cin>>m;
    
    cout<<"Minimum largest sum among "<<m<<" subarrays: "<<splitArray(nums, m)<<endl;
}