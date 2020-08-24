#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size() < 3)
        return 0;
    
    int n = A.size(), prev = A[1] - A[0], dp[n], slices = 0;
    
    memset(dp, 0, sizeof(dp));
    
    for(int i = 2; i < n; i++) {
        int curr = A[i] - A[i - 1];
        
        if(curr == prev) {
            dp[i] = dp[i - 1] + 1;
            slices += dp[i];
        }
        
        prev = curr;
    }
    
    return slices;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>A[i];

    cout<<"Count of arithmetic slices: "<<numberOfArithmeticSlices(A)<<endl;
}