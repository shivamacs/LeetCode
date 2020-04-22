/* Source - https://leetcode.com/problems/next-greater-element-ii/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[n], ans[n];
    stack<int> s;

    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter elements for circular array: ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
        ans[i] = -1;
    }

    int i = 0, count = 1;
    s.push(i);
    ++i;

    while(i < n && count <= 2)
    {
        while(!s.empty() && arr[i] > arr[s.top()]) {
            if (ans[s.top()] == -1) ans[s.top()] = arr[i];
            s.pop();
        }
        if (ans[i] == -1) s.push(i);
        if (i == n-1) { 
            i = -1;
            count++;
        }
        ++i;
    }

    cout<<"Next greater element array for circular array: ";
    for (int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}