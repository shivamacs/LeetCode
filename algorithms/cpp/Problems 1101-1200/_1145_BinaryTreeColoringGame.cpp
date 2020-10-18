/* Source - https://leetcode.com/problems/binary-tree-coloring-game/
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

int xLeft = 0, xRight = 0;
    
int countNodes(TreeNode* root, int x) {
    if(root == NULL)
        return 0;
    
    int leftCount = countNodes(root->left, x);
    int rightCount = countNodes(root->right, x);
    
    if(root->val == x) {
        xLeft = leftCount;
        xRight = rightCount;
    }
    
    return 1 + leftCount + rightCount;
}

bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    countNodes(root, x);
            
    return xLeft > n / 2 || xRight > n / 2 || (n - xLeft - xRight - 1) > n / 2;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int n = 11, x = 3;

    cout<<"Can you win the game (second player) ? "<<boolalpha<<btreeGameWinningMove(root, n, x)<<endl;
}