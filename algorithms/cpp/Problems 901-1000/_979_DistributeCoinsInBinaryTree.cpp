/* Source - https://leetcode.com/problems/distribute-coins-in-binary-tree/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int coins;
    TreeNode *left, *right;

    TreeNode (int x) {
        coins = x;
        left = right = NULL;
    }
};

int distributeCoinsUtil (TreeNode* root, int &moves) {
    if (root == NULL) return 0;

    int left = distributeCoinsUtil(root->left, moves);
    int right = distributeCoinsUtil(root->right, moves);
    
    moves += abs(left) + abs(right);

    return root->coins + left + right - 1;
}

int distributeCoins (TreeNode *root) {
    int moves = 0;

    distributeCoinsUtil(root, moves);

    return moves;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left->right = new TreeNode(3);

    cout<<"Number of moves in the binary tree such that each node has exactly one coin: "<<distributeCoins(root)<<endl;
}