/* Source - https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<vector<int>>& graph, bool *visited, bool *recStack, stack<int>& st) {
    visited[src] = true;
    recStack[src] = true;
    
    for(int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i];
        
        if(recStack[nbr])
            return false;
        
        if(visited[nbr] == false && dfs(nbr, graph, visited, recStack, st) == false)
            return false;
    }
    
    st.push(src);
    recStack[src] = false;
    
    return true;
}

vector<int> topoSort(vector<vector<int>>& graph, int n, int m) {
    int N = n + (2 * m);
    bool visited[N];
    bool recStack[N];
    stack<int> st;
    
    memset(visited, false, sizeof(visited));
    memset(recStack, false, sizeof(recStack));
    
    for(int i = n; i < N; i++) {
        if(visited[i] == false && dfs(i, graph, visited, recStack, st) == false)
            return {};
    }
    
    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            bool recur[N];
            memset(recur, false, sizeof(recur));
            
            if(dfs(i, graph, visited, recur, st) == false)
                return {};
        }
    }
        
    vector<int> result;
    
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        
        if(top < n)
            result.push_back(top);
    }
        
    return result;
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    int N = n + (2 * m);
    vector<vector<int>> graph(N);
    
    for(int i = 0; i < group.size(); i++) {
        if(group[i] != -1) {
            graph[n + (2 * group[i])].push_back(i);
            graph[i].push_back(n + (2 * group[i] + 1));
        }
    }
        
    for(int i = 0; i < beforeItems.size(); i++) {
        for(int j = 0; j < beforeItems[i].size(); j++) {
            int b = beforeItems[i][j], g1 = group[b], g2 = group[i];
            
            if(g1 != g2) {
                if(g1 != -1 && g2 != -1)
                    graph[n + (2 * g1 + 1)].push_back(n + (2 * g2));
                else if(g1 != -1 && g2 == -1)
                    graph[n + (2 * g1 + 1)].push_back(i);
                else if(g1 == -1 && g2 != -1)
                    graph[b].push_back(n + (2 * g2));
            } else
                graph[b].push_back(i);
        }
    }
        
    return topoSort(graph, n, m);
}

int main()
{
    int n;

    cout<<"Enter number of items: ";
    cin>>n;

    int m;

    cout<<"Enter number of groups: ";
    cin>>m;

    vector<int> group(n);

    cout<<"Enter group numbers for each item (-1 if not present in any group): ";
    for(int i = 0; i < n; i++)
        cin>>group[i];

    vector<vector<int>> beforeItems(n);
    int p, q;

    cout<<"Enter before items for each item, "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"Enter number of before items for item "<<i<<": ";
        cin>>p;

        if(p > 0) {
            cout<<"Enter before items for item "<<i<<": ";
            for(int j = 0; j < p; j++) {
                cin>>q;
                beforeItems[i].push_back(q);
            }
        }
    }

    vector<int> result = sortItems(n, m, group, beforeItems);

    cout<<"Sorted list of items by respecting dependencies: [";
    if(result.size() != 0) {
        for(int i = 0; i < result.size() - 1; i++)
            cout<<result[i]<<", ";
        cout<<result[result.size() - 1];
    }
    cout<<"]"<<endl;
}