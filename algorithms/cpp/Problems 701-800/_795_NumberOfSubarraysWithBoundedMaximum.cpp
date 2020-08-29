/* Source - https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int n = A.size(), prevValid = 0, start = 0, ans = 0;
        
    for(int i = 0; i < n; i++) {
        if(A[i] >= L && A[i] <= R) {
            ans += i - start + 1;
            prevValid = i - start + 1;
        } else if(A[i] < L)
            ans += prevValid;
        else if(A[i] > R) {
            start = i + 1;
            prevValid = 0;
        }
    }
    
    return ans;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);
    int L, R;

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>A[i];

    cout<<"Enter left and right bounds: ";
    cin>>L>>R;

    cout<<"Number of subarrays with bounded maximum: "<<numSubarrayBoundedMax(A, L, R)<<endl;
}