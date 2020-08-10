/* Source - https://leetcode.com/problems/possible-bipartition/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int src, vector<vector<int>>& graph, int *visited) {
    int N = graph.size(), A = N, B = N + 1;
    queue<int> q;
    
    visited[src] = A;
    q.push(src);
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(int i = 0; i < graph[front].size(); i++) {
            int nbr = graph[front][i];
            
            if(visited[nbr] == -1) {
                if(visited[front] == A)
                    visited[nbr] = B;
                else
                    visited[nbr] = A;
                
                q.push(nbr);
            } else if(visited[front] == A && visited[nbr] != B)
                return false;
            else if(visited[front] == B && visited[nbr] != A)
                return false;
        }
    }
    
    return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(N);
    
    for(int i = 0; i < dislikes.size(); i++) {
        int v1 = dislikes[i][0] - 1, v2 = dislikes[i][1] - 1;
        
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    int visited[N];
    
    memset(visited, -1, sizeof(visited));
    
    for(int i = 0; i < N; i++) {
        if(visited[i] == -1) {
            if(isBipartite(i, graph, visited) == false)
                return false;
        }
    }
    
    return true;
}

int main()
{
    int N;

    cout<<"Enter number of people: ";
    cin>>N;

    int m;

    cout<<"Enter number of dislikes: ";
    cin>>m;

    vector<vector<int>> dislikes(m);
    int p1, p2;

    cout<<"Enter dislikes: "<<endl;
    for(int i = 0; i < m; i++) {
        cin>>p1>>p2;
        dislikes[i] = {p1, p2};
    }

    cout<<"Is it possible to split everyone into two groups? "<<boolalpha<<possibleBipartition(N, dislikes)<<endl;
}