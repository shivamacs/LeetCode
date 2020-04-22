/* Source - https://leetcode.com/problems/delete-node-in-a-bst/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode (int x) {
        data = x;
        left = right = NULL;
    }
};

void insert (TreeNode** root_ref, int x) {
    if (*root_ref == NULL) *root_ref = new TreeNode(x);

    else {
        if (x <= (*root_ref)->data) insert(&((*root_ref)->left), x);
        else insert(&((*root_ref)->right), x);
    }
}

TreeNode* deleteNode(TreeNode *root, int val) {
    if (root == NULL) return NULL;
    
    if (val == root->data) {
        if (root->left == NULL && root->right == NULL) {
            delete(root);
            return NULL;
        }

        if (root->left == NULL || root->right == NULL) {
            TreeNode *temp = root->left ? root->left : root->right;
            delete(root);
            return temp;
        }
        
        TreeNode *succ = root->right, *succParent = root;
        while (succ->left != NULL) {
            if (succ->data > val) {
                succParent = succ;
                succ = succ->left;
            }
            else succ = succ->right;
        }

        if (succParent->left == succ) succParent->left = succ->right;
        else succParent->right = succ->right;
        root->data = succ->data;

        delete(succ);
        return root;
    }

    if (val < root->data) root->left = deleteNode(root->left, val);
    else root->right = deleteNode(root->right, val);

    return root;
}


void printInorder(TreeNode *root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main()
{
    TreeNode *root = NULL;
    insert(&root, 50); 
    insert(&root, 30); 
    insert(&root, 20); 
    insert(&root, 40); 
    insert(&root, 70); 
    insert(&root, 60); 
    insert(&root, 80);

    int val;
    cout<<"Enter value of node to be deleted: ";
    cin>>val;

    root = deleteNode(root, val);
    printInorder(root);
    cout<<endl;
}