/* Source - https://leetcode.com/problems/pascals-triangle-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    if (rowIndex == 0)
        return {1};
    
    vector<int> perm = {1, 1};
    
    while (rowIndex-- > 1) {
        int n = perm.size();
        vector<int> temp(n + 1);
        
        temp[0] = perm[0];
        temp[n] = perm[n - 1];
        
        for (int i = 1; i < n; i++)
            temp[i] = perm[i - 1] + perm[i];
        
        perm = temp;
    }
    
    return perm;
}

vector<int> getRowOptimised(int rowIndex) {
    vector<int> row(rowIndex + 1);
    
    row[0] = 1;
    
    for (int i = 1; i <= rowIndex; i++) {
        row[i] = ((rowIndex - i + 1) * long(row[i - 1])) / i; 
    }
    
    return row;
}

int main()
{
    int rowIndex;

    cout<<"Enter row index: ";
    cin>>rowIndex;

    vector<int> result = getRow(rowIndex);

    cout<<"Pascal triangle's row for given index: ";
    for (int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;

    result = getRowOptimised(rowIndex);

    cout<<"Pascal triangle's row for given index using formula: ";
    for (int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}