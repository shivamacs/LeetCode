/* Source - https://leetcode.com/problems/knight-probability-in-chessboard/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int xDir[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int yDir[8] = {2, 1, -2, -1, 2, 1, -2, -1};

double knightProbability(int N, int K, int r, int c) {
    double dp[K + 1][N][N];
    
    memset(dp, 0, sizeof(dp));
    dp[0][r][c] = 1;
    
    for(int move = 1; move <= K; move++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dp[move - 1][i][j] != 0) {
                    for(int d = 0; d < 8; d++) {
                        int x = i + xDir[d], y = j + yDir[d];
                        
                        if(x >= 0 && x < N && y >= 0 && y < N)
                            dp[move][x][y] += dp[move - 1][i][j] / 8.0;
                    }
                }
            }
        }
    }
    
    double answer = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            answer += dp[K][i][j];
    }
    
    return answer;
}

int main()
{
    int N, r, c, K;

    cout<<"Enter the value of N: ";
    cin>>N;

    cout<<"Enter the value of K: ";
    cin>>K;

    cout<<"Enter starting row and column: ";
    cin>>r>>c;
    
    cout<<"Probability that the knight remains on the board: "<<knightProbability(N, K, r, c)<<endl;
}