/* Source - https://leetcode.com/problems/redundant-connection/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int dsFind(int i, unordered_map<int, int>& parent) {
    if(i == parent[i])
        return i;
    else {
        int result = dsFind(parent[i], parent);
        parent[i] = result;
        
        return result;
    }
}

bool dsUnion(int x, int y, unordered_map<int, int>& parent, unordered_map<int, int>& rank) {
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
        
        return true;
    }
    
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int, int> parent, rank;
    
    for(int i = 0; i < n; i++) {
        int v1 = edges[i][0], v2 = edges[i][1];
        
        if(parent.find(v1) == parent.end()) {
            parent[v1] = v1;
            rank[v1] = 1;
        }
        
        if(parent.find(v2) == parent.end()) {
            parent[v2] = v2;
            rank[v2] = 1;
        }
        
        if(dsUnion(v1, v2, parent, rank) == false)
            return {v1, v2};
    }
    
    return {};
}

int main()
{
    int n;

    cout<<"Enter number of edges: ";
    cin>>n;

    vector<vector<int>> edges(n);
    int v1, v2;

    cout<<"Enter edges: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>v1>>v2;
        edges[i] = {v1, v2};    
    }

    vector<int> result = findRedundantConnection(edges);

    cout<<"Redundant edge: ["<<result[0]<<", "<<result[1]<<"]"<<endl;
}