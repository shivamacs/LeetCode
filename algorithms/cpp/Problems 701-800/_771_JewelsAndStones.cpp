/* Source - https://leetcode.com/problems/jewels-and-stones/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> jewelSet;
    int count = 0;
    
    for(char jewel : jewels)
        jewelSet.insert(jewel);
    
    for(char stone : stones) {
        if(jewelSet.find(stone) != jewelSet.end())
            count++;
    }
    
    return count;
}

int main()
{
    string jewels, stones;
    cout<<"Enter the jewels string: ";
    cin>>jewels;
    cout<<"Enter the stones string: ";
    cin>>stones;

    cout<<"Number of stones that are jewels: "<<numJewelsInStones(jewels, stones)<<endl;
}