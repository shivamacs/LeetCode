/* Source - https://leetcode.com/problems/4sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> result;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i + 3 < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        
        for(int j = i + 1; j + 2 < n; j++) {
            if(j > i + 1 && nums[j] == nums[j - 1])
                continue;
            
            int l = j + 1, r = n - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                
                if(sum == target) {
                    result.push_back({nums[i], nums[j], nums[l], nums[r]});
                    
                    while(l < r && nums[l] == nums[l + 1])
                        l++;
                    while(l < r && nums[r] == nums[r - 1])
                        r--;
                    
                    l++;
                    r--;
                } else if(sum < target)
                    l++;
                else
                    r--;
            }
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

    int target;

    cout<<"Enter target: ";
    cin>>target;

    vector<vector<int>> result = fourSum(nums, target);

    cout<<"Unique Quadruplets that sum to 0: "<<endl;
    for(int i = 0; i < result.size(); i++)
        cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<" "<<result[i][3]<<endl; 
}