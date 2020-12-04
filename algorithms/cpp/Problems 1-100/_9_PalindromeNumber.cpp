/* Source - https://leetcode.com/problems/palindrome-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0|| (x > 0 && x % 10 == 0))
        return false;
    
    int rev = 0;
    
    while(x > rev) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    
    return (x == rev) || (x == rev / 10);
}

int main()
{
    int x;

    cout<<"Enter an integer: ";
    cin>>x;

    cout<<"Is the given integer a palindrome? "<<boolalpha<<isPalindrome(x)<<endl;
}