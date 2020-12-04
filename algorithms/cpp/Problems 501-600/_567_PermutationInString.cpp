/* Source - https://leetcode.com/problems/permutation-in-string/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int n = s1.length(), m = s2.length(), matched = 0, count = 0;
    int freq[26];
    bool patt[26];
    
    memset(freq, 0, sizeof(freq));
    memset(patt, false, sizeof(patt));
    
    for(int i = 0; i < n; i++) {
        freq[s1[i] - 'a']++;
        
        if(patt[s1[i] - 'a'] == false) {
            count++;
            patt[s1[i] - 'a'] = true;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int ch = s2[i] - 'a';
        
        if(patt[ch]) {
            freq[ch]--;
            
            if(freq[ch] == 0)
                matched++;
        }
        
        if(matched == count)
            return true;
        
        if(i >= n - 1) {
            int temp = s2[i - n + 1] - 'a';
            
            if(patt[temp]) {
                if(freq[temp] == 0)
                    matched--;
                
                freq[temp]++;
            }
        }
    }
                    
    return false;
}

int main()
{
    string s1, s2;

    cout<<"Enter pattern: ";
    cin>>s1;

    cout<<"Enter string: ";
    cin>>s2;

    cout<<"Does "<<s2<<" contain any permutation of "<<s1<<"? "<<boolalpha<<checkInclusion(s1, s2)<<endl;
}