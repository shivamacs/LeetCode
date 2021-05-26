/* Source - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;

    TreeNode(int v) {
        val = v;
        left = right = NULL;
    }
};

vector< vector<int> > zigzag_level_order(TreeNode* root) {
    if(root == NULL) {
        vector< vector<int> > temp;
        return temp;
    }
    
    queue<TreeNode*> q;
    vector< vector<int> > result;
    bool lTor = true;
    
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> temp(size);
        
        for(int i = 0; i < size; i++) {
            TreeNode* front = q.front();
            q.pop();
            
            if(lTor)
                temp[i] = front->val;
            else
                temp[size - i - 1] = front->val;

            
            if(front->left)
                q.push(front->left);

            if(front->right)
                q.push(front->right);
        }
        
        lTor = !lTor;
        result.push_back(temp);
    }
    
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);

    vector< vector<int> > result = zigzag_level_order(root);
    
    cout<<"ZigZag Order traversal of the given tree: "<<endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}