/* Source - https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    
    if (a == 1 || b == 1) return 1;
    
    if (a == b) return a;
    
    if (a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}

bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> freqMap;
    unordered_map<int, int>::iterator iter;
            
    for (int i = 0; i < deck.size(); i++) freqMap[deck[i]]++;
    
    int i = 0, X = 0;
                
    for (iter = freqMap.begin(); iter != freqMap.end(); ++iter)
        X = gcd(iter->second, X);
    
    if (X >= 2) return true;
    
    return false;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> deck(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < deck.size(); i++) cin>>deck[i];

    bool result = hasGroupsSizeX(deck);

    if (result == true) cout<<"A number X >= 2 CAN ";
    else cout<<"A number X >= 2 CANNOT ";
    cout<<"be chosen such that the entire deck contains 1 or more groups of X cards."<<endl;
} 