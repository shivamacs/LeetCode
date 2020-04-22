/* Source - https://leetcode.com/problems/squares-of-a-sorted-array/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
    int n = A.size();
    vector<int> squares(n);
    
    int i = 0, j = n - 1;
    
    while (i != j) {            
        if ((A[i] * A[i]) > (A[j] * A[j])) {
            squares[j - i] = A[i] * A[i];
            i++;
        }
        
        else {
            squares[j - i] = A[j] * A[j];
            j--;
        }
    }
    
    squares[0] = A[i] * A[i];
            
    return squares;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin>>A[i];

    vector<int> squares = sortedSquares(A);

    cout<<"Sorted squares of the given array: ";
    for (int i = 0; i < squares.size(); i++)
        cout<<squares[i]<<" ";
    cout<<endl;
}