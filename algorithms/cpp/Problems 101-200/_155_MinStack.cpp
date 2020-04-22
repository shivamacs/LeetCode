/* Source - https://leetcode.com/problems/min-stack/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

class MinStack {
    private:
        stack<long> st;
        long min;
    
    public:
        void push(int x);
        void pop();
        int top();
        int getMin();
};

void MinStack :: push(int x) {
    if (st.empty()) { st.push(0); min = x; return; }
    
    long diff = long(x) - min;
    st.push(diff);
    if (diff < 0) min = x;
}

void MinStack :: pop() {
    if (st.empty()) return;
    
    long top = st.top();
    st.pop();

    if (top < 0) min -= top;
}

int MinStack :: top() {
    if (st.empty()) return -1;

    if (st.top() < 0) return min;
    else return min + st.top();
}

int MinStack :: getMin() {
    if (st.empty()) return -1;

    return min;
}
int main()
{
    MinStack ms;
    ms.push(5);
    ms.push(8);
    ms.push(6);
    ms.push(5);
    ms.push(3);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.top()<<endl;
    ms.pop();
    cout<<ms.top()<<endl;
    ms.pop();
    ms.push(2);
    cout<<ms.getMin()<<endl;   
}