/* Source - https://leetcode.com/problems/game-of-life/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int liveNeighbours(vector< vector<int> >& board, int m, int n, int i, int j) {
    int lives = 0;
    
    for(int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
        for(int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++)
            lives += board[x][y] & 1;
    }
    
    return lives - (board[i][j] & 1);
}

void gameOfLife(vector< vector<int> >& board) {
    int m = board.size();
    int n = board[0].size();
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int lives = liveNeighbours(board, m, n, i, j);
            
            if(board[i][j] == 1 && lives >= 2 && lives <= 3)
                board[i][j] = 3;
            
            if(board[i][j] == 0 && lives == 3)
                board[i][j] = 2;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            board[i][j] >>= 1;
    }
}

int main()
{
    int m, n;

    cout<<"Enter the dimensions of the board: ";
    cin>>m>>n;

    vector< vector<int> > board(m, vector<int> (n));

    cout<<"Enter the values in the cells row-wise (0/1): "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin>>board[i][j];
    }

    gameOfLife(board);

    cout<<"Updated board: "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}