/* Source - https://leetcode.com/problems/powx-n/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    if(n == 0)
        return 1;
    
    if(n < 0)
        x = (1/x);
    
    double oddProduct = 1;
    
    while(n != 1 && n != -1) {
        if(n % 2 != 0)
            oddProduct *= x;
            
        x *= x;
        n /= 2;
    }
    
    return x * oddProduct;
}

int main()
{
    int x, n;

    cout<<"Enter the value of base and exponent: ";
    cin>>x>>n;

    cout<<"Pow (x, n): "<<myPow(x, n)<<endl;
}