/* Source - https://leetcode.com/problems/convert-bst-to-greater-tree/
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

TreeNode* bstToGst (TreeNode* root) {
    if (root == NULL) return root;
    
    TreeNode* curr = root, *currP1 = NULL;
    int sum = 0;

    while (curr != NULL) {
        if (!curr->right) {
            sum += curr->data;
            curr->data = sum;
            curr = curr->left;
        }
        else {
            currP1 = curr->right;

            while (currP1->left && currP1->left != curr) currP1 = currP1->left;

            if (currP1->left == NULL) {
                currP1->left = curr;
                curr = curr->right;
            }

            else {
                currP1->left = NULL;
                sum += curr->data;
                curr->data = sum;
                curr = curr->left;
            }
        }
    }

    return root;
}

void inorder (TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(11); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(29); 
    root->left->left = new TreeNode(1); 
    root->left->right = new TreeNode(7); 
    root->right->left = new TreeNode(15); 
    root->right->right = new TreeNode(40); 
    root->right->right->left = new TreeNode(35);

    root = bstToGst(root);
    inorder(root);
    cout<<endl;
}