/* Source - https://leetcode.com/problems/xor-operation-in-an-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int xorOperation(int n, int start) {
    int x = 0;
    
    for(int i = 0; i < n; i++)  
        x ^= (start + 2 * i);
    
    return x;
}

int main()
{
    int n, start;

    cout<<"Number of elements in the array: ";
    cin>>n;

    cout<<"Enter starting point: ";
    cin>>start;

    cout<<"XOR of all elements: "<<xorOperation(n, start)<<endl;
}