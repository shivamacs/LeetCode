/* Source - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    typedef pair<int, pair<int, int>> rcv;
    priority_queue<rcv, vector<rcv>, greater<rcv>> minHeap;
    rcv top;
    
    int n = matrix.size();
    
    for (int i = 0; i < matrix.size(); i++)
        minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
    
    while (k-- > 1) {
        top = minHeap.top();
        minHeap.pop();
        
        int row = top.second.first;
        int col = top.second.second;
        
        if (col + 1 <= n - 1)
            minHeap.push(make_pair(matrix[row][col + 1], make_pair(row, col + 1)));
    }
                            
    return minHeap.top().first;
}

int main()
{
    int n;
    
    cout<<"Enter matrix size: ";
    cin>>n;

    vector<vector<int>> matrix(n);
    int a;

    cout<<"Enter elements: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            cin>>a;
            matrix[i].push_back(a);
        }
    }

    int k;

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Kth smallest element in the given matrix: "<<kthSmallest(matrix, k)<<endl;
}