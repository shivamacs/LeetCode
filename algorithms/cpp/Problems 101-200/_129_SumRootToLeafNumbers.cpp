/* Source - https://leetcode.com/problems/sum-root-to-leaf-numbers/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;

    TreeNode(int v) {
        val = v;
        left = right = NULL;
    }
};

int helper(TreeNode* root, int asf) {
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return asf * 10 + root->val;
    
    return helper(root->left, asf * 10 + root->val) + helper(root->right, asf * 10 + root->val);        
}

int sumNumbers(TreeNode* root) {
    return helper(root, 0);
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    cout<<"Sum of all root-to-leaf numbers: "<<sumNumbers(root)<<endl;
}