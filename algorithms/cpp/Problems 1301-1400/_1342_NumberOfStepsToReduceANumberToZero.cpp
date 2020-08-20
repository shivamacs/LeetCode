/* Source - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numberOfSteps (int num) {
    int count = 0;
    
    while(num > 0) {
        num = (num % 2 == 0) ? num / 2 : num - 1;
        count++;
    }
    
    return count;
}

int main()
{
    int num;
    
    cout<<"Enter a number: ";
    cin>>num;

    cout<<"Number of steps to reduce "<<num<<" to 0: "<<numberOfSteps(num)<<endl;
}