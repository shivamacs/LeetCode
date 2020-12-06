/* Source - https://leetcode.com/problems/merge-intervals/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

static bool comparator(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> result;
    
    sort(intervals.begin(), intervals.end(), comparator);
    
    int start = intervals[0][0], end = intervals[0][1];
    
    for(int i = 1; i < n; i++) {
        int s = intervals[i][0], e = intervals[i][1];
        
        if(s <= end)
            end = max(end, e);
        else {
            result.push_back({start, end});
            start = s;
            end = e;
        }
    }
    
    result.push_back({start, end});
    
    return result;
}

int main()
{
    int n;
    
    cout<<"Enter number of intervals: ";
    cin>>n;
    
    vector<vector<int>> intervals(n, vector<int>(2));

    cout<<"Enter intervals: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++)
            cin>>intervals[i][j];
    }

    vector<vector<int>> result = merge(intervals);

    cout<<"Merged Intervals: "<<endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}