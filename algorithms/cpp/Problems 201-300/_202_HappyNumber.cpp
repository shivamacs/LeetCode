/* Source - https://leetcode.com/problems/happy-number/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int digitSquareSum(int n) {
    int sum = 0;
    
    while(n != 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    
    if (slow == 1)
        return true;
    
    return false;
}

int main()
{
    int n;

    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Is "<<n<<" a happy number? "<<boolalpha<<isHappy(n)<<endl;
}