// Leetcode -> 424. Longest Repeating Character Replacement
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int freq[26];
    int start = 0, maxRepeatSoFar = 0, maxLen = 0; 
    
    memset(freq, 0, sizeof(freq));
    
    for(int i = 0; i < s.length(); i++) {
        freq[s[i] - 'A']++;
        maxRepeatSoFar = max(maxRepeatSoFar, freq[s[i] - 'A']);
        
        if(i - start + 1 - maxRepeatSoFar > k) {
            freq[s[start] - 'A']--;
            start++;
        }
        
        maxLen = max(maxLen, i - start + 1);
    }
    
    return maxLen;
}

int main()
{   
    string s;

    cout<<"Enter a string (uppercase english letters): ";
    cin>>s;

    int k;

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Length of longest substring containing all repeating characters after at most "<<k<<" replacements: "<<characterReplacement(s, k)<<endl; 
}