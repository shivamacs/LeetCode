/* Source - https://www.lintcode.com/problem/number-of-islands-ii/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};

int dsFind(int i, vector<int>& parent) {
    if(parent[i] == i)
        return i;
    else {
        int result = dsFind(parent[i], parent);
        parent[i] = result;
        
        return result;
    }
}

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dsUnion(vector<vector<int>>& grid, vector<int>& parent, vector<int>& rank, int x, int y, int& count) {
    grid[x][y] = 1;
    int w = grid[0].size();
    
    for(int i = 0; i < dirs.size(); i++) {
        int curr = dsFind((x * w) + y, parent);
        int a = x + dirs[i].first, b = y + dirs[i].second;
    
        if(a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == 1) {
            int adj = dsFind((a * w) + b, parent);
            
            if(curr != adj) {
                if(rank[curr] > rank[adj])
                    parent[adj] = curr;
                else if(rank[curr] < rank[adj])
                    parent[curr] = adj;
                else {
                    parent[curr] = adj;
                    rank[adj]++;
                }
                
                count--;
            }
        }
    }
}

vector<int> numIslands2(int n, int m, vector<Point> &operators) {
    vector<vector<int>> grid(n, vector<int> (m));
    int size = n * m;
    vector<int> parent(size, -1);
    vector<int> rank(size, 1);
    
    vector<int> result;
    int count = 0;
    
    for(int i = 0; i < operators.size(); i++) {
        int idx = (operators[i].x * m) + operators[i].y;
        
        if(parent[idx] == -1) {
            parent[idx] = idx;
            count++;
            dsUnion(grid, parent, rank, operators[i].x, operators[i].y, count);
        }
        
        result.push_back(count);
    }
    
    return result;
}

int main()
{
    int n, m;
    cout<<"Enter grid dimensions: ";
    cin>>n>>m;

    int k;

    cout<<"Enter number of operators: ";
    cin>>k;

    vector<Point> operators;
    int x, y;

    cout<<"Enter operators (x-coordinate y-coordinate): "<<endl;
    for(int i = 0; i < k; i++) {
        cin>>x>>y;
        operators.push_back(Point(x, y));
    }

    vector<int> result = numIslands2(n, m, operators);

    cout<<"Output: [";
    for(int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<"]"<<endl;
}