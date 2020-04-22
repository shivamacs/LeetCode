/* Source - https://leetcode.com/problems/maximum-product-of-three-numbers/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int n = nums.size(), pproduct = 1, nproduct = 0;
                
    pproduct = nums[n - 1] * nums[n - 2] * nums[n - 3];
    nproduct = nums[0] * nums[1] * nums[n - 1];
    
    return max(pproduct, nproduct);
}

int main() {
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Maximum product of three numbers: "<<maximumProduct(nums)<<endl;
}