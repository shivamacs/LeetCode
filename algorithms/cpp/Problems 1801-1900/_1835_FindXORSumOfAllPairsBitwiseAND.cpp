/* Source - https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    int xora = 0;
    int xorb = 0;
    
    for(int a : arr1)
        xora ^= a;
    
    for(int b : arr2)
        xorb ^= b;
    
    return xora & xorb;
}

int main()
{
    int n1, n2;
    cout<<"Enter the number of elements in first array: ";
    cin>>n1;
    cout<<"Enter the number of elements in second array: ";
    cin>>n2;
    vector<int> arr1(n1), arr2(n2);
    cout<<"Enter elements in first array: ";
    for(int i = 0; i < n1; i++)
        cin>>arr1[i];
    cout<<"Enter elements in second array: ";
    for(int i = 0; i < n2; i++)
        cin>>arr2[i];
    
    int result = getXORSum(arr1, arr2);
    cout<<"XOR Sum of all pairs bitwise AND: "<<result<<endl;
}