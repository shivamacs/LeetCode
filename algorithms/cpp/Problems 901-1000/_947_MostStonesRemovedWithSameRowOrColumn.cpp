/* Source - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int dsFind(int i, unordered_map<int, int>& parent) {
    if(parent[i] == i)
        return i;
    
    int result = dsFind(parent[i], parent);
    parent[i] = result;
    
    return result;
}

void dsUnion(int x, int y, unordered_map<int, int>& parent, unordered_map<int, int>& rank, int& count) {
    int px = dsFind(x, parent);
    int py = dsFind(y, parent);
    
    if(px != py) {
        if(rank[px] > rank[py])
            parent[py] = px;
        else if(rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
        
        count--;
    }
}

int removeStones(vector<vector<int>>& stones) {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int count = 0;
    
    for(int i = 0; i < stones.size(); i++) {
        int r = stones[i][0], c = -stones[i][1] - 1;
        
        if(parent.find(r) == parent.end()) {
            parent[r] = r;
            rank[r] = 1;
            count++;
        } if(parent.find(c) == parent.end()) {
            parent[c] = c;
            rank[c] = 1;
            count++;
        }
        
        dsUnion(r, c, parent, rank, count);
    }
    
    return stones.size() - count;
}

int main()
{
    int n;

    cout<<"Enter number of stones: ";
    cin>>n;

    vector<vector<int>> stones(n);
    int x, y;

    cout<<"Enter coordinates of each stone (x y): "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>x>>y;
        stones[i] = {x, y};
    }

    cout<<"Largest possible number of moves (most stones that can be removed): "<<removeStones(stones)<<endl;
}