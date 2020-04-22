/* Source - https://leetcode.com/problems/binary-tree-cameras/
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

int camera = 0;

int cameraCover (TreeNode* root) {
    if (root == NULL) return 2;

    int left = cameraCover(root->left);
    int right = cameraCover(root->right);

    if (left == 0 || right == 0) {
        camera++;
        return 1;
    }

    if (left == 1 || right == 1) return 2;

    return 0;
}

int minCameraCover (TreeNode* root) {
    if (cameraCover(root) == 0) return camera + 1;
    return camera;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);

    cout<<"Minimum number of cameras to cover the entire binary tree: "<<minCameraCover(root)<<endl;
}