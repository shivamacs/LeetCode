/* Source - https://leetcode.com/problems/01-matrix/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int x[4] = {0, -1, 0, 1};
int y[4] = {-1, 0, 1, 0};

struct Element {
    int x, y, cost;
    
    Element(int i, int j, int c) {
        x = i;
        y = j;
        cost = c;
    }
};

void bfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& answer) {
    queue<Element> q;
    q.push(Element(i, j, 0));
            
    while(!q.empty()) {
        Element front = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int r = front.x + x[k], c = front.y + y[k];
            
            if(r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || (r == i && c == j))
                continue;
                            
            if(matrix[r][c] == 0) {
                answer[i][j] = front.cost + 1;
                return;
            } else {
                q.push(Element(r, c, front.cost + 1));
            }
        }
    }
}

// approach 1
vector<vector<int>> updateMatrixApproach1(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> answer(m, vector<int> (n));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1)
                bfs(i, j, matrix, answer);
        }
    }
    
    return answer;
}

// approach 2
vector<vector<int>> updateMatrixApproach2(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> answer(m, vector<int> (n));
    queue<Element> q;
    int onesCount = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0)
                q.push(Element(i, j, 0));
            else
                onesCount++;
        }
    }
                    
    while(!q.empty()) {
        Element front = q.front();
        q.pop();

        answer[front.x][front.y] = front.cost;
        
        for(int k = 0; k < 4; k++) {
            int r = front.x + x[k], c = front.y + y[k];
            
            if(r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size())
                continue;
                            
            if(matrix[r][c] == 1) {
                matrix[r][c] = 0;
                q.push(Element(r, c, front.cost + 1));
                onesCount--;
            }
            
            if(onesCount == 0)
                break;
        }
    }
    
    return answer;
}

int main()
{
    int m, n;

    cout<<"Enter dimensions of the matrix: ";
    cin>>m>>n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    
    cout<<"Enter values row-wise (0 or 1): "<<endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin>>matrix[i][j];
    }

    vector<vector<int>> answer = updateMatrixApproach1(matrix);
    
    cout<<"Distance of the nearest 0 for each cell (using approach 1): "<<endl;
    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < answer[i].size(); j++)
            cout<<answer[i][j]<<" ";
        cout<<endl;
    }
    
    answer = updateMatrixApproach2(matrix);
    
    cout<<"Distance of the nearest 0 for each cell (using approach 2): "<<endl;
    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < answer[i].size(); j++)
            cout<<answer[i][j]<<" ";
        cout<<endl;
    }
}