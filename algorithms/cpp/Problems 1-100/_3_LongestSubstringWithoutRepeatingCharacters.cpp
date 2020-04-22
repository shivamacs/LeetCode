/* Source - https://leetcode.com/problems/longest-substring-without-repeating-characters/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> freqMap;
    int length = 0, longest = 0;
    
    int i = 0, j = 0;

    while (j < s.length()) {
        freqMap[s[j]]++;
            
        while (freqMap[s[j]] != 1) {
            freqMap[s[i]]--;
            i++;
        }
        
        length = j - i + 1;
        if (length > longest) longest = length;
        
        j++;
    }
    
    return longest;
}

int main()
{
    string s;

    cout<<"Enter string: ";
    cin>>s;

    cout<<"Length of longest substring: "<<lengthOfLongestSubstring(s)<<endl;
}