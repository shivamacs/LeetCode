/* Source - https://leetcode.com/problems/container-with-most-water/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

 int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int area = 0;
    
    while (i != j) {
        area = max(area, ((j - i) * min(height[i], height[j])));
        
        if (height[i] <= height[j]) i++;
        else j--;
    }
    
    return area;
}

int main()
{
    int n;

    cout<<"Enter number of heights: ";
    cin>>n;

    vector<int> height(n);

    cout<<"Enter heights: ";
    for (int i = 0; i < n; i++)
        cin>>height[i];

    cout<<"Area of container with most water: "<<maxArea(height)<<endl;
}