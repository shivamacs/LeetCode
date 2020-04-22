/* Source - https://leetcode.com/problems/minimum-number-of-refueling-stops/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if (stations.empty()) { 
            if (startFuel >= target) return 0;
            else return -1;
        }
        
    if (startFuel < stations[0][0]) return -1;
    
    int n = stations.size();
    
    priority_queue<int> maxFuel;
    int currFuel, diff, fuelStops = 0;
    
    int i = 0;
    
    currFuel = startFuel - stations[i][0];
    
    for (i; i < n; i++) {
        diff = (i < (n - 1) ? stations[i + 1][0] : target) - stations[i][0];
        
        maxFuel.push(stations[i][1]);
                    
        while (!maxFuel.empty() && currFuel < diff) {
            currFuel += maxFuel.top();
            maxFuel.pop();

            fuelStops++;
        }
        
        currFuel -= diff;
        
        if (currFuel < 0) return -1;
    }
    
    return fuelStops;
}

int main()
{
    int n;
    cout<<"Enter number of stations: ";
    cin>>n;

    vector<vector<int>> stations(n);
    int miles, gas;

    cout<<"Enter the miles and litres of gas for each station: "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>miles>>gas;
        stations[i].push_back(miles);
        stations[i].push_back(gas);
    }

    int target, startFuel;
    cout<<"Enter target: ";
    cin>>target;
    cout<<"Enter start fuel: ";
    cin>>startFuel;

    int result = minRefuelStops(target, startFuel, stations);
    if (result >= 0) cout<<"Minimum refuelling stops: "<<result;
    else cout<<"The target can not be reached.";
    cout<<endl;
}