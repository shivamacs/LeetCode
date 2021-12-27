/* Source - https://leetcode.com/problems/binary-tree-paths/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int v) {
        val = v;
        left = right = NULL;
    }
};

void binaryTreePathsHelper(TreeNode* root, string pathSoFar, vector<string>& paths) {
    if(root->left == NULL && root->right == NULL) {
        paths.push_back(pathSoFar + to_string(root->val));
        return;
    }
    
    if(root->left != NULL)
        binaryTreePathsHelper(root->left, pathSoFar + to_string(root->val) + "->", paths);
    
    if(root->right != NULL)
        binaryTreePathsHelper(root->right, pathSoFar + to_string(root->val) + "->", paths);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    
    if(root != NULL)
        binaryTreePathsHelper(root, "", paths);
    
    return paths;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> paths = binaryTreePaths(root);
    cout<<"Root to leaf paths: "<<endl;
    for(int i = 0; i < paths.size(); i++)
        cout<<paths[i]<<endl;
}