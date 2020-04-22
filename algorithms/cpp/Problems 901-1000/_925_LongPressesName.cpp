/* Source - https://leetcode.com/problems/long-pressed-name/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;
    
    while (j < typed.length()) {
        if (name[i] == typed[j]) {
            i++;
            j++;
        }
        
        else {
            if (typed[j] == typed[j - 1]) j++;
            
            else return false;
        }
    }
    
    if (i == name.length() && j == typed.length())
        return true;

    return false;
}

int main()
{
    string name, typed;

    cout<<"Enter original name: ";
    cin>>name;

    cout<<"Enter typed name: ";
    cin>>typed;

    bool result = isLongPressedName(name, typed);

    if (result == true) cout<<"Typed string is a valid long pressed name.";
    else cout<<"Typed string is an invalid long pressed name.";
    cout<<endl;
}