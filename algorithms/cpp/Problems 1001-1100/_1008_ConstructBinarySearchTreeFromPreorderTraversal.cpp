/* Source - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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

TreeNode* preorderToBST(vector<int>& preorder) {
    if (preorder.empty()) return NULL;
    
    int n = preorder.size();

    stack<pair<pair<TreeNode*, bool>, pair<int, int>>> preStack;
    pair<pair<TreeNode*, bool>, pair<int, int>> top;

    TreeNode *root = new TreeNode(preorder[0]);
    
    preStack.push(make_pair(make_pair(root, false), make_pair(root->data, INT_MAX)));
    preStack.push(make_pair(make_pair(root, true), make_pair(INT_MIN, root->data)));

    int i = 1;

    while (i < n) {
        int item = preorder[i];
        
        top = preStack.top();
        preStack.pop();

        if (item > top.second.first && item < top.second.second) {
            TreeNode *node = new TreeNode(item);

            if (top.first.second) top.first.first->left = node;
            else top.first.first->right = node;
            
            preStack.push(make_pair(make_pair(node, false), make_pair(node->data, top.second.second)));
            preStack.push(make_pair(make_pair(node, true), make_pair(top.second.first, node->data)));
            
            i++;
        }
    }

    return root;
}

void printInorder(TreeNode *root) {
    TreeNode *curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            cout<<curr->data<<" ";
            curr = curr->right;
        }

        else {
            TreeNode *currP1 = curr->left;

            while (currP1->right && currP1->right != curr) currP1 = currP1->right;

            if (currP1->right == NULL) {
                currP1->right = curr;
                curr = curr->left;
            }

            else {
                currP1->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    vector<int> preorder(n);

    cout<<"Enter preorder: ";
    for (int i = 0; i < n; i++) cin>>preorder[i];

    TreeNode *root = preorderToBST(preorder);
    printInorder(root);
    cout<<endl;
}