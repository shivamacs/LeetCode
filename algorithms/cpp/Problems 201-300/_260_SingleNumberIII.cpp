/* Source - https://leetcode.com/problems/single-number-iii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int twoNums = 0;
    
    for(int i = 0; i < nums.size(); i++)
        twoNums ^= nums[i];

    int rsb = twoNums & (-twoNums), num1 = 0, num2 = 0;

    for(int i = 0; i < nums.size(); i++) {
        if((nums[i] & rsb) == 0)
            num1 ^= nums[i];
        else
            num2 ^= nums[i];
    }
    
    vector<int> result;
    
    result.push_back(num1);
    result.push_back(num2);
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements (all repeating exactly twice except two): ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    vector<int> result = singleNumber(nums);

    cout<<"Two non-repeating numbers: "<<result[0]<<" "<<result[1]<<endl;
}