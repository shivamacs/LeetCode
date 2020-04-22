/* Source - https://leetcode.com/problems/daily-temperatures/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of days: ";
    cin>>n;

    int arr[n];
    cout<<"Enter temperatures for each day: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    stack<int> s;
    int i = 0;
    s.push(i);
    ++i;

    while(i < n)
    {
        while(!s.empty() && arr[i] > arr[s.top()]) {
            arr[s.top()] = i - s.top();
            s.pop();
        }

        s.push(i);
        ++i;
    }

    while(!s.empty()) {
        arr[s.top()] = 0;
        s.pop();
    }

    cout<<"Days you have to wait for warmer temperature array: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}