/* Source - https://leetcode.com/problems/grid-illumination/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    unordered_map<int, int> lRowCount;
    unordered_map<int, int> lColCount;
    unordered_map<int, int> lDiag1Count;
    unordered_map<int, int> lDiag2Count;
    
    unordered_set<string> lPositions;
    
    for (int i = 0; i < lamps.size(); i++) {
        lRowCount[lamps[i][0]]++;
        lColCount[lamps[i][1]]++;
        lDiag1Count[lamps[i][0] - lamps[i][1]]++;
        lDiag2Count[lamps[i][0] + lamps[i][1]]++;
        lPositions.insert(to_string(lamps[i][0]) + "*" + to_string(lamps[i][1]));
    }
    
    vector<int> result;
        
    for (int i = 0; i < queries.size(); i++) {
        int row = queries[i][0];
        int col = queries[i][1];
                    
        if (lRowCount.find(row) != lRowCount.end() || lColCount.find(col) != lColCount.end() 
            || lDiag1Count.find(row - col) != lDiag1Count.end() || lDiag2Count.find(row + col) != lDiag2Count.end()) {
            
            result.push_back(1);
                        
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    string pos = to_string(row + j) + "*" + to_string(col + k);

                    if (lPositions.find(pos) != lPositions.end()) {
                        int s = (row + j) + (col + k);
                        int d = (row + j) - (col + k);

                        if (--lRowCount[row + j] == 0) lRowCount.erase(row + j);
                        if (--lColCount[col + k] == 0) lColCount.erase(col + k);
                        if (--lDiag1Count[d] == 0) lDiag1Count.erase(d);
                        if (--lDiag2Count[s] == 0) lDiag2Count.erase(s);

                        lPositions.erase(pos);
                    }
                }
            }
        }
        
        else result.push_back(0);
    }
    
    return result;
}

int main()
{
    int N, l, q;
    
    cout<<"Enter grid size: ";
    cin>>N;
    
    cout<<"Enter number of lamps: ";
    cin>>l;

    int a, b;

    vector<vector<int>> lamps(l);
    
    cout<<"Enter lamp positions: "<<endl;
    for (int i = 0; i < l; i++) {
        cin>>a>>b;
        lamps[i].push_back(a);
        lamps[i].push_back(b);
    }

    cout<<"Enter number of queries: "<<endl;
    cin>>q;

    vector<vector<int>> queries(q);
    
    cout<<"Enter positions to query: ";
    for (int i = 0; i < q; i++) {
        cin>>a>>b;
        queries[i].push_back(a);
        queries[i].push_back(b);
    }

    vector<int> result = gridIllumination(N, lamps, queries);

    cout<<"Answers: ";
    for (int i = 0; i < result.size(); i++) cout<<result[i]<<" ";
    cout<<endl;
}