/* Source - https://leetcode.com/problems/find-all-anagrams-in-a-string/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int n = s.length(), m = p.length(), matched = 0, count = 0;
    int freq[26];
    bool patt[26];
    vector<int> result;
    
    memset(freq, 0, sizeof(freq));
    memset(patt, false, sizeof(patt));
    
    for(int i = 0; i < m; i++) {
        freq[p[i] - 'a']++;
        
        if(patt[p[i] - 'a'] == false) {
            count++;
            patt[p[i] - 'a'] = true;
        }
    }
    
    for(int i = 0; i < n; i++) {
        int ch = s[i] - 'a';
        
        if(patt[ch]) {
            freq[ch]--;
            
            if(freq[ch] == 0)
                matched++;
        }
        
        if(matched == count)
            result.push_back(i - m + 1);
        
        if(i >= m - 1) {
            int temp = s[i - m + 1] - 'a';
            
            if(patt[temp]) {
                if(freq[temp] == 0)
                    matched--;
                
                freq[temp]++;
            }
        }
    }
                    
    return result;
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