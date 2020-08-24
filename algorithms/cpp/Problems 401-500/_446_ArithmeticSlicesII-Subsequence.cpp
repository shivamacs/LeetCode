#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size() < 3)
        return 0;
    
    int n = A.size(), slices = 0;
    unordered_map<long, int> dp[n];
    
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            long diff = long(A[i]) - long(A[j]);
            int prev = 0;
                
            if(dp[j].find(diff) != dp[j].end())
                prev = dp[j][diff];
            
            dp[i][diff] += prev + 1;
            slices += prev;
        }            
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

    cout<<"Count of sub-sequences having all its elements in A.P: "<<numberOfArithmeticSlices(A)<<endl;
}