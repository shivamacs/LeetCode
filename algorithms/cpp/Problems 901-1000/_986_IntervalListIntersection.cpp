/* Source - https://leetcode.com/problems/interval-list-intersections/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    int i = 0, j = 0;
    vector<vector<int>> result;
    
    while(i < A.size() && j < B.size()) {
        if(A[i][0] >= B[j][0] && A[i][0] <= B[j][1] || B[j][0] >= A[i][0] && B[j][0] <= A[i][1])
            result.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
        
        if(A[i][1] < B[j][1])
            i++;
        else
            j++;
    }
    
    return result;
}

int main()
{
    int n1, n2;

    cout<<"Enter number of intervals in A: ";
    cin>>n1;

    vector<vector<int>> A(n1, vector<int> (2));

    cout<<"Enter intervals in A: "<<endl;
    for(int i = 0; i < n1; i++)
        cin>>A[i][0]>>A[i][1];        

    cout<<"Enter number of intervals in B: ";
    cin>>n2;

    vector<vector<int>> B(n2, vector<int> (2));

    cout<<"Enter intervals in B: "<<endl;
    for(int i = 0; i < n2; i++)
        cin>>B[i][0]>>B[i][1];

    vector<vector<int>> result = intervalIntersection(A, B);

    cout<<"Intersection of given two lists: "<<endl;
    for(int i = 0; i < result.size(); i++)
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
}