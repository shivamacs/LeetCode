/* Source - https://leetcode.com/problems/binary-tree-postorder-traversal/
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

void postorder (TreeNode *root) {
    if (root == NULL) return;

    TreeNode *curr = root, *currP1 = NULL;
    vector<int> pst;

    while (curr != NULL) {
        if (curr->right == NULL) {
            pst.push_back(curr->data);
            curr = curr->left;
        }

        else {
            currP1 = curr->right;

            while (currP1->left != NULL && currP1->left != curr)
                currP1 = currP1->left;

            if (currP1->left == NULL) {
                currP1->left = curr;
                pst.push_back(curr->data);
                curr = curr->right;
            }

            else {
                currP1->left = NULL;
                curr = curr->left;    
            }
        }
    }

    reverse(pst.begin(), pst.end());
    for(int i=0;i<pst.size();i++) cout<<pst[i]<<" ";
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

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
}