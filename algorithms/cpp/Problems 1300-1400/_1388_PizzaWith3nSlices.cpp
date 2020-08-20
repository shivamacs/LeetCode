/* Source - https://leetcode.com/problems/pizza-with-3n-slices/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& slices, int si, int ei, int k) {
    if(si > ei || k == 0)
        return 0;
    
    int n = ei - si + 1;
    int inc[k + 1][n], exc[k + 1][n];
    
    for(int j = 0; j < n; j++)
        inc[0][j] = exc[0][j] = 0;
    
    for(int i = 1; i <= k; i++) {
        inc[i][0] = slices[si];
        exc[i][0] = 0;
    }
    
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j < n; j++) {
            inc[i][j] = slices[si + j] + exc[i - 1][j - 1];
            exc[i][j] = max(inc[i][j - 1], exc[i][j - 1]);
        }
    }
    
    return max(inc[k][n - 1], exc[k][n - 1]);
}

int maxSizeSlices(vector<int>& slices) {
    int n = slices.size(), k = n / 3;
    
    return max(slices[0] + maxSum(slices, 2, n - 2, k - 1), maxSum(slices, 1, n - 1, k));
}

int main()
{
    int n;

    cout<<"Enter number of pizza slices (multiple of 3): ";
    cin>>n;

    vector<int> slices(n);

    cout<<"Enter size of each slice: ";
    for(int i = 0; i < n; i++)
        cin>>slices[i];

    cout<<"Maximum possible sum of slice sizes you can have: "<<maxSizeSlices(slices)<<endl;
}