/* Source - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode (int x) {
        data = x;
        left = right = NULL;
    }
};

map<int, int> inorderIndex;

TreeNode* constructTree (vector<int>& inorder, int is, int ie, vector<int>& postorder, int pos, int poe) {
    if (is > ie || pos > poe) return NULL;

    TreeNode *root = new TreeNode(postorder[poe]);
    int index = inorderIndex[postorder[poe]];
    int diff = index - is;

    root->left = constructTree(inorder, is, index - 1, postorder, pos, pos + diff - 1);
    root->right = constructTree(inorder, index + 1, ie, postorder, pos + diff, poe - 1);

    return root;
}

TreeNode* buildTree (vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    int is = 0, ie = n - 1, pos = 0, poe = n - 1;

    for (int i=0;i<n;i++) inorderIndex[inorder[i]] = i;

    TreeNode* root = constructTree(inorder, is, ie, postorder, pos, poe);

    return root;
}

void printPreorder (TreeNode* root) {
    if (root == NULL) return;
    
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    vector<int> inorder, postorder;
    int n, a;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter Inorder: ";
    for (int i = 0;i < n;i++) {
        cin>>a;
        inorder.push_back(a);
    }

    cout<<"Enter Postorder: ";
    for (int i = 0;i < n;i++) {
        cin>>a;
        postorder.push_back(a);
    }

    TreeNode *root = buildTree(inorder, postorder);
    cout<<"Preorder of the contructed tree: ";
    printPreorder(root);
    cout<<endl;
}