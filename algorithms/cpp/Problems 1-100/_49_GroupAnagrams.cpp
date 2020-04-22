/* Source - https://leetcode.com/problems/group-anagrams/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 102
#define ALPHA_SIZE 26

void fillPrimesUsingSOE(int *alphaPrime) {
    string s = "abcdefghijklmnopqrstuvwxyz";

    bool IsPrime[MAX];  
    memset(IsPrime, true, sizeof(IsPrime));  
    
    for (int i = 2; i * i < MAX; i++)  
    {  
        if (IsPrime[i] == true) {
            for (int k = i * i; k < MAX; k += i)  
                IsPrime[k] = false;
        }  
    }

    int i = 0;
    for (int j = 2; j < MAX; j++)  
       if (IsPrime[j]) alphaPrime[s[i++] - 'a'] = j;
}  

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<unsigned long, vector<string>> stringHash;
    unordered_map<unsigned long, vector<string>>::iterator iter;
    
    int alphaPrime[ALPHA_SIZE] = {0};
    
    fillPrimesUsingSOE(alphaPrime);
    
    for (int i = 0; i < strs.size(); i++) {
        unsigned long primeProd = 1;
        
        for (int j = 0; j < strs[i].size(); j++) 
            primeProd *= alphaPrime[strs[i][j] - 'a'];
        
        stringHash[primeProd].push_back(strs[i]);
    }
    
    vector<vector<string>> result;
    
    for (iter = stringHash.begin(); iter != stringHash.end(); ++iter)
        result.push_back(iter->second);
    
    return result;
}
int main()
{
    int n;

    cout<<"Enter number of strings: ";
    cin>>n;

    vector<string> strs(n);
    
    cout<<"Enter strings: "<<endl;
    for (int i = 0; i < n; i++) cin>>strs[i];

    vector<vector<string>> result = groupAnagrams(strs);

    cout<<"Group of anagrams: "<<endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) cout<<result[i][j]<<" ";
        cout<<endl;
    }

}