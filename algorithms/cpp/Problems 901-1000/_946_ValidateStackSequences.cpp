/* Source - https://leetcode.com/problems/validate-stack-sequences/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

bool validateStackSequences (vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size(), i = 0, j = 0;
    stack<int> st;
    
    while(i < n) {
        if(!st.empty() && pushed[st.top()] == popped[j]) {
            st.pop();
            j++;
        } else {
            st.push(i);
            i++;
        }
    }
            
    while(!st.empty()) {
        if(popped[j] != pushed[st.top()])
            return false;
        
        st.pop();
        j++;
    }
                    
    return (j == n);
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> pushed(n), popped(n);

    cout<<"Enter pushed sequence: ";
    for (int i=0;i<n;i++) cin>>pushed[i];

    cout<<"Enter popped sequence: ";
    for (int i=0;i<n;i++) cin>>popped[i];

    cout<<"Sequence validation: "<<validateStackSequences(pushed, popped)<<endl;
}