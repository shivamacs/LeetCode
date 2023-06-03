/*  Source - https://leetcode.com/problems/set-matrix-zeroes/
    Author - Shivam Arora
*/
#include <iostream>
#include <vector>

void nullifyRow(std::vector<std::vector<int>>& matrix, int row) {
    for(int j = 0; j < matrix[0].size(); j++)
        matrix[row][j] = 0;
}

void nullifyColumn(std::vector<std::vector<int>>& matrix, int col) {
    for(int i = 0; i < matrix.size(); i++)
        matrix[i][col] = 0;
}

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowHasZero = false;
    bool firstColHasZero = false;
    
    for(int j = 0; j < n; j++) {
        if(matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }
    
    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < m; i++)
        if(matrix[i][0] == 0)
            nullifyRow(matrix, i);
    
    for(int j = 1; j < n; j++)
        if(matrix[0][j] == 0)
            nullifyColumn(matrix, j);
    
    if(firstRowHasZero)
        nullifyRow(matrix, 0);

    if(firstColHasZero)
        nullifyColumn(matrix, 0);
}

int main() {
    int m, n;
    std::cout<<"Enter the dimensions of the matrix: ";
    std::cin>>m>>n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    std::cout<<"Enter the values in the matrix: "<<std::endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            std::cin>>matrix[i][j];
    }

    setZeroes(matrix);

    std::cout<<"Matrix after setting zeroes: "<<std::endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            std::cout<<matrix[i][j]<<" ";
        std::cout<<std::endl;
    }
}