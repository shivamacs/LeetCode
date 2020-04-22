/* Source - https://leetcode.com/problems/decode-string/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

void decodeString(string exp)
{
    stack<string> s;
    string sub, temp, result;

    for(int i=exp.length()-1;i>=0;i--) {
        temp = sub = "";
        if (exp[i] == ' ') continue;

        if (isdigit(exp[i])) {
            s.pop();
            int val = 0, j = 0; 
            while(i >= 0 && isdigit(exp[i])) { 
                val += (exp[i]-'0') * pow(10, j);
                j++;
                if (i > 0 && isdigit(exp[i-1])) i--;
                else break; 
            }
            while (!s.empty() && s.top() != "]") {
                temp += s.top();
                s.pop();
            }
            while(val--) sub += temp; 
            if (!s.empty()) s.pop();
            s.push(sub);
        }
        
        else if (!isdigit(exp[i])) s.push(string(1, exp[i]));
    }

    while(!s.empty()) {
        result += s.top();
        s.pop();
    }
    s.push(result);

    cout<<s.top()<<endl;
}

int main()
{
    string exp;
    cout<<"Enter expression in the required format: ";
    getline(cin, exp);

    decodeString(exp);
}