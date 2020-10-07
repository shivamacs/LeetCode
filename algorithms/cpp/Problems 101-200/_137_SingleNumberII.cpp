// Pep -> All Repeating Three Times Except One
#include <bits/stdc++.h>
using namespace std;

// approach 1 [O(32n)]
int singleNumberApproach1(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    
    for(int i = 0; i < 32; i++) {
        int mask = 1 << i, sum = 0;
        
        for(int j = 0; j < n; j++) {
            if((nums[j] & mask) == mask)
                sum++;
        }
                    
        if(sum % 3 != 0)
            ans |= mask;
    }
    
    return ans;
}

// approach 2 [O(n)]
int singleNumberApproach2(vector<int>& nums) {
    int n = nums.size();
    int ones = 0, twos = 0, threes = -1;
    
    for(int i = 0; i < n; i++) {
        int mask1 = ones & nums[i];
        int mask2 = twos & nums[i];
        int mask3 = threes & nums[i];
        
        ones = (ones & ~(mask1)) | mask3;
        twos = (twos & ~(mask2)) | mask1;
        threes = (threes & ~(mask3)) | mask2;
    }
    
    return ones;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements (all repeating exactly three times except one): ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Non-repeating number (using sum of bits approach): "<<singleNumberApproach1(nums)<<endl; 
    cout<<"Non-repeating number (using set theory approach): "<<singleNumberApproach2(nums)<<endl; 
}