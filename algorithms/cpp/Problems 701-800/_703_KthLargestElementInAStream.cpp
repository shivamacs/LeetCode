/* Source - https://leetcode.com/problems/kth-largest-element-in-a-stream/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> kth_largest(int k, int arr[], int n) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
        
        if(minHeap.size() < k)
            result.push_back(-1);
        else if (minHeap.size() == k)
            result.push_back(minHeap.top());
        else {
            minHeap.pop();
            result.push_back(minHeap.top());
        }
    }
    
    return result;
}

int main()
{
    int k, n;

    cout<<"Enter the value of k: ";
    cin>>k;
    
    cout<<"Enter the number of elements in the stream: ";
    cin>>n;

    int arr[n];

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    vector<int> result = kth_largest(k, arr, n);

    cout<<"Kth largest element for every element in the stream: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}