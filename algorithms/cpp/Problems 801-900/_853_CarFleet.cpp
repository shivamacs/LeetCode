/* Source - https://leetcode.com/problems/car-fleet/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int carFleet (int target, vector<int>& position, vector<int>& speed) {
    int n = position.size(), fleets = 0;
    float timeOfFleet = -1;
    vector<float> time(n);
    vector<pair <int, int> > v;

    for (int i=0;i<n;i++) v.push_back(make_pair(position[i], speed[i]));
    sort(v.begin(), v.end());
    
    for (int i=n-1;i>=0;i--) {
        time[i] = float(target - v[i].first) / float(v[i].second);
        if (time[i] > timeOfFleet) {
            timeOfFleet = time[i];
            fleets++;
        }
    }

    return fleets;
}

int main()
{
    int n, target;
    cout<<"Enter number of cars: ";
    cin>>n;

    vector<int> position(n), speed(n);

    cout<<"Enter positions: ";
    for (int i=0;i<n;i++) cin>>position[i];

    cout<<"Enter speeds: ";
    for (int i=0;i<n;i++) cin>>speed[i];

    cout<<"Enter target: ";
    cin>>target;
    cout<<"Number of car fleets: "<<carFleet(target, position, speed)<<endl;
}