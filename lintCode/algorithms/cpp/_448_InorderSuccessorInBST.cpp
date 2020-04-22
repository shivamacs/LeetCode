/* Source - https://www.lintcode.com/problem/inorder-successor-in-bst/description/
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

TreeNode* inorderSuccessor (TreeNode* root, TreeNode* n) {
    TreeNode *curr = root, *succ = NULL;    

    while (curr != NULL) {
        if (curr->data > n->data) {
            succ = curr;
            curr = curr->left;
        }
        else curr = curr->right;
    }

    return succ;
}

int main()
{
    TreeNode *root = NULL;
    insert(&root, 20); 
    insert(&root, 8); 
    insert(&root, 22); 
    insert(&root, 4); 
    insert(&root, 12); 
    insert(&root, 10);   
    insert(&root, 14);

    root = inorderSuccessor(root, root->left->right);
    cout<<root->data<<endl;
}