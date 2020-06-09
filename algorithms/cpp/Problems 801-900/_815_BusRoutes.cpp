/* Source - https://leetcode.com/problems/bus-routes/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int stop, cost;
    
    Pair(int s, int c) {
        stop = s;
        cost = c;
    }
};

int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {        
    unordered_map<int, vector<int>> stopsMap;
    int maxStop = 0;
    
    for(int i = 0; i < routes.size(); i++) {
        for(int j = 0; j < routes[i].size(); j++) {
            stopsMap[routes[i][j]].push_back(i);
            maxStop = max(maxStop, routes[i][j]);
        }
    }
        
    vector<bool> bVisited(routes.size()), sVisited(maxStop + 1);
    
    queue<Pair*> q;
    
    sVisited[S] = true;
    q.push(new Pair(S, 0));
    
    while(!q.empty()) {
        Pair *front = q.front();
        q.pop();
        
        if(front->stop == T)
            return front->cost;
        
        for(int i = 0; i < stopsMap[front->stop].size(); i++) {
            int bus = stopsMap[front->stop][i];
            
            if(!bVisited[bus]) {
                bVisited[bus] = true;

                for(int j = 0; j < routes[bus].size(); j++) {
                    int stop = routes[bus][j];
                    
                    if(!sVisited[stop]) {
                        sVisited[stop] = true;
                        q.push(new Pair(stop, front->cost + 1));
                    }
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    int n;

    cout<<"Enter number of buses: ";
    cin>>n;

    vector<vector<int>> routes(n);
    int m, s;

    for(int i = 0; i < n; i++) {
        cout<<"Enter number of stops covered by bus no. "<<i + 1<<": ";
        cin>>m;

        cout<<"Enter stops covered by bus no. "<<i + 1<<": ";
        for(int j = 0; j < m; j++) {
            cin>>s;
            routes[i].push_back(s);
        }
    }

    int S, T;

    cout<<"Enter start stop and destination stop: ";
    cin>>S>>T;

    cout<<"Least number of buses to take from start stop for reaching the destination: "<<numBusesToDestination(routes, S, T)<<endl;
}