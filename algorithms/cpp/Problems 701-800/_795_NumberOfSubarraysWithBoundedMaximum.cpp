/* Source - https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    int n = A.size(), start = 0, i = 0, len = 0, count = 0;
    
    while (i < n) {
        if (A[i] >= L && A[i] <= R) {
            len = i - start + 1;
            count += len;
        }
        
        else { 
            if (A[i] < L)
                count += len;
        
            else if (A[i] > R) {
                len = 0;
                start = i + 1;
            }
        }
            
        i++;
    }
    
    return count;
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