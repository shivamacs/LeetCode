/* Source - https://leetcode.com/problems/substring-with-concatenation-of-all-words/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    int wc = words.size(), wl = words[0].length();
    unordered_map<string, int> freqMap;
    vector<int> result;
    
    for(string word : words)
        freqMap[word]++;
    
    int last = s.length() - wc * wl;
    
    for(int i = 0; i <= last; i++) {
        unordered_map<string, int> wordsSeen;
        
        for(int j = 0; j < wc; j++) {
            string word = s.substr(i + j * wl, wl);
            
            if(freqMap.find(word) == freqMap.end())
                break;
            
            wordsSeen[word]++;
            
            if(wordsSeen[word] > freqMap[word])
                break;
            
            if(j + 1 == wc)
                result.push_back(i);
        }
    }
    
    return result;
}

int main()
{   
    string s;
    
    cout<<"Enter a string: ";
    cin>>s;

    int n;

    cout<<"Enter number of words: ";
    cin>>n;

    vector<string> words(n);

    cout<<"Enter the words: ";
    for(int i = 0; i < n; i++)
        cin>>words[i];
    
    vector<int> result = findSubstring(s, words);

    cout<<"Starting indices of substrings that are concatenation of all the words: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<" "; 
    cout<<endl;
}