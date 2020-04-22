/* Source - https://leetcode.com/problems/valid-parentheses/
   Author - Shivam Arora
*/  
#include<bits/stdc++.h>
using namespace std;

bool validExpression(string exp) {
    stack<char> s;
    map<char, char> expMap;
    
    expMap[')'] = '(';
    expMap[']'] = '[';
    expMap['}'] = '{';

    for(int i=0;i<exp.length();i++) {
        if (exp[i] == ' ' || isalpha(exp[i]) || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
            continue;

        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') s.push(exp[i]);
        else {
            if (s.empty())
                return false;
            char t = s.top();
            if (expMap[exp[i]] != t) 
                return false;
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string exp;
    cout<<"Enter expression: ";
    getline(cin, exp);

    cout<< (validExpression(exp) ? "Balanced" : "Not balanced")<<endl;
}