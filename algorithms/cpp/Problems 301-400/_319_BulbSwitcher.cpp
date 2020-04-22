/* Source - https://leetcode.com/problems/bulb-switcher/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int bulbSwitch(int& n) {
    return sqrt(n);
}

int main()
{
    int n;
    
    cout<<"Enter number of bulbs (initially off): ";
    cin>>n;

    cout<<"Number of bulbs which are on after n rounds: "<<bulbSwitch(n)<<endl;
}