/* Source - https://leetcode.com/problems/search-a-2d-matrix-ii
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector< vector<int> >& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m - 1;
    
    while(i >= 0 && i < n && j >= 0 && j < m) {
        if(matrix[i][j] == target)
            return true;
        
        if(matrix[i][j] < target)
            i++;
        else
            j--;
    }
    
    return false;
}

int main()
{
    int m, n;
    cout<<"Enter the dimensions of the matrix: ";
    cin>>m>>n;

    vector< vector<int> > matrix(m, vector<int> (n));
    cout<<"Enter the elements in the matrix row-wise: "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin>>matrix[i][j];
    }

    int target;
    cout<<"Enter the target element: ";
    cin>>target;

    cout<<"Is target found? "<<boolalpha<<searchMatrix(matrix, target)<<endl;
}