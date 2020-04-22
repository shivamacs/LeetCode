/* Source - https://leetcode.com/problems/the-skyline-problem/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Height {
    int c;
    int h;
    
    Height(int a, int b) {
        c = a;
        h = b;
    }
};

static bool comparator (Height& h1, Height& h2) {
    if (h1.c == h2.c)
        return h1.h < h2.h;
    
    return h1.c < h2.c;
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    multiset<int> maxHeights;
    int curr, max = 0;
    vector<Height> heights;
    vector<vector<int>> result;
                            
    for (int i = 0; i < buildings.size(); i++) {
        heights.push_back(Height(buildings[i][0], -1 * buildings[i][2]));    
        heights.push_back(Height(buildings[i][1], buildings[i][2]));
    }
    
    sort(heights.begin(), heights.end(), comparator);
    maxHeights.emplace(0);
    
    for (int i = 0; i < heights.size(); i++) {
        if (heights[i].h < 0)
            maxHeights.emplace(abs(heights[i].h));
        
        else maxHeights.erase(maxHeights.find(heights[i].h));
        
        curr = *maxHeights.rbegin();
                    
        if (curr != max) {
            max = curr;
            result.push_back({heights[i].c, max});
        }
    }
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter number of buildings: ";
    cin>>n;

    vector<vector<int>> buildings(n);
    int x, y, h;

    cout<<"Enter dimensions of the buildings: "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>x>>y>>h;
        buildings[i].push_back(x);
        buildings[i].push_back(y);
        buildings[i].push_back(h);
    }

    vector<vector<int>> result = getSkyline(buildings);

    cout<<"The skyline contour is shown by the coordinates: ";
    for (int i = 0; i < result.size() - 1; i++)
        cout<<"["<<result[i][0]<<", "<<result[i][1]<<"], ";
    cout<<"["<<result[result.size() - 1][0]<<", "<<result[result.size() - 1][1]<<"]"<<endl;
}