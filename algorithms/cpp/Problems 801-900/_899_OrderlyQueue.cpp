/* Source - https://leetcode.com/problems/orderly-queue/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string orderlyQueue(string S, int K) {
    if (K == 1) {
        int n = S.length();
        string lex_min = S;
        
        while (n-- > 0) {
            S = S.substr(1) + S[0];
            
            if (S.compare(lex_min) < 0)
                lex_min = S;
        }
        
        return lex_min;
    }
    
    else sort(S.begin(), S.end());
    
    return S;
}

int main()
{
    string S;
    int K;

    cout<<"Enter string: ";
    cin>>S;

    cout<<"Enter the value of K: ";
    cin>>K;

    cout<<"Lexicographically smallest possible string after any number of moves: "<<orderlyQueue(S, K);
}