/* Source - https://leetcode.com/problems/minimum-window-substring/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 256

string smallestWindowForSubstring(string s, string t) {
    if (s.length() < t.length()) return "-1";
    
    int textFreq[MAX] = {0}, windowFreq[MAX] = {0};
    string window, minWindow = "";
    int winStart = 0, matchCount = 0, minLength = INT_MAX;

    int sLen = s.length(), tLen = t.length();

    for (int i = 0; i < tLen; i++)
        textFreq[t[i]]++;

    for (int i = 0; i < sLen; i++) {
        windowFreq[s[i]]++;
    
        if (textFreq[s[i]] != 0 && textFreq[s[i]] >= windowFreq[s[i]]) matchCount++;

        if (matchCount == tLen) {
            while (textFreq[s[winStart]] < windowFreq[s[winStart]] || textFreq[s[winStart]] == 0) {
                if (textFreq[s[winStart]] < windowFreq[s[winStart]]) windowFreq[s[winStart]]--;
                winStart++;
            }

            window = s.substr(winStart, i - winStart + 1);
        
            if (window.length() < minLength) {
                minWindow = window;
                minLength = window.length();
            }
        }
    }

    return minWindow != "" ? minWindow : "-1";
}

int main()
{
    string s, t;

    cout<<"Enter main string: ";
    getline(cin, s);

    cout<<"Enter the text for which the window is to be found: ";
    getline(cin, t);

    cout<<"Least sized window which contains the text: "<<smallestWindowForSubstring(s, t)<<endl;
}