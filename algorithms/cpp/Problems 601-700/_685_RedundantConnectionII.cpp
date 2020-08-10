/* Source - https://leetcode.com/problems/redundant-connection-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int dsFind(int i, unordered_map<int, int>& parent) {
    if(i == parent[i])
        return i;
    
    int result = dsFind(parent[i], parent);
    parent[i] = result;
    
    return result;
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

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size(), ignore1 = -1, ignore2 = -1;
    unordered_map<int, int> indegree;
    
    ignore1 = ignore2 = -1;
    
    for(int i = 0; i < n; i++) {
        int v2 = edges[i][1];
        
        if(indegree.find(v2) == indegree.end())
            indegree[v2] = i;
        else {
            ignore1 = i;
            ignore2 = indegree[v2];
            break;
        }
    }
            
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
        
        if(i != ignore1 && dsUnion(v1, v2, parent, rank) == false)
            return (ignore1 == -1) ? edges[i] : edges[ignore2];
    }
    
    return edges[ignore1];
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

    vector<int> result = findRedundantDirectedConnection(edges);

    cout<<"Redundant edge in the given directed graph: ["<<result[0]<<", "<<result[1]<<"]"<<endl;
}