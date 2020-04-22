/* Source - https://leetcode.com/problems/k-closest-points-to-origin/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;
    
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    typedef pair<float, vector<int>> dp;

    priority_queue<dp, vector<dp>, greater<dp>> minDistance;

    for (int i = 0; i < points.size(); i++) {
        float distance = sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
        minDistance.push(make_pair(distance, points[i]));
    }

    vector<vector<int>> kClosestPoints;

    while (!minDistance.empty() && K > 0) {
        kClosestPoints.push_back(minDistance.top().second);
        minDistance.pop();
        K--;
    }

    return kClosestPoints;
}

int main()
{
    int n;
    cout<<"Enter number of points: ";
    cin>>n;

    vector<vector<int>> points(n);
    int x, y;

    cout<<"Enter the points: "<<endl;
    for (int i = 0;i < n; i++) {
        cin>>x>>y;
        points[i].push_back(x);
        points[i].push_back(y);
    }

    int K;
    cout<<"Enter the value of K: ";
    cin>>K;

    vector<vector<int>> kClosestPoints = kClosest(points, K);

    cout<<"K closest point(s) to origin: "<<endl;
    for (int i = 0; i < kClosestPoints.size(); i++) cout<<kClosestPoints[i][0]<<" "<<kClosestPoints[i][1]<<endl;
}