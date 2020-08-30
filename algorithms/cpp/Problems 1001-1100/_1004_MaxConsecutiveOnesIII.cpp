/* Source - https://leetcode.com/problems/max-consecutive-ones-iii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& A, int K) {
    int n = A.size();
    
    int start = 0, i = 0, z = 0, result = 0;
    
    while (i < n) {
        if (A[i] == 0) {
            z++;
            
            if (z > K) {
                while (A[start] != 0)
                    start++;
                
                start++;
                z = K;
            }
        }
        
        result = max(result, i - start + 1);
        
        i++;
    }
    
    return result;
}

int main()
{
    int n, K;
    
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Enter the value of K: ";
    cin>>K;

    cout<<"Max consecutive ones with atmost K zero flip: "<<longestOnes(nums, K)<<endl;
}