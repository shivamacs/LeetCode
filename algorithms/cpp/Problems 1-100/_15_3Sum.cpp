/* Source - https://leetcode.com/problems/3sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i + 2 < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        
        int l = i + 1, r = n - 1;
        
        while(l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            
            if(sum == 0) {
                result.push_back({nums[i], nums[l], nums[r]});
                
                while(l < r && nums[l] == nums[l + 1])
                    l++;
                while(l < r & nums[r] == nums[r - 1])
                    r--;
                
                l++;
                r--;
            } else if(sum < 0)
                l++;
            else
                r--;
        }
    }
    
    return result;
}

int main()
{
    int n;
    
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>nums[i];

    vector<vector<int>> result = threeSum(nums);

    cout<<"Unique Triplets that sum to 0: "<<endl;
    for(int i = 0; i < result.size(); i++)
        cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl; 
}