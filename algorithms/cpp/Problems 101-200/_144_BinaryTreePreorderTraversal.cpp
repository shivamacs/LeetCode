/* Source - https://leetcode.com/problems/binary-tree-preorder-traversal/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode (int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void preorder (TreeNode *root) {
    if (root == NULL) return;

    TreeNode *curr = root, *currP1 = NULL;

    while (curr != NULL) {
        if (curr->left == NULL) {
            cout<<curr->data<<" ";
            curr = curr->right;
        }

        else {
            currP1 = curr->left;

            while (currP1->right != NULL && currP1->right != curr)
                currP1 = currP1->right;

            if (currP1->right == NULL) {
                currP1->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }

            else {
                currP1->right = NULL;
                curr = curr->right;    
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5); 
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(10);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
}