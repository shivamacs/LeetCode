/* Source - https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

class Element {
    public:
        int val, x, y;
    
        Element(int v = 0, int i = -1, int j = -1) {
            val = v;
            x = i;
            y = j;
        }
    
        bool operator<(const Element& e1) const {
            return val > e1.val;
        }
            
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    int n = nums.size();
    priority_queue<Element> minHeap;
    Element top;
    int maxSoFar = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        minHeap.push(Element(nums[i][0], i, 0));
        maxSoFar = max(maxSoFar, nums[i][0]);
    }
    
    int minRange = INT_MAX;
    vector<int> result(2);
    
    while(!minHeap.empty()) {
        top = minHeap.top();
        minHeap.pop();
                    
        if(maxSoFar - top.val < minRange) {
            minRange = maxSoFar - top.val;
            result[0] = min(top.val, maxSoFar);
            result[1] = max(top.val, maxSoFar);
        }
        
        if(top.y < nums[top.x].size() - 1 && minHeap.size() == n - 1) {
            maxSoFar = max(maxSoFar, nums[top.x][top.y + 1]);
            minHeap.push(Element(nums[top.x][top.y + 1], top.x, top.y + 1));
        }
        else 
            break;
    }
    
    return result;
}

int main()
{
    int k;
    
    cout<<"Enter number of lists: ";
    cin>>k;

    vector<vector<int>> nums(k);
    int n, a;

    for(int i = 0; i < k; i++) {
        cout<<"Enter size of list "<<i + 1<<": ";
        cin>>n;
        cout<<"Enter elements for list "<<i + 1<<": ";
        for(int j = 0; j < n; j++) {
            cin>>a;
            nums[i].push_back(a);
        }
    }

    vector<int> result = smallestRange(nums);

    cout<<"Smallest range covering atleast one number from each of the given lists: ["<<result[0]<<", "<<result[1]<<"]"<<endl;
}