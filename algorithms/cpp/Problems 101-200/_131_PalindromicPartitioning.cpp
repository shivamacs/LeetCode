/* Source - https://leetcode.com/problems/palindrome-partitioning/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    
    while(i < j) {
        if(s[i] != s[j])
            return false;
        
        i++;
        j--;
    }
    
    return true;
}

void helper(int si, int ei, string s, bool** isPalin, vector<string>& asf, vector<vector<string>>& ans) {
    if(si > ei) {
        ans.push_back(asf);
        return;
    }
    
    for(int i = si; i <= ei; i++) {
        string curr = s.substr(si, i - si + 1);
        
        if(isPalin[si][i]) {
            asf.push_back(curr);
            helper(i + 1, ei, s, isPalin, asf, ans);
            asf.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int n = s.length();
    bool** isPalin = new bool*[n];
    
    for(int i = 0; i < n; i++) {
        isPalin[i] = new bool[n];
        
        for(int j = 0; j < n; j++)
            isPalin[i][j] = false;
    }
        
    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(k == 0)
                isPalin[i][j] = true;
            else if(k == 1)
                isPalin[i][j] = (s[i] == s[j] ? true : false);
            else 
                isPalin[i][j] = (s[i] == s[j] ? isPalin[i + 1][j - 1] : false);
        }
    }
    
    vector<string> asf;
    vector<vector<string>> ans;
        
    helper(0, s.length() - 1, s, isPalin, asf, ans);
        
    return ans;
}

int main()
{
    string str;

    cout<<"Enter a string: ";
    cin>>str;

    vector<vector<string>> ans = partition(str);
    cout<<"Partitions of the string such that all partitions are palindromic: "<<endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}