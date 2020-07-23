/* Source - https://leetcode.com/problems/word-ladder/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    
    q.push(make_pair(beginWord, 0));
    
    while(!q.empty()) {
        pair<string, int> front = q.front();
        q.pop();
                    
        if(front.first.compare(endWord) == 0)
            return front.second + 1;
        
        string curr = front.first;
                                
        for(int i = 0; i < curr.length(); i++) {
            for(int j = 0; j < 26; j++) {
                curr[i] = char(j + 'a');
                if(wordSet.find(curr) != wordSet.end()) {
                    q.push(make_pair(curr, front.second + 1));                       
                    wordSet.erase(curr);
                }
            }
            
            curr[i] = front.first[i];
        }
    }
    
    return 0;
}

int main()
{
    string beginWord, endWord;

    cout<<"Enter begin word: ";
    cin>>beginWord;

    cout<<"Enter end word: ";
    cin>>endWord;

    int n;

    cout<<"Enter number of words in the dictionary: ";
    cin>>n;

    vector<string> wordList(n);

    cout<<"Enter dictionary words: ";
    for(int i = 0; i < n; i++)
        cin>>wordList[i];

    cout<<"Shortest transformation sequence length from "<<beginWord<<" to "<<endWord<<": "<<ladderLength(beginWord, endWord, wordList)<<endl;
}