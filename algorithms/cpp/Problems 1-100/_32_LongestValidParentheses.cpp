/* Source - https://leetcode.com/problems/longest-valid-parentheses/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int longestValidSubstring(string exp) {
    int length, maxLength = 0;
    stack<int> s;
    map<char, char> expMap;
    
    expMap[')'] = '(';
    expMap[']'] = '[';
    expMap['}'] = '{';
    
    for(int i=0;i<exp.length();i++) {
        if (exp[i] == ' ') continue;

        if (s.empty() || (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')) s.push(i);
        else if (!s.empty() && expMap[exp[i]] == exp[s.top()]) {
            s.pop();
            length = s.empty() ? i + 1 : i - s.top();
            if (length > maxLength) maxLength = length;
        }
        else if (!s.empty() && expMap[exp[i]] != exp[s.top()]) s.push(i);
    }

    return maxLength;
}

int main()
{
    string exp;
    cout<<"Enter expression: ";
    getline(cin, exp);

    cout<<"Length of longest valid substring: "<<longestValidSubstring(exp)<<endl;

}