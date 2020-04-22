/* Source - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

TreeNode* constructTree (vector<int>& inorder, int is, int ie, vector<int>& preorder, int ps, int pe) {
    
    if (is > ie || ps > pe) return NULL;

    TreeNode* root = new TreeNode(preorder[ps]);
    int index = inorderIndex[preorder[ps]];
    int diff = index - is;

    root->left = constructTree(inorder, is, index - 1, preorder, ps + 1, ps + diff);
    root->right = constructTree(inorder, index + 1, ie, preorder, ps + 1 + diff, pe);

    return root;
}

TreeNode* buildTree (vector<int>& inorder, vector<int>& preorder) {
    int n = inorder.size();
    int is = 0, ie = n - 1, ps = 0, pe = n - 1;

    for (int i=0;i<n;i++) inorderIndex[inorder[i]] = i;
    TreeNode* root = constructTree(inorder, is, ie, preorder, ps, pe);

    return root;
}

void printPostorder (TreeNode* root) {
    if (root == NULL) return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    vector<int> inorder, preorder;
    int n, a;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter Preorder: ";
    for (int i = 0;i < n;i++) {
        cin>>a;
        preorder.push_back(a);
    }

    cout<<"Enter Inorder: ";
    for (int i = 0;i < n;i++) {
        cin>>a;
        inorder.push_back(a);
    }

    TreeNode *root = buildTree(inorder, preorder);
    cout<<"Postorder of the contructed tree: ";
    printPostorder(root);
    cout<<endl;
}