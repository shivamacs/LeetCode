/* Source - https://leetcode.com/problems/spiral-matrix/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size() == 0)
        return {};
    
    vector<int> result;
    
    int n = matrix.size(), m = matrix[0].size(), k = 0, l = 0;
    
    while(k < n && l < m) {
        for(int j = l; j < m; j++)
            result.push_back(matrix[k][j]);
        k++;
        
        for(int i = k; i < n; i++)
            result.push_back(matrix[i][m - 1]);
        m--;
        
        if(k < n) {
            for(int j = m - 1; j >= l; j--)
                result.push_back(matrix[n - 1][j]);
            n--;
        }
        
        if(l < m) {
            for(int i = n - 1; i >= k; i--)
                result.push_back(matrix[i][l]);
            l++;
        }
    }
    
    return result;
}

int main()
{
    int n, m;

    cout<<"Enter dimensions: ";
    cin>>n>>m;
    
    vector<vector<int>> matrix(n, vector<int>(m));
    
    cout<<"Enter elements row-wise: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin>>matrix[i][j];
    }
    
    int k = 0, l = 0;
    
    vector<int> result = spiralOrder(matrix);
    
    cout<<"Spiral Display: [";
    if(result.size() > 0) {
        for(int i = 0; i < result.size() - 1; i++)
            cout<<result[i]<<", ";
        cout<<result[result.size() - 1];
    }
    cout<<"]"<<endl;
}