/* Source - https://www.lintcode.com/problem/find-permutation/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findPermutation(string &s) {
    int num = 1;
    stack<int> st;
    vector<int> result;
    
    st.push(num++);
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'I') {
            while(!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
        }
            
        st.push(num++);
    }
    
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

int main()
{
    string str;

    cout<<"Enter pattern string: ";
    cin>>str;
    
    vector<int> result = findPermutation(str);

    cout<<"Smallest number following pattern: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i];
    cout<<endl;
}