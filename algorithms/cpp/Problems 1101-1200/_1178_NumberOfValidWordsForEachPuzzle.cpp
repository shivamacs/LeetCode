/* Source - https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int hashString(string word) {
    int rpr = 0;

    for(int i = 0; i < word.length(); i++)
        rpr |= (1 << (word[i] - 'a'));

    return rpr;
}

// optimised by using input constraints (puzzle.length <= 7)
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    unordered_map<int, int> wordsHashCount;
    vector<int> ans;
    
    for(int i = 0; i < words.size(); i++) {
        int h = hashString(words[i]);
        wordsHashCount[h]++;
    }
    
    for(int i = 0; i < puzzles.size(); i++) {
        int hp = hashString(puzzles[i]);
        int first = 1 << (puzzles[i][0] - 'a');
        int count = 0;
        
        int sub = hp;
        
        while(sub) {
            if((sub & first) == first && wordsHashCount.find(sub) != wordsHashCount.end())
                count += wordsHashCount[sub];
            
            sub = (sub - 1) & hp;
        }
        
        ans.push_back(count);    
    }
    
    return ans;
}

int main()
{
    int n;

    cout<<"Enter number of words: ";
    cin>>n;

    vector<string> words(n);

    cout<<"Enter words: ";
    for(int i = 0; i < n; i++)
        cin>>words[i];

    int m;

    cout<<"Enter number of puzzles: ";
    cin>>m;

    vector<string> puzzles(m);

    cout<<"Enter puzzles: ";
    for(int i = 0; i < m; i++)
        cin>>puzzles[i];

    vector<int> result = findNumOfValidWords(words, puzzles);

    cout<<"Count of valid words for each puzzle: [";
    for(int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<"]"<<endl;
}