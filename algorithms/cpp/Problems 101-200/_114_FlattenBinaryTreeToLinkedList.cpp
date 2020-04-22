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

void flatten(TreeNode *root) {
    if (root == NULL) return;

    flatten(root->left);

    if (root->left != NULL) {
        TreeNode *temp1 = root->right;
        TreeNode *temp2 = root->left;
        root->right = temp2;
        root->left = NULL;

        while (temp2->right != NULL) temp2 = temp2->right;
        
        temp2->right = temp1;
    }

    flatten(root->right);
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