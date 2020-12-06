/* Source - https://leetcode.com/problems/insert-interval/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size(), i = 0;
    vector<vector<int>> result;
    
    while(i < n && intervals[i][1] < newInterval[0])
        result.push_back(intervals[i++]);
    
    while(i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    
    result.push_back(newInterval);
    
    while(i < n)
        result.push_back(intervals[i++]);
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter number of intervals: ";
    cin>>n;

    vector<vector<int>> intervals(n, vector<int> (2));

    cout<<"Enter intervals: "<<endl;
    for(int i = 0; i < n; i++) 
        cin>>intervals[i][0]>>intervals[i][1];

    vector<int> newInterval(2);

    cout<<"Enter new interval to be inserted: ";
    cin>>newInterval[0]>>newInterval[1];

    vector<vector<int>> result = insert(intervals, newInterval);

    cout<<"Non-overlapping intervals after insertion: "<<endl;
    for(int i = 0; i < result.size(); i++)
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
}
