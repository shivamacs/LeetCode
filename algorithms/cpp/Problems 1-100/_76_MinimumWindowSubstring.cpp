/* Source - https://leetcode.com/problems/minimum-window-substring/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string smallestWindowForSubstring(string s, string t) {
    int n = s.length(), m = t.length(), matched = 0, minLen = INT_MAX, start = 0, beg = 0;
    int freq[256];
    bool patt[256];
    
    memset(freq, 0, sizeof(freq));
    memset(patt, false, sizeof(patt));
    
    for(int i = 0; i < m; i++) {
        freq[t[i]]++;
        patt[t[i]] = true;
    }
        
    for(int i = 0; i < n; i++) {
        if(patt[s[i]]) {
            freq[s[i]]--;
            
            if(freq[s[i]] >= 0)
                matched++;
        }
        
        while(matched == m) {
            if(i - start + 1 < minLen) {
                minLen = i - start + 1;
                beg = start;
            }
            
            if(patt[s[start]]) {
                if(freq[s[start]] == 0)
                    matched--;
                
                freq[s[start]]++;
            }
            
            start++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(beg, minLen);
}

int main()
{
    string s, t;

    cout<<"Enter main string: ";
    getline(cin, s);

    cout<<"Enter the text for which the window is to be found: ";
    getline(cin, t);

    cout<<"Least sized window which contains the text: "<<smallestWindowForSubstring(s, t)<<endl;
}