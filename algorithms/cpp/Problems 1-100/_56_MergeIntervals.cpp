/* Source - https://leetcode.com/problems/merge-intervals/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int s, e;

    Interval(int a, int b) {
        s = a;
        e = b;
    }
};

static bool comparator(Interval i1, Interval i2) {
    return i1.s < i2.s;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0)
        return {};
    
    vector<Interval> pairs;
    
    for(int i = 0; i < intervals.size(); i++)
        pairs.push_back(Interval(intervals[i][0], intervals[i][1]));
    
    sort(pairs.begin(), pairs.end(), comparator);

    stack<Interval> stack;
    vector<vector<int>> result;

    stack.push(Interval(pairs[0].s, pairs[0].e));

    for(int i = 1; i < pairs.size(); i++) {
        Interval curr = pairs[i];

        if(curr.s > stack.top().e) 
            stack.push(curr);
        else
            stack.top().e = max(stack.top().e, curr.e);
    }

    while(!stack.empty()) {
        result.push_back({stack.top().s, stack.top().e});
        stack.pop();
    }

    reverse(result.begin(), result.end());

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