/* Source - https://leetcode.com/problems/koko-eating-bananas/
   Author - Shivam Arora
*/ 
#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int H) {
    int n = piles.size(), maxOfPiles = INT_MIN;
    
    for(int i = 0; i < piles.size(); i++)
        maxOfPiles = max(maxOfPiles, piles[i]);
    
    int i = 1, j = maxOfPiles, speed = INT_MAX;
    
    while(i <= j) {
        int mid = i + (j - i) / 2;
        int hours = 0;
        
        for(int i = 0; i < n; i++)
            hours += ceil(float(piles[i]) / mid);
        
        if(hours > H)
            i = mid + 1;
        else {
            j = mid - 1;
            speed = min(speed, mid);
        }
    }
    
    return speed;
}

int main()
{
    int n;

    cout<<"Enter number of piles: ";
    cin>>n;

    vector<int> piles(n);

    cout<<"Enter bananas in each pile: ";
    for(int i = 0; i < n; i++)
        cin>>piles[i];

    int H;
    
    cout<<"Enter number of hours: ";
    cin>>H;

    cout<<"Minimum speed at which Koko can eat all the bananas within "<<H<<" hours: "<<minEatingSpeed(piles, H)<<endl;
}