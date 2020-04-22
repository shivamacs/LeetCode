/* Source - https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-ii/description/
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

bool comp(int a, int b) {
    return a < b;
}

pair<int, int> longestConsecutiveUtil(TreeNode *root, int& alt) {
    if (root == NULL) return make_pair(0, 0);

    pair<int, int> leftPair = longestConsecutiveUtil(root->left, alt);
    pair<int, int> rightPair = longestConsecutiveUtil(root->right, alt);

    int inc = 1, dec = 1;

    if (root->left) {
        if (root->left->data == root->data + 1) inc = leftPair.first + 1;
        if (root->left->data == root->data - 1) dec = leftPair.second + 1;
    }

    if (root->right) {
        if (root->right->data == root->data + 1) inc = max(inc, rightPair.first + 1);
        if (root->right->data == root->data - 1) dec = max(dec, rightPair.second + 1);
    }

    alt = max(alt, inc + dec - 1);

    return make_pair(inc, dec);
}

int longestConsecutive(TreeNode *root) {
    int alt = 0;
    pair<int, int> res = longestConsecutiveUtil(root, alt);
    int maxRes = max(res.first, res.second);
    return max(alt, maxRes);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(7);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(8);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->left = new TreeNode(4);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(6);
    root->left->right->left->right = new TreeNode(10);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(10);

    cout<<"Length of longest consecutive sequence(either increasing or decreasing): "<<longestConsecutive(root)<<endl;
}