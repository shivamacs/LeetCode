/* Source - https://leetcode.com/problems/partition-array-into-disjoint-intervals/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int partitionDisjoint(vector<int>& A) {
    int currentMax = A[0], overallMax = A[0], pIndex = 0;
    
    for (int i = 1; i < A.size(); i++) {
        if (A[i] < currentMax) {
            pIndex = i;
            currentMax = overallMax;
        }
        
        else if (A[i] > currentMax)
            overallMax = max(overallMax, A[i]);
    }
    
    return pIndex + 1;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>A[i];

    cout<<"Minimum length of left partition such that the partitions are disjoint: "<<partitionDisjoint(A)<<endl;
}