/* Source - https://leetcode.com/problems/next-greater-element-ii/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> result(n, -1);
    
    st.push(0);
    
    int i = 1;
    
    while(i < 2 * n) {
        while(!st.empty() && nums[i % n] > nums[st.top()]) {
            result[st.top()] = nums[i % n];
            st.pop();
        } 
        
        if(i < n)
            st.push(i);
        
        i++;
    }
    
    return result;
}

int main()
{
    int n;
    stack<int> s;

    cout<<"Enter array size: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter elements for circular array: ";
    for (int i=0;i<n;i++)
        cin>>nums[i];

    vector<int> result = nextGreaterElements(nums);

    cout<<"Next greater element array for circular array: ";
    for(int i=0;i<n;i++) cout<<result[i]<<" ";
    cout<<endl;
}