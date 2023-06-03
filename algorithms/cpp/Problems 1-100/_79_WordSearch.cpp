/*  Source - https://leetcode.com/problems/word-search/
    Author - Shivam Arora
*/
#include <iostream>
#include <vector>

int xDir[4] = {0, -1, 1, 0};
int yDir[4] = {-1, 0, 0, 1};

bool _exists(int sr, int sc, std::vector<std::vector<char>>& board, int& m, int& n, std::string word) {
    if(board[sr][sc] != word[0])
        return false;

    std::string remaining = word.substr(1);

    if(remaining.length() == 0)
        return true;

    char curr = board[sr][sc];
    board[sr][sc] = '*';

    for(int d = 0; d < 4; d++) {
        int x = sr + xDir[d];
        int y = sc + yDir[d];

        if(x < 0 || x == m || y < 0 || y == n)
            continue;

        if(board[x][y] != '*') {
            bool wordExists = _exists(x, y, board, m, n, remaining);
            if(wordExists)
                return true;
        }
    }

    board[sr][sc] = curr;

    return false;
}

bool exists(std::vector<std::vector<char>>& board, std::string word) {
    int m = board.size();
    int n = board[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            bool wordExists = _exists(i, j, board, m, n, word);
            if(wordExists)
                return true;
        }
    }

    return false;
}

int main() {
    int m, n;
    std::cout<<"Enter the dimensions of the matrix: ";
    std::cin>>m>>n;

    std::vector<std::vector<char>> board(m, std::vector<char>(n));
    std::cout<<"Enter the characters in the grid row-wise: "<<std::endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            std::cin>>board[i][j];
    }

    std::string word;
    std::cout<<"Enter the word to be searched for: ";
    std::cin>>word;

    std::cout<<std::boolalpha<<exists(board, word)<<std::endl;
}