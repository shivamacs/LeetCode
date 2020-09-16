/* Source - https://leetcode.com/problems/remove-duplicate-letters/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string reverse(string s) {
    int i = 0, j = s.length() - 1;
    
    while(i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        
        i++;
        j--;
    }
    
    return s;
}

string removeDuplicateLetters(string s) {
    int n = s.length();
    
    if(n == 0)
        return "";
    
    int freq[26];
    bool visited[26];
    stack<char> st;
    
    memset(freq, 0, sizeof(freq));
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < n; i++)
        freq[s[i] - 'a']++;
    
    visited[s[0] - 'a'] = true;
    st.push(s[0]);
            
    for(int i = 1; i < n; i++) {            
        if(visited[s[i] - 'a'] == true) {
            freq[s[i] - 'a']--;
            continue;
        }
        
        while(!st.empty() && s[i] <= st.top() && freq[st.top() - 'a'] > 1) {
            visited[st.top() - 'a'] = false;
            freq[st.top() - 'a']--;
            st.pop();
        }
        
        visited[s[i] - 'a'] = true;
        st.push(s[i]);
    }
    
    string answer = "";
    
    while(!st.empty()) {
        answer += string(1, st.top());
        st.pop();
    }
            
    return reverse(answer);
}

int main()
{
    string s;

    cout<<"Enter a string (lowercase letters, a-z): ";
    cin>>s;

    cout<<"Lexicographically smallest string after removing duplicate letters: "<<removeDuplicateLetters(s)<<endl;
}