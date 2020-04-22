/* Source - https://leetcode.com/problems/gas-station/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit (vector<int>& gas, vector<int>& cost) {
    int sum = 0, diff = 0, index = 0, n = gas.size();
    
    for (int i=0;i<n;i++) {
        sum += gas[i] - cost[i];
        if (sum < 0) {
            index = i + 1;
            diff += sum;
            sum = 0;
        }      
    }
    
    return sum + diff >= 0 ? index : -1; 
}

int main()
{
    int n;
    cout<<"Enter the number of gas stations: ";
    cin>>n;

    vector<int> gas(n), cost(n);

    cout<<"Enter amount of gas at each station: ";
    for (int i=0;i<n;i++) cin>>gas[i];

    cout<<"Enter costs: ";
    for (int i=0;i<n;i++) cin>>cost[i];

    int result = canCompleteCircuit(gas, cost);
    if (result != -1) cout<<"The starting gas station from which the circuit is completed once in the clockwise direction: "<<result;
    else cout<<"Circuit can't be completed from any gas station.";
    cout<<endl;
}