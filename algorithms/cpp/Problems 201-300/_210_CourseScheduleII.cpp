/* Source - https://leetcode.com/problems/course-schedule-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, unordered_set<int>& visited, vector<bool>& recStack, stack<int>& st, int src) {
    visited.insert(src);
    recStack[src] = true;
    
    for(int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i];
        
        if(recStack[nbr])
            return true;
        
        if(visited.find(nbr) == visited.end()) {
            bool answer = dfs(graph, visited, recStack, st, nbr);
            
            if(answer)
                return true;
        }
    }
    
    st.push(src);
    recStack[src] = false;
    
    return false;
}    

// approach 1
vector<int> findOrderUsingDFS(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    
    for(int i = 0; i < prerequisites.size(); i++)
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    
    unordered_set<int> visited;
    stack<int> st;
    vector<bool> recStack(numCourses);
    
    for(int i = 0; i < graph.size(); i++) {
        if(visited.find(i) == visited.end()) {
            bool answer = dfs(graph, visited, recStack, st, i);

            if(answer == true)
                return {};
        }
    }
                
    if(visited.size() != numCourses)
        return {};
            
    vector<int> result;
    
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

// approach 2
vector<int> findOrderUsingKahnsAlgo(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    
    for(int i = 0; i < prerequisites.size(); i++)
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    
    vector<int> indegree(numCourses);
    
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[i].size(); j++)
            indegree[graph[i][j]]++;
    }
    
    queue<int> q;
    int count = 0;
    
    for(int i = 0; i < indegree.size(); i++) {
        if(indegree[i] == 0) {
            q.push(i);
            count++;
        }
    }
    
    vector<int> result;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        result.push_back(front);
        
        for(int i = 0; i < graph[front].size(); i++) {
            int nbr = graph[front][i];
            
            if(--indegree[nbr] == 0) {
                q.push(nbr);
                count++;
            }
        }
    }
    
    if(count != numCourses)
        return {};
    
    return result;
}

int main()
{
    int numCourses;

    cout<<"Enter number of courses: ";
    cin>>numCourses;

    int p;
    
    cout<<"Enter number of prerequisite pairs: ";
    cin>>p;

    vector<vector<int>> prerequisites(p);
    int f, s;

    cout<<"Enter prerequisite pairs: "<<endl;
    for(int i = 0; i < p; i++) {
        cin>>f>>s;
        prerequisites[i].push_back(f);
        prerequisites[i].push_back(s);
    }

    vector<int> result = findOrderUsingDFS(numCourses, prerequisites);
    
    cout<<"Correct ordering of courses to finish all courses (using DFS - recursive): [";
    if(result.size() > 0) {
        for(int i = 0; i < result.size() - 1; i++)
            cout<<result[i]<<", ";
        cout<<result[result.size() - 1];
    }
    cout<<"]"<<endl;

    result = findOrderUsingKahnsAlgo(numCourses, prerequisites);
    
    cout<<"Correct ordering of courses to finish all courses (using Kahn's Algo - iterative): [";
    if(result.size() > 0) {
        for(int i = 0; i < result.size() - 1; i++)
            cout<<result[i]<<", ";
        cout<<result[result.size() - 1];
    }
    cout<<"]"<<endl;
}