/* Source - https://leetcode.com/problems/rotate-image/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2) {
    int temp = matrix[x1][y1];
    matrix[x1][y1] = matrix[x2][y2];
    matrix[x2][y2] = temp;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < m; j++)
            swap(matrix, i, j, j, i);
    }    
    
    for(int j = 0, k = m - 1; j < k; j++, k--) {
        for(int i = 0; i < n; i++)
            swap(matrix, i, j, i, k);
    }   
}

int main()
{
    int n;
    
    cout<<"Enter the value of n: ";
    cin>>n;

    vector<vector<int>> matrix(n, vector<int> (n));

    cout<<"Enter elements row-wise: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>matrix[i][j];
    }

    rotate(matrix);

    cout<<"Matrix after rotating 90 degree clockwise: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}