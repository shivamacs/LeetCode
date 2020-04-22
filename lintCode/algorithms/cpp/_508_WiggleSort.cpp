/* Source - https://www.lintcode.com/problem/wiggle-sort/description/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void wiggleSort(vector<int> &nums) {
    int n = nums.size(), i = 0;
    
    while (i < n - 1) {
        if (i % 2 == 0) {
            if (nums[i] > nums[i + 1])
                swap(nums[i], nums[i + 1]);
        }
            
        else if (nums[i] < nums[i + 1])
            swap(nums[i], nums[i + 1]);
            
        i++;
    }
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
        
    wiggleSort(nums);
    
    cout<<"Wiggly sorted array: ";
    for (int i = 0; i < n; i++) 
        cout<<nums[i]<<" ";
    cout<<endl;
}