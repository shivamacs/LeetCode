/* Source - https://leetcode.com/problems/can-i-win/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isWinPossible(int curr, int target, int m, int* dp) {
    if(dp[curr] != -1)
        return dp[curr];
                
    if(target <= 0)
        return false;
                    
    for(int i = 1; i <= m; i++) {
        int mask = 1 << (i - 1);
                                    
        if((curr & mask) == 0 && isWinPossible((curr | mask), target - i, m, dp) == false) {
            dp[curr] = 1;
            return true;
        }
    }
    
    dp[curr] = 0;
    
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(desiredTotal <= 0)
        return true;
    
    if((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 < desiredTotal)
        return false;
    
    int currState = 0;
    int dp[1 << maxChoosableInteger];
    
    memset(dp, -1, sizeof(dp));
        
    return isWinPossible(currState, desiredTotal, maxChoosableInteger, dp);
}

int main()
{
    int maxChoosableInteger, desiredTotal;

    cout<<"Enter maximum integer that can be chosen: ";
    cin>>maxChoosableInteger;

    cout<<"Enter the desired total: ";
    cin>>desiredTotal;

    cout<<"Can the first player to move win? "<<boolalpha<<canIWin(maxChoosableInteger, desiredTotal)<<endl;
}