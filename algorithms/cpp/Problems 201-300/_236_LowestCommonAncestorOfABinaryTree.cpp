/* Source - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left, *right;

    TreeNode(int x) {
        data = x;
        left = right = NULL;
    }
};

map<TreeNode*, TreeNode*> parent;
map<TreeNode*, TreeNode*> grandParent;
map<TreeNode*, int> level;

int height (TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void preprocessing(TreeNode* root) {
    queue<TreeNode*> tq;
    TreeNode *front = NULL;
    int size, l = 0, h = height(root);
    int boxsize = ceil(sqrt(h));

    tq.push(root);
    TreeNode* extra = new TreeNode(-1);
    parent[root] = extra;
    grandParent[root] = extra;
    level[root] = l;
    l++;
    
    while(!tq.empty()) {
        size = tq.size();
        while(size-- > 0) {
            front = tq.front();
            tq.pop();

            if (front->left) {
                tq.push(front->left);
                parent[front->left] = front;
                level[front->left] = l;
                if (l % boxsize != 0) grandParent[front->left] = grandParent[front];
                else grandParent[front->left] = front;
            }

            if (front->right) {
                tq.push(front->right);
                parent[front->right] = front;
                level[front->right] = l;
                if (l % boxsize != 0) grandParent[front->right] = grandParent[front];
                else grandParent[front->right] = front;
            }
        }
        l++;
    }
}

TreeNode* lowestCommonAncestor (TreeNode* root, TreeNode *p, TreeNode *q) {
    while (grandParent[p] != grandParent[q] && p != q) {
        if (level[p] < level[q]) q = grandParent[q];
        else if (level[p] > level[q]) p = grandParent[p];
        else {
            p = grandParent[p];
            q = grandParent[q];
        }
    }

    while (level[p] != level[q]) {
        if (level[p] < level[q]) q = parent[q];
        else if (level[p] > level[q]) p = parent[p];
    }

    while (p != q) {
        p = parent[p];
        q = parent[q];
    }

    return p;
}

int main()
{
    TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5); 
    root->right->left = new TreeNode(6); 
    root->right->right = new TreeNode(7);

    preprocessing(root);

    cout<<"LCA(4, 5) = "<<lowestCommonAncestor(root, root->left->left, root->left->right)->data<<endl; 
    cout<<"LCA(4, 6) = "<<lowestCommonAncestor(root, root->left->left, root->right->right)->data<<endl;
}