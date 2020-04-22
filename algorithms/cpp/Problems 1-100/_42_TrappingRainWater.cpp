/* Source - https://leetcode.com/problems/trapping-rain-water/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int trappedRainWater(vector<int>& heights) {
    int left_max = 0, right_max = 0, water = 0;

    int i = 0, j = heights.size() - 1;
    while (i <= j) {
        if (heights[i] < heights[j]) {
            if (heights[i] > left_max)
                left_max = heights[i];
            else 
                water += left_max - heights[i];
            
            i++;
        }

        else {
            if (heights[j] > right_max)
                right_max = heights[j];
            else
                water += right_max - heights[j];

            j--;
        }
    }

    return water;
}

int main()
{
    int n;

    cout<<"Enter number of heights: ";
    cin>>n;

    vector<int> heights(n);

    cout<<"Enter heights: ";
    for (int i = 0; i < n; i++)
        cin>>heights[i];

    cout<<"Units of water that can be trapped in the array: "<<trappedRainWater(heights)<<endl;
}