/* Source - https://leetcode.com/problems/fruit-into-baskets/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& tree) {
    unordered_map<int, int> freqMap;
    int start = 0, count = 0, maxCount = 0;
    
    for(int i = 0; i < tree.size(); i++) {
        freqMap[tree[i]]++;
        
        while(freqMap.size() > 2) {
            freqMap[tree[start]]--;
            
            if(freqMap[tree[start]] == 0)
                freqMap.erase(tree[start]);
            
            start++;
        }
        
        maxCount = max(maxCount, i - start + 1);
    }
    
    return maxCount;
}

int main()
{
    int n;

    cout<<"Enter number of trees: ";
    cin>>n;

    vector<int> tree(n);

    cout<<"Enter the trees (i-th tree produces fruit of type tree[i]): ";
    for(int i = 0; i < n; i++)
        cin>>tree[i];

    cout<<"Maximum amount of fruit that can be collected (of 2 types): "<<totalFruit(tree)<<endl;
}