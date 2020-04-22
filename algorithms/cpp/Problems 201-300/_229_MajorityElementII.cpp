/* Source - https://leetcode.com/problems/majority-element-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    if (nums.empty()) return {};
    
    int element1 = nums[0], count1 = 1, element2 = nums[0], count2 = 0;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != element1 && nums[i] != element2 && count1 != 0 && count2 != 0) {
            count1--;
            count2--;
        }
        
        else if (nums[i] == element1) count1++;
        
        else if (nums[i] == element2) count2++;
        
        else {
            if (count1 == 0) {
                element1 = nums[i];
                count1++;
            }
        
            if (count2 == 0) {
                element2 = nums[i];
                count2++;
            }
        }
    }
    
    count1 = 0, count2 = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == element1) count1++;
        else if (nums[i] == element2) count2++;
    }
    
    vector<int> result;
    
    if (count1 > nums.size() / 3) result.push_back(element1);
    if (count2 > nums.size() / 3) result.push_back(element2);

    return result;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];

    vector<int> result = majorityElement(nums);

    cout<<"Element(s) that occur(s) more than n / 3 times: ";
    for (int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1];
    cout<<endl;
}