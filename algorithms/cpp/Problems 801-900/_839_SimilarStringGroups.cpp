/* Source - https://leetcode.com/problems/similar-string-groups/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int dsFind(int i, int *parent) {
    if(i == parent[i])
        return i;
    
    int result = dsFind(parent[i], parent);
    parent[i] = result;
    
    return result;
}

void dsUnion(int x, int y, int *parent, int *rank, int& sets) {
    int px = dsFind(x, parent);
    int py = dsFind(y, parent);
    
    if(px != py) {
        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        
        sets--;
    }
}

int numSimilarGroups(vector<string>& A) {
    int n = A.size();
    int parent[n], rank[n];
    
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    
    int sets = n, compare, len = A[0].length();
    
    for(int i = 0; i < n; i++) {            
        for(int j = i + 1; j < n; j++) {
            string str1 = A[i], str2 = A[j];
            compare = 0;
            
            for(int k = 0; k < len; k++) {
                if(str1[k] != str2[k])
                    compare++;
            } 
                            
            if(compare <= 2)
                dsUnion(i, j, parent, rank, sets);
        }
    }
    
    return sets;
}

int main()
{
    int n;

    cout<<"Enter number of strings: ";
    cin>>n;

    vector<string> A(n);

    cout<<"Enter strings: ";
    for(int i = 0; i < n; i++)
        cin>>A[i];

    cout<<"Number of groups of similar strings: "<<numSimilarGroups(A)<<endl;
}