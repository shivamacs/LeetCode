/* Source - https://leetcode.com/problems/search-a-2d-matrix/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int left = 0, right = m * n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n;
        int col = mid % n;
        
        if(matrix[row][col] == target)
            return true;
        
        if(matrix[row][col] < target)
            left = mid + 1;    
        else
            right = mid - 1;
    }
    
    return false;
}

int main()
{
    int m, n;
    cout<<"Enter dimensions of the matrix: ";
    cin>>m>>n;

    vector< vector<int> > matrix(m, vector<int> (n));

    cout<<"Enter elements in the matrix row-wise: "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin>>matrix[i][j];
    }

    int target;
    cout<<"Enter target element to be found: ";
    cin>>target;

    cout<<"Target found? "<<boolalpha<<searchMatrix(matrix, target)<<endl;
}