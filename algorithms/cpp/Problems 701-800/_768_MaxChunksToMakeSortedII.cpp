/* Source - https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    if (arr.size() == 1) return 1;
    
    int n = arr.size(), chunks = 0;
    vector<int> leftMax(n), rightMin(n);
    
    leftMax[0] = arr[0], rightMin[n - 1] = arr[n - 1];
    
    for (int i = 1, j = n - 2; i < n, j >= 0; i++, j--) {
            leftMax[i] = arr[i] > leftMax[i - 1] ? arr[i] : leftMax[i - 1];
            rightMin[j] = arr[j] < rightMin[j + 1] ? arr[j] : rightMin[j + 1];
    }
    
    for (int i = 0; i < n - 1; i++)
        if (leftMax[i] <= rightMin[i + 1])
            chunks++;
        
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