/* Source - https://leetcode.com/problems/sliding-puzzle/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

 int slidingPuzzle(vector<vector<int>>& board) {
    int n = board.size();
    vector<vector<int>> swaps(n * board[0].size());
    
    swaps[0] = {1, 3};
    swaps[1] = {0, 2, 4};
    swaps[2] = {1, 5};
    swaps[3] = {0, 4};
    swaps[4] = {1, 3, 5};
    swaps[5] = {2, 4};
    
    string curr = "", solved = "123450";
    
    for(int i = 0; i < n; i++)
        curr += to_string(board[i][0]) + to_string(board[i][1]) + to_string(board[i][2]);     
    
    unordered_set<string> unique;
    queue<string> q;
    int moves = 0;
    
    unique.insert(curr);
    q.push(curr);
    
    while(!q.empty()) {
        int size = q.size();
        
        while(size--) {            
            string front = q.front();
            q.pop();

            if(front.compare(solved) == 0)
                return moves;

            int idxOfZ;

            for(int i = 0; i < front.length(); i++) {
                if(front[i] == '0') {
                    idxOfZ = i;
                    break;
                }
            }

            string original = front;

            for(int i = 0; i < swaps[idxOfZ].size(); i++) {
                int idx = swaps[idxOfZ][i];

                char temp = front[idx];
                front[idx] = front[idxOfZ];
                front[idxOfZ] = temp;

                if(unique.find(front) == unique.end()) {
                    unique.insert(front);
                    q.push(front);
                }

                front = original;
            }
        } 
        
        moves++;
    }
    
    return -1;
}

int main()
{
    vector<vector<int>> board(2, vector<int> (3));

    cout<<"Enter configuration of tiles in the board (0 represents empty square): "<<endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++)
            cin>>board[i][j];
    }

    cout<<"Least number of moves required so that the state of the board is solved: "<<slidingPuzzle(board)<<endl;
}