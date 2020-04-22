/* Source - https://www.lintcode.com/problem/line-reflection/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool lineReflection(vector<pair<int, int>>& points) {
    if (points.empty()) return true;
    
    unordered_map<int, unordered_set<int>> xyMap;
    int minX = INT_MAX, maxX = INT_MIN;

    for (int i = 0; i < points.size(); i++) {
        if (points[i].first < minX) minX = points[i].first;
        if (points[i].first > maxX) maxX = points[i].first;

        xyMap[points[i].first].insert(points[i].second);
    }

    float rline = float(minX + maxX)/2;

    for (int i = 0; i < points.size(); i++) {
        int rpoint = (2*rline) - points[i].first;
        if (xyMap.find(rpoint) != xyMap.end()) {
            if (xyMap[rpoint].find(points[i].second) == xyMap[rpoint].end())
                return false;
        }
        else return false;
    }

    return true;
}

int main()
{
    int n;

    cout<<"Enter the number of points: ";
    cin>>n;

    vector<pair<int, int>> points;
    int x, y;

    cout<<"Enter the points: "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        points.push_back(make_pair(x, y));
    }

    bool result = lineReflection(points);

    if (result == true) cout<<"A line can be drawn such that all the given points have their reflection.";
    else cout<<"A line cannot be drawn such that all the given points have their reflection.";
    cout<<endl;
}