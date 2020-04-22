/* Source - https://leetcode.com/problems/shortest-palindrome/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string reverse (string s) {
    int n = s.length();
    
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    
    return s;
}

int longestPrefixSuffix(string s) {
    int i = 1, len = 0;
    vector<int> lps(s.length());
    
    lps[0] = 0;
    
    while (i < s.length()) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        
        else {
            if (len > 0) len = lps[len - 1];
            
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps[s.length() - 1];
}

string shortestPalindrome(string s) {
    string temp = s + "#" + reverse(s);
    
    int p = longestPrefixSuffix(temp);
    
    string rem = s.substr(p);
    
    return reverse(rem) + s;
}

int main() {
    string s;

    cout<<"Enter string: ";
    cin>>s;

    cout<<"Shortest palindrome after minimum insertions: "<<shortestPalindrome(s)<<endl;
}