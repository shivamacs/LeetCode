/* Source - https://leetcode.com/problems/reverse-vowels-of-a-string/
   Author - Shivam Arora
*/

#include <bits/stdc++.h>
using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

bool isVowel(char c) {
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
        return true;
    
    return false;
}

string reverseVowels(string s) {
    int i = 0, j = s.length() - 1;
    
    while (i <= j) {
        if (isVowel(s[i]) && isVowel(s[j])) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        
        else if (!isVowel(s[i]))
            i++;
        
        else if (!isVowel(s[j]))
            j--;
        
        else {
            i++;
            j--;
        }
    }
    
    return s;
}

int main()
{
    string s;

    cout<<"Enter string: ";
    getline(cin>>ws, s);

    cout<<"Given string with vowels reversed: "<<reverseVowels(s)<<endl;
}