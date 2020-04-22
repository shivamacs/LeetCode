/* Source - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int minParenthesesAddition(string exp) {
    int oc = 0, cc = 0;
    stack<char> s;
    
    for (int i=0;i<exp.length();i++) {
        if (exp[i] == ' ') continue;
        if (s.empty() || exp[i] == '(') s.push(exp[i]);
        else if (!s.empty() && (exp[i] == ')' && s.top() == '(')) s.pop();
        else if (!s.empty() && (exp[i] == ')' && s.top() != '(' )) s.push(exp[i]);
    }

    while(!s.empty()) {
        if (s.top() == '(') oc++;
        else cc++;
        s.pop();
    }

    return oc + cc;
}

int main()
{
    string exp;
    cout<<"Enter parentheses expression: ";
    getline(cin, exp);
    int result = minParenthesesAddition(exp);
    cout<<"Minimum number of parentheses to be added to make the expression valid: "<<result<<endl;
}