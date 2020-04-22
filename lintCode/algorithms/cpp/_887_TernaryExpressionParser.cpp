/* Source - https://www.lintcode.com/problem/ternary-expression-parser/description/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

string parseTernary(string &expression) {
    stack<char> s;
    int a, b;
    
    for (int i=expression.length();i>=0;i--) {
        if (expression[i] == ' ' || expression[i] == ':') continue;
        
        if (expression[i] == '?') {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            if (expression[i-1] == 'T' || expression[i-1] == 't') s.push(a);
            else if (expression[i-1] == 'F' || expression[i-1] == 'f') s.push(b);
            i--;
            continue;
        }

        s.push(expression[i]);
    }
    
    return string(1, s.top());
}

int main()
{
    string expression;
    cout<<"Enter ternary expression: ";
    getline(cin, expression);

    cout<<"Result: "<<parseTernary(expression)<<endl;
}