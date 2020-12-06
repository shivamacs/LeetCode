/* Source - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string codes[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
vector<string> helper(string digits) {
    if(digits.length() == 0)
        return {""};
    
    int ch = digits[0] - '0' - 2;
    
    vector<string> rem = helper(digits.substr(1));
    vector<string> result;
            
    for(int i = 0; i < codes[ch].length(); i++) {
        for(int j = 0; j < rem.size(); j++)
            result.push_back(codes[ch][i] + rem[j]);
    }
    
    return result;
}

vector<string> letterCombinations(string digits) {
    if(digits.length() == 0)
        return {};
    
    return helper(digits);
}

int main() 
{
    string digits;

    cout<<"Enter phone number (string): ";
    cin>>digits;

    vector<string> result = letterCombinations(digits);
    
    cout<<"All letter combinations of "<<digits<<": [";
    if(result.size() > 0) {
        for(int i = 0; i < result.size() - 1; i++)
            cout<<result[i]<<", ";
        cout<<result[result.size() - 1];
    }
    cout<<"]"<<endl;
}