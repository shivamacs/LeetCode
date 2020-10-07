/* Source - https://leetcode.com/problems/number-of-1-bits/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    
    while(n != 0) {
        n &= (n - 1);
        count++;
    }
    
    return count;
}

int main()
{
    uint32_t n;

    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Count of set bits (using Kernighan's algorithm): "<<hammingWeight(n)<<endl;
}