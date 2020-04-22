/* Source - https://leetcode.com/problems/maximize-distance-to-closest-person/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    
    int i = 0;
    
    while (seats[i] == 0)
        i++;
    
    int j = i + 1, maxDistance = i;
    
    while (j < n) {
        if (seats[j] == 1) {
            maxDistance = max(maxDistance, ((i + j) / 2) - i);
            i = j;
            j = i + 1;
        } else j++;
    }
    
    if (seats[n - 1] == 0)
        maxDistance = max(maxDistance, n - 1 - i);
    
    return maxDistance;
}

int main()
{
    int n;

    cout<<"Enter number of seats: ";
    cin>>n;

    vector<int> seats(n);
    
    cout<<"Enter seating arrangement (0 for unoccupied and 1 for occupied seat): ";
    for (int i = 0; i < n; i++)
        cin>>seats[i];

    cout<<"Seat for another person which is at maximum distance to closest person: "<<maxDistToClosest(seats)<<endl;
}