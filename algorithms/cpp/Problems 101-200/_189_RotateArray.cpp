/* Source - https://leetcode.com/problems/rotate-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, int i, int j) {
    int n = i + j;
    
    for (i; i < n / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[j - 1];
        nums[j - 1] = temp;
        
        j--;
    }
}

void rotateAntiClockWise(vector<int>& nums, int k) {
    int n = nums.size();
    
    if (k > n) k %= n;
        
    reverse(nums, 0, n - k);
    reverse(nums, n - k, n);
    reverse(nums, 0, n);
}

int main()
{
    int n, k;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Enter the value of k: ";
    cin>>k;

    rotateAntiClockWise(nums, k);

    cout<<"Rotated array: "; 
    for (int i = 0; i < n; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}