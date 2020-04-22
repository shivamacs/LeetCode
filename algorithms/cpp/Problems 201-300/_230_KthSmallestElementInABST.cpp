/* Source - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left, *right;

    TreeNode (int x) {
        data = x;
        left = right = NULL;
    }
};

int counter = 0;
int s;

void getKthSmallest (TreeNode* root, int k) {
    if (root == NULL) return;
    
    getKthSmallest(root->left, k);
    
    if (counter == k) return;
    s = root->data;
    counter++;
    
    getKthSmallest(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    getKthSmallest(root, k);
    return s;
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

    int k;
    cout<<"Enter the value of K: ";
    cin>>k;

    cout<<"Kth smallest element in the given bst is: "<<kthSmallest(root, k)<<endl;
}