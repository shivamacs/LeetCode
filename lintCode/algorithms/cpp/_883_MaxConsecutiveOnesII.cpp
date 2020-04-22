/* Source - https://www.lintcode.com/problem/max-consecutive-ones-ii/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size();
    
    int start = 0, i = 0, z = 0, result = 0;
    
    while (i < n) {
        if (nums[i] == 0) {
            z++;

            if (z > 1) {
                z--;
                
                while (nums[start] != 0)
                    start++;
                    
                start++;
            }
        }
        
        result = max(result, i - start + 1);
        
        i++;
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
    for (int i = 0; i < n; i++)
        cin>>nums[i];

    cout<<"Max consecutive ones with atmost 1 zero flip: "<<findMaxConsecutiveOnes(nums)<<endl;
}