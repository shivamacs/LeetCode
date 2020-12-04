/* Source - https://leetcode.com/problems/word-pattern/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    int n = pattern.length(), k = 0;
    unordered_map<char, string> pMap;
    unordered_set<string> strSet;
    
    for(int i = 0; i < n; i++) {
        char ch = pattern[i];
        string temp = "";
        
        while(k < s.length() and s[k] != ' ') {
            temp += s[k];
            k++;
        }
        
        k++;
        
        if(pMap.find(ch) == pMap.end() && strSet.find(temp) == strSet.end()) {
            pMap[ch] = temp;
            strSet.insert(temp);
        } else if(pMap.find(ch) != pMap.end()) {
            if(pMap[ch].compare(temp) != 0)
                return false;
        } else if(strSet.find(temp) != strSet.end())
            return false;
    }
    
    return k == s.length() + 1;
}

int main()
{
    string pattern, s;

    cout<<"Enter pattern: ";
    cin>>pattern;

    cout<<"Enter string s: ";
    getline(cin>>ws, s);

    cout<<"Does the string follow the same pattern? "<<boolalpha<<wordPattern(pattern, s)<<endl;
}