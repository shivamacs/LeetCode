/* Source - https://leetcode.com/problems/reverse-integer/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int ans = 0;
    
    while(x != 0) {
        int pop = x % 10;
        
        if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7))
            return 0;
        
        if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8))
            return 0;
        
        ans = ans * 10 + (x % 10);    
        x /= 10;
    }
    
    return ans;
}

int main()
{
    int x;
    
    cout<<"Enter an integer: ";
    cin>>x;

    cout<<"Reverse of "<<x<<" (0, if overflows): "<<reverse(x)<<endl;
}