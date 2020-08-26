/* Source - https://leetcode.com/problems/word-break/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    bool dp[n + 1];
    
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    
    for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(dp[j]) {
                string sub = s.substr(j, i - j);
                
                if(dict.find(sub) != dict.end())
                    dp[i] = true;
            }
        }
    }
        
    return dp[n];
}

int main()
{
    string s;
    
    cout<<"Enter a string: ";
    cin>>s; 

    int n;

    cout<<"Enter number of words in the dictionary: ";
    cin>>n;

    vector<string> wordDict(n);

    cout<<"Enter words: ";
    for(int i = 0; i < n; i++)
        cin>>wordDict[i];

    cout<<"Can the string be segmented into space separated sequence of one or more dictionary words? "<<boolalpha<<wordBreak(s, wordDict)<<endl; 
}