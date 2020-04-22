/* Source - https://leetcode.com/problems/moving-stones-until-consecutive-ii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> numMovesStonesII(vector<int>& stones) {
    int n = stones.size();
    vector<int> result;
    
    sort(stones.begin(), stones.end());
    
    int i = 0, j = 0, wsize, scount, minMoves = INT_MAX;
    
    while (j < n) {
        wsize = stones[j] - stones[i] + 1;
        scount = j - i + 1;
        
        if (wsize > n) {
            i++;
            continue;
        }
        
        if (wsize == n - 1 && scount == n - 1)
            minMoves = min(minMoves, 2);
        
        else minMoves = min(minMoves, n - scount);
        
        j++;
    }
    
    result.push_back(minMoves);
    
    int maxMoves;

    if (stones[1] == stones[0] + 1 || stones[n - 1] == stones[n - 2] + 1)
        maxMoves = stones[n - 1] - stones[0] + 1 - n;
    
    else 
        maxMoves = max(((stones[n - 1] - stones[1]) - (n - 1) + 1), ((stones[n - 2] - stones[0]) - (n - 1) + 1));
    
    result.push_back(maxMoves);
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter the number of stones: ";
    cin>>n;

    vector<int> stones(n);

    cout<<"Enter the positions of stones: ";
    for (int i = 0; i < n; i++)
        cin>>stones[i];

    vector<int> result = numMovesStonesII(stones);

    cout<<"Minimum and maximum number of moves to arrange the stones such that they become consecutive: "<<result[0]<<", "<<result[1]<<endl;
}