/* Source - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(int x) {
        data = x;
        left = right = NULL;
    }
};

TreeNode* helper(TreeNode* root) {
    if(root == NULL)
        return NULL;
    
    TreeNode* lTail = helper(root->left);
    TreeNode* rTail = helper(root->right);
    TreeNode* lHead = root->left;
    TreeNode* rHead = root->right;
    
    if(lHead == NULL && rHead == NULL)
        return root;
    else if(lHead != NULL && rHead == NULL) {
        root->right = lHead;
        root->left = NULL;
        
        return lTail;
    } else if(lHead != NULL && rHead != NULL) {
        root->right = lHead;
        root->left = NULL;
        lTail->right = rHead;
        
        return rTail;
    } else
        return rTail;
}

void flatten(TreeNode* root) {
    root = helper(root);
}

void displayFlattenedTree(TreeNode *root) {
    if (root == NULL) return;

    TreeNode* temp = root;

    while (temp->right != NULL) {
        cout<<temp->data<<" <- ";
        temp = temp->right;
    }
    cout<<temp->data<<endl;
}

int main()
{
    TreeNode* root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(5); 
    root->left->left = new TreeNode(3); 
    root->left->right = new TreeNode(4); 
    root->right->right = new TreeNode(6);

    flatten(root);

    cout<<"Linked list constructed: ";
    displayFlattenedTree(root);
}