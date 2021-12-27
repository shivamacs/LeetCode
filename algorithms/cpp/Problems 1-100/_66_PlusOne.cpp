/* Source - https://leetcode.com/problems/plus-one/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    bool carry = false;
    
    for(int i = n - 1; i >= 0; i--) {
        if(digits[i] == 9) {
            digits[i] = 0;
            carry = true;
        } else {
            digits[i] = digits[i] + 1;
            carry = false;
            break;
        }
    }
    
    if(carry) {
        vector<int> newDigits(n + 1);
        
        for(int i = 0; i < n; i++)
            newDigits[i + 1] = digits[i];
        
        newDigits[0] = 1;
        
        return newDigits;
    }
    
    return digits;
}

int main()
{
    int n;
    cout<<"Enter the length of digits: ";
    cin>>n;

    vector<int> digits(n);
    cout<<"Enter the elements in the array representing an integer: ";
    for(int i = 0; i < n; i++)
        cin>>digits[i];

    vector<int> result = plusOne(digits);
    cout<<"Result: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}