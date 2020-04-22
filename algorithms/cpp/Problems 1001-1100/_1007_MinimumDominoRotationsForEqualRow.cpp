/* Source - https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

#define IM INT_MAX
    
int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int movesAZeroInA = 0, movesAZeroInB = 1, movesBZeroInB = 0, movesBZeroInA = 1;
    
    for (int i = 1; i < n; i++) {
        if (movesAZeroInA != IM)
        {
            if (A[i] != A[0])
            {
                if (B[i] == A[0])
                    movesAZeroInA++;
                else
                {
                    if (movesBZeroInB == IM)
                        return -1;
                    
                    movesAZeroInA = IM;
                    movesAZeroInB = IM;
                }
            }
            else if (B[i] != A[0])
                movesAZeroInB++;
        }

        if (movesBZeroInB != IM)
        {
            if (B[i] != B[0])
            {
                if (A[i] == B[0])
                    movesBZeroInB++;
                else 
                {
                    if (movesAZeroInA == IM)
                        return -1;
                    
                    movesBZeroInB = IM;
                    movesBZeroInA = IM;
                }
            }
            else if (A[i] != B[0])
                movesBZeroInA++;
        }
    }
    
    return min({movesAZeroInA, movesAZeroInB, movesBZeroInB, movesBZeroInA}); 
}

int main()
{
    int n;
    
    cout<<"Enter number of elements in a row of dominoes: ";
    cin>>n;

    vector<int> A(n), B(n);

    cout<<"Enter values for first row: ";
    for(int i = 0; i < n; i++)
        cin>>A[i];

    cout<<"Enter values for second row: ";
    for(int i = 0; i < n; i++)
        cin>>B[i];

    int result = minDominoRotations(A, B);

    if(result == -1)
        cout<<"No row can have equal elements with any number of rotations."<<endl;
    else
        cout<<"Minimum domino rotations for a row to have all equal elements: "<<result<<endl;
}