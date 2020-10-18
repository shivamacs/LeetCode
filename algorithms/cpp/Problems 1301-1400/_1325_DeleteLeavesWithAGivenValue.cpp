/* Source - https://leetcode.com/problems/delete-leaves-with-a-given-value/
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

TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(root == NULL)
        return NULL;
        
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    
    if(root->val == target && root->left == NULL && root->right == NULL)
        return NULL;
    
    return root;
}

void preOrder(TreeNode* root) {
    if(root == NULL)
        return;

    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    int target = 2;

    root = removeLeafNodes(root, target);

    cout<<"Pre-order of modified tree: ";
    preOrder(root);
    cout<<endl;
}