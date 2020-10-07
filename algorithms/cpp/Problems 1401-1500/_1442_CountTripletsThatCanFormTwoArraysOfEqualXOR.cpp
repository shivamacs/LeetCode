/* Source - https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>& arr) {
    int n = arr.size(), xy = 0, triplets = 0;
        
    for(int i = 0; i < n; i++) {
        xy = arr[i];
        
        for(int k = i + 1; k < n; k++) {
            xy ^= arr[k];
            
            if(xy == 0)
                triplets += (k - i);
        }
    }
    
    return triplets;
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

    cout<<"Number of triplets where X = Y (X & Y are defined in question): "<<countTriplets(arr)<<endl;
}