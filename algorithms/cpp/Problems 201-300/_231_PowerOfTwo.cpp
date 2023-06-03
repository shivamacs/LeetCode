/* Source - https://leetcode.com/problems/power-of-two/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & n - 1) == 0;
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<boolalpha<<"Is "<<n<<", a power of 2? "<<isPowerOfTwo(n)<<endl;
}