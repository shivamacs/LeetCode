/* Source - https://leetcode.com/problems/recover-binary-search-tree/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        val = v;
        left = right = NULL;
    }
};

void recoverTree(TreeNode* root) {
    TreeNode* curr = root, *prev = NULL, *prn1 = NULL, *prn2 = NULL;
    
    while(curr != NULL) {
        if(curr->left == NULL) {
            if(prev && curr->val <= prev->val) {
                if(prn1 == NULL) {
                    prn1 = prev;
                    prn2 = curr;
                } else
                    prn2 = curr;
            }
            
            prev = curr;
            curr = curr->right;
        } else {
            TreeNode* currP1 = curr->left;
            
            while(currP1->right != NULL && currP1->right != curr)
                currP1 = currP1->right;
            
            if(currP1->right == NULL) {
                currP1->right = curr;
                curr = curr->left;
            } else {
                if(prev && curr->val <= prev->val) {
                    if(prn1 == NULL) {
                        prn1 = prev;
                        prn2 = curr;
                    } else
                        prn2 = curr;
                }
                
                prev = curr;
                currP1->right = NULL;
                curr = curr->right;
            }
        }
    }
        
    int temp = prn1->val;
    prn1->val = prn2->val;
    prn2->val = temp;
}

void printInorder(TreeNode* root) {
    if(root == NULL)
        return;

    printInorder(root->left);
    cout<<root->val<<" ";
    printInorder(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    
    recoverTree(root);

    cout<<"Inorder of recovered tree: ";
    printInorder(root);
    cout<<endl;
}