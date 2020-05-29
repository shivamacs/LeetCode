/* Source - https://leetcode.com/problems/global-and-local-inversions/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isIdealPermutation(vector<int>& A) {
    for(int i = 0; i < A.size(); i++)
        if(abs(A[i] - i) > 1)
            return false;
    
    return true;
}

int main()
{
    int n;
    
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>A[i];

    cout<<"Number of global inversions = number of local inversions? "<<boolalpha<<isIdealPermutation(A)<<endl;
}