/* Source - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minScoreTriangulation(vector<int>& A) {
    int n = A.size();
    int dp[n][n];
    
    memset(dp, 0, sizeof(dp));
    
    for(int k = 2; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(k == 2)
                dp[i][j] = A[i] * A[i + 1] * A[j];
            else {
                dp[i][j] = INT_MAX;

                for(int cut = i + 1; cut < j; cut++)
                    dp[i][j] = min(dp[i][j], dp[i][cut] + (A[i] * A[cut] * A[j]) + dp[cut][j]);
            }
        }
    }
    
    return dp[0][n - 1];
}

int main()
{
    int n;

    cout<<"Enter number of sides: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter value of each vertex: ";
    for(int i = 0; i < n; i++)
        cin>>A[i];

    cout<<"Minimum score of triangulation for a convex polygon of "<<n<<" sides: "<<minScoreTriangulation(A)<<endl;
}