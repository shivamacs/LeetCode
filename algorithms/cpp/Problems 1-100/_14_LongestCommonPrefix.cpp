/* Source - https://leetcode.com/problems/longest-common-prefix/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size(), i = 0;
    
    if(n == 0)
        return "";
    
    for(i; i < strs[0].length(); i++) {
        for(int s = 1; s < n; s++) {
            if(i == strs[s].length() || strs[s][i] != strs[0][i])
                return strs[0].substr(0, i);
        }   
    }
    
    return strs[0].substr(0, i);
}

int main()
{
    int n;

    cout<<"Enter the number of strings: ";
    cin>>n;

    vector<string> strs(n);

    cout<<"Enter strings: "<<endl;
    for(int i = 0; i < n; i++)
        cin>>strs[i];

    cout<<"Longest common prefix: "<<longestCommonPrefix(strs)<<endl;
}