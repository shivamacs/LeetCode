/* Source - https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence/description/
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

 void longestConsecutiveIncreasingUtil(TreeNode *root, int inc, int expected, int& ans) {
    if (root == NULL ) return;
    
    if (root->data == expected) inc++; 
    else inc = 1; 
    
    ans = max(ans, inc);

    longestConsecutiveIncreasingUtil(root->left, inc, root->data + 1, ans);
    longestConsecutiveIncreasingUtil(root->right, inc, root->data + 1, ans);
}
    
int longestConsecutiveIncreasing(TreeNode * root) {
    int ans = 0;
    longestConsecutiveIncreasingUtil(root, 0, root->data, ans);
    
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(6); 
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(10);
    root->right->right->right = new TreeNode(11);

    cout<<"Length of longest consecutive increasing sequence: "<<longestConsecutiveIncreasing(root)<<endl;
}