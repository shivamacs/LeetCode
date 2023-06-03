/* Source - https://leetcode.com/problems/course-schedule/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, vector< vector<int> >& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[src] = true;
    recStack[src] = true;
    
    for(int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i];
        
        if(recStack[nbr])
            return false;
        
        if(!visited[nbr]) {
            bool finish = dfs(nbr, graph, visited, recStack);
            
            if(!finish)
                return false;
        }
    }
    
    recStack[src] = false;
    return true;
}

bool canFinish(int numCourses, vector< vector<int> >& prerequisites) {
    vector< vector<int> > graph(numCourses);
    
    for(int p = 0; p < prerequisites.size(); p++)
        graph[prerequisites[p][0]].push_back(prerequisites[p][1]);
    
    vector<bool> visited(numCourses);
    vector<bool> recStack(numCourses);
    
    for(int n = 0; n < numCourses; n++) {
        if(!visited[n]) {
            bool finish = dfs(n, graph, visited, recStack);
            
            if(!finish)
                return false;
        }
    }
    
    return true;
}

int main()
{
    int numCourses;
    cout<<"Enter number of courses: ";
    cin>>numCourses;

    int p;
    cout<<"Enter number of prerequisites: ";
    cin>>p;

    vector< vector<int> > prerequisites(p, vector<int> (2));

    cout<<"Enter prerequisites: "<<endl;
    for(int i = 0; i < p; i++)
        cin>>prerequisites[i][0]>>prerequisites[i][1];

    cout<<"Can finish all the courses: "<<boolalpha<<canFinish(numCourses, prerequisites)<<endl;    
}