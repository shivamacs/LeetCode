/* Source - https://leetcode.com/problems/invert-binary-tree/
   Author  - Shivam Arora
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

TreeNode* invert_tree(TreeNode* root) {
    if(root == NULL)
        return NULL;
    
    TreeNode* temp = root->left;
        
    root->left = invert_tree(root->right);
    root->right = invert_tree(temp);
    
    return root;
    }

void print_inorder(TreeNode* root) {
    if(root == NULL)
        return;

    cout<<root->val<<" ";
    print_inorder(root->left);
    print_inorder(root->right);
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

    cout<<"Inorder of original tree: ";
    print_inorder(root);
    cout<<endl;

    root = invert_tree(root);
    
    cout<<"Inorder of inverted tree: ";
    print_inorder(root);
    cout<<endl;
}