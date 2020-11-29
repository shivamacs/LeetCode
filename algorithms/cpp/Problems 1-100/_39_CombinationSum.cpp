/* Source - https://leetcode.com/problems/combination-sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void helper(int idx, vector<int>& candidates, int sum, int target, vector<int>& temp, vector<vector<int>>& result) {
    if(sum == target) {
        result.push_back(temp);
        return;
    }
    
    if(idx == candidates.size())
        return;
    
    if(sum + candidates[idx] <= target) {
        temp.push_back(candidates[idx]);
        helper(idx, candidates, sum + candidates[idx], target, temp, result);
        temp.pop_back();
    }
    
    helper(idx + 1, candidates, sum, target, temp, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<int> temp;
    vector<vector<int>> result;
    
    helper(0, candidates, 0, target, temp, result);
    
    return result;
}

int main()
{
    int n;

    cout<<"Enter number of candidates: ";
    cin>>n;

    vector<int> candidates(n);

    cout<<"Enter candidates: ";
    for(int i = 0; i < n; i++)
        cin>>candidates[i];

    int target;

    cout<<"Enter target: ";
    cin>>target;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout<<"Combinations of candidates that form the target (unlimited choices - backtracking approach): "<<endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}