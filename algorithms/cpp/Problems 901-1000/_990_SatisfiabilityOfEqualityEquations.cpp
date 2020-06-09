/* Source - https://leetcode.com/problems/satisfiability-of-equality-equations/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int dsFind(int i, vector<int>& parent) {
    if(parent[i] == i)
        return i;
    
    int result = dsFind(parent[i], parent);
    parent[i] = result;
    
    return result;
}

void dsUnion(int x, int y, vector<int>& parent, vector<int>& rank) {
    int px = dsFind(x, parent);
    int py = dsFind(y, parent);
    
    if(px != py) {
        if(rank[px] > rank[py])
            parent[py] = px;
        else if(rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
}

bool equationsPossible(vector<string>& equations) {
    vector<int> parent(26);
    vector<int> rank(26);
    
    for(int i = 0; i < 26; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    
    for(int i = 0; i < equations.size(); i++) {
        int c1 = equations[i][0] - 'a', c2 = equations[i][3] - 'a';
        
        if(equations[i][1] == '=' && equations[i][2] == '=') {
            dsUnion(c1, c2, parent, rank);
        } else if(c1 == c2)
            return false;
    }
    
    for(int i = 0; i < equations.size(); i++) {
        int c1 = equations[i][0] - 'a', c2 = equations[i][3] - 'a';
            
        if(equations[i][1] == '!' && equations [i][2] == '=' && dsFind(c1, parent) == dsFind(c2, parent))
            return false;
    }
    
    return true;
}

int main()
{
    int n;

    cout<<"Enter the number of equations: ";
    cin>>n;

    vector<string> equations(n);

    cout<<"Enter equations (length of each equation string must be 4): "<<endl;
    for(int i = 0; i < n; i++)
        cin>>equations[i];

    cout<<"All equations satisfied? "<<boolalpha<<equationsPossible(equations)<<endl;
}