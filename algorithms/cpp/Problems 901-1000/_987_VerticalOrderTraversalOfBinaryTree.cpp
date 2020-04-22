/* Source - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left, *right;

    TreeNode (int x) {
        data = x;
        left = right = NULL;
    }
};

vector<vector<int>> verticalTraversal (TreeNode* root) {
    if (root == NULL) return {};
        
    vector<vector<int>> result;
    map<int, vector<int>> np_combined;
    map<int, vector<int>> np_eachlvl;
    map<int, vector<int>>::iterator iter1;
    queue<pair<TreeNode*, int>> lq;
    pair<TreeNode*, int> front;
    int size, k;

    lq.push(make_pair(root, 0));

    while (!lq.empty()) {
        size = lq.size();
        np_eachlvl.clear();

        while (size-- > 0) {
            front = lq.front();
            lq.pop();

            k = front.second;

            np_eachlvl[k].push_back(front.first->data);

            if (front.first->left) lq.push(make_pair(front.first->left, k - 1));
            if (front.first->right) lq.push(make_pair(front.first->right, k + 1));
        }
        
        for (iter1 = np_eachlvl.begin();iter1 != np_eachlvl.end();iter1++) {
            vector<int> temp = iter1->second;
            sort(temp.begin(), temp.end());
            np_combined[iter1->first].insert(np_combined[iter1->first].end(), temp.begin(), temp.end());
        }
    }

    for (iter1 = np_combined.begin();iter1 != np_combined.end();++iter1) result.push_back(iter1->second);
    
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5); 
    root->right->left = new TreeNode(6); 
    root->right->right = new TreeNode(7); 
    root->right->left->right = new TreeNode(8); 
    root->right->right->right = new TreeNode(9);

    int size;
    cout<<"Vertical order traversal: "<<endl;
    vector<vector<int>> result = verticalTraversal(root);
    for(int i=0;i<result.size();i++) {
        for (int j=0;j<result[i].size();j++) cout<<result[i][j]<<" ";
        cout<<endl;
    }
}