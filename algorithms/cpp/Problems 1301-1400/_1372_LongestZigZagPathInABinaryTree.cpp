/* Source - https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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

int maxLen = 0;
    
pair<int, int> helper(TreeNode* root) {
    if(root == NULL)
        return make_pair(-1, -1);
    
    pair<int, int> lPath = helper(root->left);
    pair<int, int> rPath = helper(root->right);
    
    maxLen = max(maxLen, max(lPath.second + 1, rPath.first + 1));
    
    return make_pair(lPath.second + 1, rPath.first + 1);
}

int longestZigZag(TreeNode* root) {
    helper(root);
    return maxLen;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->left->right = new TreeNode(1);
    root->right->right->left->right->right = new TreeNode(1);

    cout<<"Length of longest ZigZag path in the given tree (in terms of edges): "<<longestZigZag(root)<<endl;
}