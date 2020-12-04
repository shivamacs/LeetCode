/* Source - https://leetcode.com/problems/zigzag-conversion/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1)
        return s;
    
    int n = s.length(), i = 0;
    string groups[numRows];
    int gr = 0;
    bool dir = true;
            
    for(int i = 0; i < n; i++) {
        if(dir)
            groups[gr++] += s[i];
        else
            groups[gr--] += s[i];
        
        if(gr == numRows - 1)
            dir = false;
        
        if(gr == 0)
            dir = true;
    }
    
    string res = "";
    
    for(int i = 0; i < numRows; i++)
        res += groups[i];
    
    return res;
}

int main()
{
    string s;

    cout<<"Enter a string: ";
    cin>>s;

    int numRows;

    cout<<"Enter number of rows: ";
    cin>>numRows;

    cout<<s<<" in zigzag pattern: "<<convert(s, numRows)<<endl;
}