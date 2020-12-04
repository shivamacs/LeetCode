/* Source - https://leetcode.com/problems/string-to-integer-atoi/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

 int myAtoi(string s) {
    int n = s.length(), i = 0, ans = 0;
    bool neg = false;
    
    while(s[i] == ' ')
        i++;
    
    if(s[i] == '+')
        i++;
    else if(s[i] == '-') {
        i++;
        neg = true;
    }
    
    while(isdigit(s[i])) {
        int digit = s[i] - '0';

        if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
            return neg ? INT_MIN : INT_MAX;
        
        ans = ans * 10 + (s[i] - '0');
        i++;
    }
    
    return neg == true ? -ans : ans;
}

int main()
{
    string s;

    cout<<"Enter a string to be converted into an integer: ";
    getline(cin>>ws, s);

    cout<<"String to integer (atoi): "<<myAtoi(s)<<endl;
}