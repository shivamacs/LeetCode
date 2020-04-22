/* Source - https://leetcode.com/problems/optimal-division/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string optimalDivision(vector<int>& nums) {
    if (nums.size() == 1) return to_string(nums[0]);
    if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
    
    string result = to_string(nums[0]) + "/" + "(";
    
    for (int i = 1; i < nums.size() - 1; i++)
        result += to_string(nums[i]) + "/";
    
    result += to_string(nums[nums.size() - 1]) + ")";
    
    return result;
}

int main()
{
    int n;
    
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements in the series order of division: ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Optimal Division: "<<optimalDivision(nums)<<endl;
}