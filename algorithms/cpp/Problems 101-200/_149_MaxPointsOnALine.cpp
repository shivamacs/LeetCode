/* Source - https://leetcode.com/problems/max-points-on-a-line/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    
    return gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
    unordered_map<string, int> slopeMap;
    int n = points.size();
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        int temp = 0;
        int duplicates = 0;
        
        slopeMap.clear();
    
        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            
            if (dx == 0 && dy == 0) {
                duplicates++;
                continue;
            }
                
            int g = gcd(dx, dy);
            temp = max(temp, ++slopeMap[to_string(dy/g) + "/" + to_string(dx/g)]);
        }
        
        result = max(result, temp + duplicates + 1);
    }
    
    return result;
}

int main()
{
    int n;
    
    cout<<"Enter number of points: ";
    cin>>n;

    vector<vector<int>> points(n);
    int x, y;

    cout<<"Enter points: "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        points[i].push_back(x);
        points[i].push_back(y);
    }

    cout<<"Maximum points on a line: "<<maxPoints(points)<<endl;
}