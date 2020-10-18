/* Source - https://leetcode.com/problems/sum-of-distances-in-tree/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int node, dist;
    
    Pair(int n, int d) {
        node = n;
        dist = d;
    }
};

int countNodes(int src, unordered_map<int, vector<int>>& nbrMap, bool* visited, int* ncount) {
    visited[src] = true;
    
    if(ncount[src] != 0)
        return ncount[src];
    
    for(int nbr : nbrMap[src]) {
        if(visited[nbr] == false)
            ncount[src] += countNodes(nbr, nbrMap, visited, ncount);
    }
    
    return ncount[src] += 1;
}

int getTotalDistance(int root, unordered_map<int, vector<int>>& nbrMap, bool* visited) {
    queue<Pair*> q;
    int total = 0;
    
    visited[root] = true;
    q.push(new Pair(root, 0));
    
    while(!q.empty()) {
        Pair* front = q.front();
        q.pop();
        
        total += front->dist;
        
        for(int nbr : nbrMap[front->node]) {
            if(visited[nbr] == false) {
                visited[nbr] = true;
                q.push(new Pair(nbr, front->dist + 1));
            }
        }
    }
    
    return total;
}

void calcDistances(int src, int N, unordered_map<int, vector<int>>& nbrMap, int* ncount, vector<int>& result) {        
    for(int nbr : nbrMap[src]) {
        if(result[nbr] == 0) {
            result[nbr] = result[src] - ncount[nbr] + (N - ncount[nbr]);
            calcDistances(nbr, N, nbrMap, ncount, result);
        }
    }
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> nbrMap;
    
    for(int i = 0; i < edges.size(); i++) {
        nbrMap[edges[i][0]].push_back(edges[i][1]);
        nbrMap[edges[i][1]].push_back(edges[i][0]);
    }
    
    int* ncount = new int[N];
    bool visited[N];
    
    for(int i = 0; i < N; i++)
        ncount[i] = 0;
    memset(visited, false, sizeof(visited));        
    countNodes(0, nbrMap, visited, ncount);
    
    memset(visited, false, sizeof(visited));        
    int total = getTotalDistance(0, nbrMap, visited);
    
    vector<int> result(N);

    result[0] = total;
    calcDistances(0, N, nbrMap, ncount, result);
    
    return result;
}

int main()
{
    int N;

    cout<<"Enter number of nodes: ";
    cin>>N;

    int m;

    cout<<"Enter number of edges: ";
    cin>>m; 

    vector<vector<int>> edges(m, vector<int> (2));

    cout<<"Enter edges: "<<endl;
    for(int i = 0; i < m; i++) {
        cin>>edges[i][0];
        cin>>edges[i][1];
    }

    vector<int> result = sumOfDistancesInTree(N, edges);

    cout<<"Sum of distances in tree from each node: [";
    for(int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<"]"<<endl;
}