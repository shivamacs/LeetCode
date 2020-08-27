/* Source - https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    int leftMax[n];
    
    leftMax[0] = arr[0];
    
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    
    int rightMin = arr[n - 1], chunks = 0;
    
    for (int i = n - 2; i >= 0; i--) {
        if (leftMax[i] <= rightMin)
            chunks++;
        
        rightMin = min(rightMin, arr[i]);
    }
        
    return chunks + 1;
}

int main()
{
    int n;
    
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<"Max chunks to make sorted: "<<maxChunksToSorted(arr)<<endl;
}