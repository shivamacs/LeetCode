/* Source - https://www.lintcode.com/problem/meeting-rooms-ii/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

class Interval {
    public:
        int start, end;

        Interval(int s = -1, int e = -1) {
            start = s;
            end = e;
        }
};

static bool comparator(Interval& A, Interval& B) {
        return A.start < B.start;
}
    
int minMeetingRooms(vector<Interval> &intervals) {
    int n = intervals.size(), minRooms = 0;
    sort(intervals.begin(), intervals.end(), comparator);
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < n; i++) {
        while(!minHeap.empty() && intervals[i].start >= minHeap.top())
            minHeap.pop();
            
        minHeap.push(intervals[i].end);
        
        minRooms = max(minRooms, int(minHeap.size()));
    }
    
    return minRooms;
}

int main()
{
    int n;

    cout<<"Enter the number of meetings: ";
    cin>>n;

    vector<Interval> intervals(n);

    cout<<"Enter meeting intervals: "<<endl;
    for(int i = 0; i < n; i++)
        cin>>intervals[i].start>>intervals[i].end;

    cout<<"Minimum rooms required to conduct all the meetings: "<<minMeetingRooms(intervals)<<endl;
}