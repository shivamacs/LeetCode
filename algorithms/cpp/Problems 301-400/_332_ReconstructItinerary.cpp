/* Source - https://leetcode.com/problems/reconstruct-itinerary/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(string src, 
         unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& routes,
         stack<string>& st) {
    
    while(!routes[src].empty()) {
        string nbr = routes[src].top();
        routes[src].pop();
        
        dfs(nbr, routes, st);
    }
    
    st.push(src);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> routes;
    
    for(int i = 0; i < tickets.size(); i++)
        routes[tickets[i][0]].push(tickets[i][1]);
    
    stack<string> st;
    dfs("JFK", routes, st);
    
    vector<string> result;
    
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

int main() {
    int n;

    cout<<"Enter number of airline tickets: ";
    cin>>n;

    vector<vector<string>> tickets(n);
    string s, d;

    cout<<"Enter source and destination for each ticket: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>s>>d;
        tickets[i] = {s, d};
    }

    vector<string> result = findItinerary(tickets);

    cout<<"Itinerary in order: [";
    for(int i = 0; i < result.size() - 1; i++)  
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<"]"<<endl;
}