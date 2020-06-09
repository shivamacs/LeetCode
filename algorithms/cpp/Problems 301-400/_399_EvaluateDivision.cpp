/* Source - https://leetcode.com/problems/evaluate-division/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Pair {
    string nbr;
    double val;
    
    Pair(string n, double v) {
        nbr = n;
        val = v;
    }
};

double _evaluateApproach1(unordered_map<string, vector<Pair*>> graph, unordered_map<string, bool> visited, 
                string src, string dest, double cost) {
    visited[src] = true;
    
    if(src == dest)
        return cost;
                            
    for(int i = 0; i < graph[src].size(); i++) {
        Pair *n = graph[src][i];
                    
        if(!visited[n->nbr]) {
            double answer = _evaluateApproach1(graph, visited, n->nbr, dest, cost * n->val);
            
            if(answer != -1)
                return answer;
        }
    }
                
    return -1;
}

double evaluateApproach1(unordered_map<string, vector<Pair*>> graph, string src, string dest) {
    if(graph.find(src) == graph.end() || graph.find(dest) == graph.end())
        return -1;
    
    if(src == dest)
        return 1;
            
    unordered_map<string, bool> visited;
        
    return _evaluateApproach1(graph, visited, src, dest, 1);
}

// approach 1
vector<double> calcEquationApproach1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<Pair*>> graph;
    
    for(int i = 0; i < equations.size(); i++) {
        graph[equations[i][0]].push_back(new Pair(equations[i][1], values[i]));
        graph[equations[i][1]].push_back(new Pair(equations[i][0], (1 / values[i])));
    }
    
    vector<double> result;
    
    for(int i = 0; i < queries.size(); i++)
        result.push_back(evaluateApproach1(graph, queries[i][0], queries[i][1]));
    
    return result;
}

void _evaluateApproach2(unordered_map<string, vector<Pair*>> graph,
                        unordered_map<string, pair<double, int>>& valueMap,
                        unordered_map<string, bool>& visited, string src) {
    visited[src] = true;
                                
    for(int i = 0; i < graph[src].size(); i++) {
        Pair *n = graph[src][i];
                    
        if(!visited[n->nbr]) {
            valueMap[n->nbr] = make_pair((valueMap[src].first / n->val), valueMap[src].second);
            _evaluateApproach2(graph, valueMap, visited, n->nbr);
        }
    }
}

void evaluateApproach2(unordered_map<string, vector<Pair*>> graph, unordered_map<string, pair<double, int>>& valueMap) {        
    unordered_map<string, bool> visited;
    
    int comp = 1;
    
    for(auto iter = graph.begin(); iter != graph.end(); ++iter) {
        if(!visited[iter->first]) {
            valueMap[iter->first].first = 1;
            valueMap[iter->first].second = comp;
            
            _evaluateApproach2(graph, valueMap, visited, iter->first);
            
            comp++;
        }
    }
}

// approach 2
vector<double> calcEquationApproach2(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<Pair*>> graph;
    
    for(int i = 0; i < equations.size(); i++) {
        graph[equations[i][0]].push_back(new Pair(equations[i][1], values[i]));
        graph[equations[i][1]].push_back(new Pair(equations[i][0], (1.0 / values[i])));
    }
            
    unordered_map<string, pair<double, int>> valueMap;
    
    evaluateApproach2(graph, valueMap);
    
    vector<double> result;
    
    for(int i = 0; i < queries.size(); i++) {
        if(valueMap.find(queries[i][0]) == valueMap.end() 
        || valueMap.find(queries[i][1]) == valueMap.end()
        || valueMap[queries[i][0]].second != valueMap[queries[i][1]].second)
            result.push_back(-1);
        else
            result.push_back(valueMap[queries[i][0]].first / valueMap[queries[i][1]].first);
    }
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter number of equations: ";
    cin>>n;

    vector<vector<string>> equations(n);
    string num, den;

    cout<<"Enter numerator and denominator for each equation: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>num>>den;
        equations[i].push_back(num);
        equations[i].push_back(den);
    }

    vector<double> values(n);
    double val;

    cout<<"Enter values associated with each equation: "<<endl;
    for(int i = 0; i < n; i++)
        cin>>values[i];

    int q;

    cout<<"Enter number of queries: ";
    cin>>q;

    vector<vector<string>> queries(q);

    cout<<"Enter numerator and denominator for each query: "<<endl;
    for(int i = 0; i < q; i++) {
        cin>>num>>den;
        queries[i].push_back(num);
        queries[i].push_back(den);
    }

    vector<double> result = calcEquationApproach1(equations, values, queries);

    cout<<"Output using approach 1 (each query calls DFS): [";
    for(int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<"]"<<endl;

    result = calcEquationApproach2(equations, values, queries);

    cout<<"Output using approach 2 (only one call to DFS): [";
    for(int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<"]"<<endl;
}