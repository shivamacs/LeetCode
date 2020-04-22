/* Source - https://leetcode.com/problems/median-of-two-sorted-arrays/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
        nums1.swap(nums2);
        
    int m = nums1.size();
    int n = nums2.size();
    int len = (m + n + 1) / 2;
    int i = 0, j = m, temp1, temp2;
    
    double median;
    
    while (i <= j) {
        temp1 = (i + j) / 2;
        temp2 = len - temp1;
                                    
        if (temp1 < m && temp2 > 0 && nums1[temp1] < nums2[temp2 - 1])
            i = temp1 + 1;
        
        else if (temp1 > 0 && temp2 < n && nums1[temp1 - 1] > nums2[temp2])
            j = temp1 - 1;
        
        else {
            if (temp1 == 0)
                median = nums2[temp2 - 1];
            
            else if (temp2 == 0)
                median = nums1[temp1 - 1];
            
            else median = max(nums1[temp1 - 1], nums2[temp2 - 1]);
            
            break;
        }
    }
    
    if ((m + n) % 2 == 0) {
        if (temp1 == m)
            return (median + nums2[temp2]) / 2.0;

        if (temp2 == n)
            return (median + nums1[temp1]) / 2.0;

        return (median + min(nums1[temp1], nums2[temp2])) / 2.0;
    }

    return median;
}

int main()
{
    int m, n;

    cout<<"Enter sizes of first and second array: ";
    cin>>m>>n;

    vector<int> nums1(m), nums2(n);

    cout<<"Enter elements of first array (sorted): ";
    for (int i = 0; i < m; i++)
        cin>>nums1[i];

    cout<<"Enter elements of second array (sorted): ";
    for (int i = 0; i < n; i++)
        cin>>nums2[i];

    cout<<"Median of two given sorted arrays: "<<findMedianSortedArrays(nums1, nums2)<<endl;
}