/* Source - https://www.lintcode.com/problem/range-addition/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    vector<int> arr(length, 0);
    int prefixSum = 0;
    
    arr.push_back(0);
    
    for (int i = 0; i < updates.size(); i++) {
        arr[updates[i][0]] += updates[i][2];
        arr[updates[i][1] + 1] -= updates[i][2];
    }
    
    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        arr[i] = prefixSum;
    }
    
    arr.pop_back();
    
    return arr;
}

int main()
{
    int length, q;

    cout<<"Enter length of array: ";
    cin>>length;

    cout<<"Enter number of queries/updates: ";
    cin>>q;

    vector<vector<int>> updates(q);
    int s, e, v;

    cout<<"Enter update operations: "<<endl;
    for (int i = 0; i < q; i++) {
        cin>>s>>e>>v;
        updates[i].push_back(s);
        updates[i].push_back(e);
        updates[i].push_back(v);
    }

    vector<int> modified = getModifiedArray(length, updates);

    cout<<"Modified array: ";
    for (int i = 0; i < modified.size(); i++)
        cout<<modified[i]<<" ";
    cout<<endl;
}