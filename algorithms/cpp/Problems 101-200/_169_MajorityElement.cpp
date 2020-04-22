/* Source - https://leetcode.com/problems/majority-element/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 1, element = nums[0];
    // int frequency = 0;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == element)
            count++;
    
        else {
            if (count == 0) {
                count = 1;
                element = nums[i];
            }
            
            else count--;
        }
    }
        
    // for (int i = 0; i < nums.size(); i++)
    //     if (nums[i] == element)
    //         frequency++;
        
    //if (frequency <= floor(nums.size() / 2)) return -1;
    
    return element;
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

    cout<<"Majority element (occurs more the n / 2 times): "<<majorityElement(nums)<<endl;
}