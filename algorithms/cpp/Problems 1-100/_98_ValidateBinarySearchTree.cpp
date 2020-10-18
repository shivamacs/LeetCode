/* Source - https://leetcode.com/problems/validate-binary-search-tree/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;

    TreeNode (int x) {
        val = x;
        left = right = NULL;
    }
};

bool isValidBSTApproach1(TreeNode* root) {
    int* prev = NULL;
    bool result = true;

    while(root != NULL) {
        if(root->left == NULL) {
            if(prev && root->val <= *prev)
                result = false;
                        
            prev = &(root->val);
            root = root->right;
        } else {
            TreeNode* rootP1 = root->left;

            while(rootP1->right != NULL && rootP1->right != root)
                rootP1 = rootP1->right;

            if(rootP1->right == NULL) {
                rootP1->right = root;
                root = root->left;
            } else {
                rootP1->right = NULL;

                if(prev && root->val <= *prev)
                    result = false;
                
                prev = &(root->val);
                root = root->right;
            }
        }
    }
    
    return result;
}

bool checkBST(TreeNode* root, long min, long max) {
    if(root == NULL)
        return true;
    
    if(root->val < min || root->val > max)
        return false;
    
    bool left = checkBST(root->left, min, long(root->val) - 1);
    bool right = checkBST(root->right, long(root->val) + 1, max);
    
    if(left == false || right == false)
        return false;
    
    return true;
}

bool isValidBSTApproach2(TreeNode* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}

int main()
{
    TreeNode *root = new TreeNode(11); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(29); 
    root->left->left = new TreeNode(1); 
    root->left->right = new TreeNode(7); 
    root->right->left = new TreeNode(15); 
    root->right->right = new TreeNode(40); 
    root->right->right->left = new TreeNode(35);

    cout<<"Is the given tree a valid BST? (using approach 1)"<<boolalpha<<isValidBSTApproach1(root)<<endl;
    cout<<"Is the given tree a valid BST? (using approach 2)"<<boolalpha<<isValidBSTApproach2(root)<<endl;
}