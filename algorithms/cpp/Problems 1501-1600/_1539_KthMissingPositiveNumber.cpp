/* Source - https://leetcode.com/problems/kth-missing-positive-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int curr = 0;
    
    for (int i = 0; i < arr.size(); ++i) {
        int missing = arr[i] - curr - 1;    
        
        if (missing < k)
            k -= missing;
        else
            return curr + k;
        
        curr = arr[i];
    }
    
    return curr + k;   
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int k;

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Kth missing positive number: "<<findKthPositive(arr, k)<<endl;
}