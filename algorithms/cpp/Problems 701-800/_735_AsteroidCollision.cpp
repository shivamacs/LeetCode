/* Source - https://leetcode.com/problems/asteroid-collision/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> st;
    
    st.push(0);
    
    for(int i = 1; i < n; i++) {
        int curr = i;
        bool flag = true;
        
        while(!st.empty() && asteroids[curr] < 0 && asteroids[st.top()] > 0) {
            int top = st.top();
            st.pop();
            
            if(abs(asteroids[curr]) == abs(asteroids[top])) {
                flag = false;
                break;
            } else if(abs(asteroids[curr]) < abs(asteroids[top]))
                curr = top;
        }
            
        if(flag)
            st.push(curr);
    }
    
    vector<int>result(st.size());
    
    int i = result.size() - 1;
    
    while(!st.empty()) {
        result[i] = asteroids[st.top()];
        st.pop();
        i--;
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