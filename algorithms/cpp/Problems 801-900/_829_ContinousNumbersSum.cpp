/* Source - https://leetcode.com/problems/consecutive-numbers-sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int consecutiveNumbersSum(int N) {
    int k = ceil(sqrt(2 * N)), answer = 0;
    
    for(int i = 1; i < k; i++) {
        if((N - i * (i - 1) / 2) % i == 0)
            answer++;
    }
    
    return answer;
}

int main()
{
    int N;

    cout<<"Enter a number: ";
    cin>>N;

    cout<<"Number of ways to represent "<<N<<" as a sum of consecutive positive integers: "<<consecutiveNumbersSum(N)<<endl;
}