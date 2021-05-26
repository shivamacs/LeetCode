/* Source - https://leetcode.com/problems/generate-parentheses/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void _generate_parentheses(int open, int close, int n, string asf, vector<string>& result) {
    if(asf.length() == 2 * n && open == close) {
        result.push_back(asf);
        return;
    }
        
    if(open > close)
        _generate_parentheses(open, close + 1, n, asf + ")", result);
        
    if(open < n)   
        _generate_parentheses(open + 1, close, n, asf + "(", result);
}

vector<string> generate_parentheses(int n) {
    vector<string> result;
    _generate_parentheses(0, 0, n, "", result);
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter the number of pairs: ";
    cin>>n;

    vector<string> result = generate_parentheses(n);

    cout<<"All possible combinations of well-formed parentheses: "<<endl;
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
}