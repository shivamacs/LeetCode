/* Source - https://leetcode.com/problems/largest-rectangle-in-histogram/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

long largestArea(vector<long>& arr) {
    arr.push_back(0);
    stack<long> s;
    long area = 0, maxArea = 0, i = 0, n = arr.size();
    while (i < n) {
        if (s.empty() || arr[i] > arr[s.top()]) s.push(i++);
        else {
            int top = s.top(); s.pop();
            area = arr[top] * (s.empty() ? i : i - s.top() - 1);
            if (area > maxArea) maxArea = area;
        }
    }
    return maxArea;
}
int main() 
{
    int n;
    cout<<"Enter number of bars: ";
    cin>>n;    
    vector<long> arr(n);
    cout<<"Enter bar heights: ";
    for (auto i=0;i<n;i++) cin>>arr[i];
    cout<<"Largest Area: "<<largestArea(arr)<<endl;
}