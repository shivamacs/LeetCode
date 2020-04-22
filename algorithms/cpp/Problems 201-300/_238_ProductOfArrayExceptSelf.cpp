/* Source - https://leetcode.com/problems/product-of-array-except-self/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> productLeft(n), result(n);
    int rProduct = 1;
    
    productLeft[0] = nums[0];
    
    for (int i = 1; i < n; i++)
        productLeft[i] = nums[i] * productLeft[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        result[i] = (i == 0 ? 1 : productLeft[i - 1]) * rProduct;
        rProduct *= nums[i];
    }
    
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

    vector<int> result = productExceptSelf(nums);

    cout<<"Product array without self: ";
    for (int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}