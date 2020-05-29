/* Source - https://leetcode.com/problems/is-graph-bipartite/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool _isBipartite(int s, vector<vector<int>>& graph, vector<int>& visited, int A, int B) {
    queue<int> q;
    
    visited[s] = A;
    q.push(s);
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < graph[front].size(); i++) {
            int neighbour = graph[front][i];
            
            if(visited[neighbour] == -1) {
                if(visited[front] == A)
                    visited[neighbour] = B;
                else
                    visited[neighbour] = A;
                
                q.push(neighbour);
            } else if(visited[front] == A && visited[neighbour] != B)
                    return false;
            else if (visited[front] == B && visited[neighbour] != A)
                    return false;
        }
    }
        
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int A = graph.size(), B = graph.size() + 1;
    vector<int> visited(graph.size(), -1);
    
    for(int i = 0; i < graph.size(); i++) {
        if(visited[i] == -1) {
            bool result = _isBipartite(i, graph, visited, A, B);
        
            if(result == false)
                return false;
        }
    }
    
    return true;
}

int main()
{
    int n;

    cout<<"Enter number of vertices: ";
    cin>>n;

    vector<vector<int>> graph(n);
    int m, a;
 
    for(int i = 0; i < n; i++) {
        cout<<"Enter number of neighbours of vertex "<<i<<": ";
        cin>>m;
        
        if(m > 0) {
            cout<<"Enter neighbours of vertex "<<i<<": ";
            for(int j = 0; j < m; j++) {
                cin>>a;
                graph[i].push_back(a);
            }
        }        
    }

    cout<<"Is Graph Bipartite? "<<boolalpha<<isBipartite(graph)<<endl;
}