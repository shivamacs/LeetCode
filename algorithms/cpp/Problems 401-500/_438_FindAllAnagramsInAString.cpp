/* Source - https://leetcode.com/problems/find-all-anagrams-in-a-string/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 256

vector<int> findAnagrams(string s, string p) {
    if (s.length() < p.length()) return {};
    if (s == p) return {0};

    vector<int> anagrams;

    int patFrequency[MAX] = {0}, winFrequency[MAX] = {0};
    int sLen = s.length(), pLen = p.length();
    int matchCount = 0;
    
    for (int i = 0; i < pLen; i++)
        patFrequency[p[i]]++;
    
    for (int i = 0; i < pLen; i++) {
        winFrequency[s[i]]++;
        
        if (patFrequency[s[i]] >= winFrequency[s[i]])
            matchCount++;
    }

    if (pLen == sLen && matchCount == pLen) {
        anagrams.push_back(0);
        return anagrams;
    }
    
    for (int i = pLen; i < sLen; i++) {
        if (matchCount == pLen) anagrams.push_back(i - pLen);
        
        winFrequency[s[i]]++;
        if (patFrequency[s[i]] >= winFrequency[s[i]]) matchCount++;
        
        --winFrequency[s[i - pLen]];
        if (patFrequency[s[i - pLen]] > winFrequency[s[i - pLen]]) matchCount--;
    }
    
    if (matchCount == pLen) anagrams.push_back(sLen - pLen);
    
    return anagrams;
}

int main()
{
    string s, p;

    cout<<"Enter string: ";
    getline(cin, s);

    cout<<"Enter pattern: ";
    getline(cin, p);

    vector<int> result = findAnagrams(s, p);

    cout<<"Anagrams are found at starting indices: ";
    for (int i = 0; i < result.size(); i++) cout<<result[i]<<" ";
    cout<<endl;
}