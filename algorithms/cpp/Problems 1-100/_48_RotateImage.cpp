/* Source - https://leetcode.com/problems/rotate-image/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverse(vector<vector<int>>& matrix, int row) {
    int n = matrix.size();
    
    int s = 0, e = n - 1;
    while (s <= e) {
        swap(matrix[row][s], matrix[row][e]);
        
        s++;
        e--;
    }
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int i = 0; i < n; i++)
        reverse(matrix, i);
    
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        int r = n - 1, c = 0;
        
        while (r > i && c < j) {
            swap(matrix[i][c], matrix[r][j]);
            
            r--;
            c++;
        }
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