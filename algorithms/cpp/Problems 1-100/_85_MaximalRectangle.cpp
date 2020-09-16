/* Source - https://leetcode.com/problems/maximal-rectangle/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int largestHistogram(int* heights, int n) {
    int i = 1, maxArea = 0;
    stack<int> st;
    
    st.push(0);
    
    while(i <= n) {
        while(!st.empty() && (i == n ? 0 : heights[i]) < heights[st.top()]) {
            int top = st.top();
            st.pop();
            maxArea = max(maxArea, heights[top] * (st.empty() ? i : i - st.top() - 1));
        }
        
        st.push(i);
        i++;
    }
    
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    
    int n = matrix.size(), m = matrix[0].size(), maxArea = 0, heights[m];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == '1')
                matrix[i][j] += (i == 0) ? 0 : matrix[i - 1][j] - '0';
            
            heights[j] = matrix[i][j] - '0';
        }
        
        maxArea = max(maxArea, largestHistogram(heights, m));
    }
    
    return maxArea;
}

int main()
{
    int n, m;
    cout<<"Enter number of rows and columns: ";
    cin>>n>>m;
    
    vector<vector<char>> matrix(n, vector<char> (m)); 
    
    cout<<"Enter binary values for the matrix row-wise: "<<endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            cin>>matrix[i][j];

    cout<<"Area of largest Rectangle containing only 1's: "<<maximalRectangle(matrix)<<endl;
}