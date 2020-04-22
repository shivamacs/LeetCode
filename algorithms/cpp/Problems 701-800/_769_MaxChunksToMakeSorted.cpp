/* Source - https://leetcode.com/problems/max-chunks-to-make-sorted/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size(), max = INT_MIN, chunks = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        
        if (i == max)
            chunks++;
    }
    
    return chunks;
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

    cout<<"Maximum chunks to make sorted: "<<maxChunksToSorted(arr)<<endl;
}