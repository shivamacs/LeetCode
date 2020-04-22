/* Source - https://leetcode.com/problems/asteroid-collision/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& arr) {
    int n = arr.size(), top;
    bool flag;
    stack<int> s;
    vector<int> result;
    
    for (int i=0;i<n;i++) {
        flag = 1;
        if (s.empty() || arr[i] >= 0) s.push(i);

        else if (!s.empty() && arr[s.top()] < 0) s.push(i);
        
        else if (!s.empty() && arr[i] < 0) {
            if (abs(arr[i]) < abs(arr[s.top()])) continue;
            while (!s.empty() && (arr[s.top()] >= 0 && abs(arr[i]) >= abs(arr[s.top()]))) {
                top = s.top(); s.pop();
                if (abs(arr[i]) == abs(arr[top])) {
                    flag = 0; 
                    break;
                };
            }
            if (!s.empty() && (arr[s.top()] > 0 && abs(arr[i]) < abs(arr[s.top()]))) flag = 0;
            if (flag == 1) if (s.empty() || arr[s.top()] < 0) s.push(i);
        }
    }

    while(!s.empty()) {
        result.insert(result.begin(), arr[s.top()]);
        s.pop();
    }

    return result;
}

int main()
{
    int n;
    cout<<"Enter number of asteroids: ";
    cin>>n;

    vector<int> arr(n), result;
    cout<<"Enter speeds of asteroids: ";
    for (int i=0;i<n;i++) cin>>arr[i];

    result = asteroidCollision(arr);

    cout<<"State of asteroids after all collisions: [";
    
    for (int i=0;i<result.size();i++) cout<<result[i]<<", ";
    cout<<"]"<<endl;
}