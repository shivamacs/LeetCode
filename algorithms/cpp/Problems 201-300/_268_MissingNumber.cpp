/* Source - https://leetcode.com/problems/missing-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int missingNumber(vector<int>& nums) {
    int n = nums.size(), i = 0;
    
    while(i < n) {
        if(nums[i] < n && nums[i] != nums[nums[i]])
            swap(nums, i, nums[i]);
        else
            i++;
    }
    
    for(int i = 0; i < n; i++) {
        if(nums[i] != i)
            return i;
    }
    
    return n;
}

// another approach, using sum
// int missingNumber(vector<int>& array, int n) {
//     int sum = n * (n + 1) / 2, actual = 0;
    
//     for (int i = 0; i < array.size(); i++)
//         actual += array[i];
        
//     return sum - actual;
// }

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements (between 0 to n) : ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Missing number: "<<missingNumber(nums)<<endl;
}