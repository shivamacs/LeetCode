/* Source - https://leetcode.com/problems/frog-jump/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool canCross(vector<int>& stones) {
    int n = stones.size();
    unordered_map<int, int> indexMap;
    
    for(int i = 0; i < n; i++)
        indexMap[stones[i]] = i;
    
    bool dp[n][n + 1];
    
    memset(dp, false, sizeof(dp));
    dp[0][1] = true;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j]) {
                int next = indexMap[stones[i] + j];
                
                if(indexMap.find(stones[next]) != indexMap.end()) {
                    if(j - 1 > 0)
                        dp[next][j - 1] = true;

                    dp[next][j] = true;
                    dp[next][j + 1] = true;
                }
            }
        }
    }
    
    for(int j = 0; j < n; j++) {
        if(dp[n - 1][j])
            return true;
    }
    
    return false;
}

int main()
{
    int n;

    cout<<"Enter number of stones: ";
    cin>>n;

    vector<int>stones(n);

    cout<<"Enter stones' positions: ";
    for(int i = 0; i < n; i++)
        cin>>stones[i];

    cout<<"Can frog cross the river? "<<boolalpha<<canCross(stones)<<endl;
}