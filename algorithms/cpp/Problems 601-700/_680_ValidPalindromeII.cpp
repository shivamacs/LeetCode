/* Source - https://leetcode.com/problems/valid-palindrome-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s) {
    int n = s.length(), i = 0, j = n - 1;
    
    while(i <= j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else
            return false;
    }
    
    return true;
}

bool validPalindrome(string s) {
    int n = s.length(), i = 0, j = n - 1;

    while (i <= j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            if (checkPalindrome(s.substr(i + 1, j - i)) || checkPalindrome(s.substr(i, j - i)))
                return true;
            
            return false;
        }
    }
    
    return true;
}

int main()
{
    string s;

    cout<<"Enter a string: ";
    cin>>s;

    cout<<"Given string a valid palindrome when atmost 1 deletion is allowed? "<<boolalpha<<validPalindrome(s)<<endl;
}