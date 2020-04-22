/* Source - https://leetcode.com/problems/binary-tree-right-side-view/
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

vector<int> righttSideView(TreeNode* root) {
    if (root == NULL) return {};

    vector<int> rsv;
    queue<TreeNode*> tq;
    TreeNode* front = NULL;
    int size, f;

    tq.push(root);

    while (!tq.empty()) {
        size = tq.size();
        f = 1;
        while (size-- > 0) {
            front = tq.front();
            tq.pop();

            if (size < f) rsv.push_back(front->data);

            if (front->left) tq.push(front->left);
            if (front->right) tq.push(front->right);
        }
    }

    return rsv;
}

int main()
{
    TreeNode* root = new TreeNode(12); 
    root->left = new TreeNode(10); 
    root->right = new TreeNode(30); 
    root->right->left = new TreeNode(25); 
    root->right->right = new TreeNode(40); 

    vector<int> result = righttSideView(root);
    cout<<"Right side view: ";
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
}