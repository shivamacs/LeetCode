/* Source - https://leetcode.com/problems/isomorphic-strings/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    int l = s.length();
    unordered_map<char, char> charMap;
    unordered_set<char> charSet;
    
    for (int i = 0; i < l; i++) {
        if (charMap.find(s[i]) != charMap.end()) {
            if (charMap[s[i]] != t[i]) return false;
        }
        
        else if (charSet.find(t[i]) == charSet.end()) {
            charMap[s[i]] = t[i];
            charSet.insert(t[i]);
        }
        
        else return false;
    }
    
    return true;
}

int main()
{
    string s, t;
    
    cout<<"Enter first string: ";
    getline(cin, s);
    cout<<"Enter second string: ";
    getline(cin, t);

    bool result = isIsomorphic(s, t);

    if (result == true) cout<<"The strings are isomorphic.";
    else cout<<"The strings are not isomorphic.";
    cout<<endl;
}