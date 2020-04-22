/* Source - https://leetcode.com/problems/binary-tree-maximum-path-sum/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(int x) {
        data = x;
        left = right = NULL;
    }
};

bool comp (int a, int b) {
    return (a < b);
}

int maxAltPath = INT_MIN;
int maxPathSum(TreeNode* root) {
    int left = 0, right = 0;
        
    if (root->left) left = maxPathSum(root->left);
    if (root->right) right = maxPathSum(root->right);
    
    if (left < 0) left = 0;
    if (right < 0) right = 0;
    
    int maxSubPath = root->data + ((left > right) ? left : right);
    int altPath = root->data + left + right;
    
    if (altPath > maxAltPath) maxAltPath = altPath;
    
    return maxSubPath;
}

int main()
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int result = maxPathSum(root);
    if (maxAltPath > result) result = maxAltPath;
    cout<<"Maximum path sum in the given tree is: "<<result<<endl;
}