/* Source - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& weights, int D) {
    int n = weights.size(), maxWeight = 0, sum = 0;
    
    for(int i = 0; i < n; i++) {
        maxWeight = max(maxWeight, weights[i]);
        sum += weights[i];
    }
    
    int l = maxWeight, r = sum, capacity = INT_MAX;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int i = 0, days = 0;
        
        while(i < n) {
            sum = 0;
            
            for(i; i < n; i++) {
                sum += weights[i];
                
                if (sum > mid)
                    break;
            }
            
            days++;
        }
        
        if (days > D)
            l = mid + 1;
        else {
            r = mid - 1;
            capacity = min(capacity, mid);
        }
    }
    
    return capacity;
}

int main()
{   
    int n;

    cout<<"Enter number of packages: ";
    cin>>n;

    vector<int> weights(n);

    cout<<"Enter weights: ";
    for(int i = 0; i < n; i++)
        cin>>weights[i];

    int D;
    cout<<"Enter number of days: ";
    cin>>D;
    
    cout<<"Least weight capacity of the ship that will result in all the packages being shipped within "<<D<<" days: "<<shipWithinDays(weights, D)<<endl;
}