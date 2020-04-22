/* Source - https://leetcode.com/problems/diameter-of-binary-tree/
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

int height(TreeNode *root) {
    if (root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

// approach 1
int treeDiameterDFS(TreeNode *root) {
    if (root == NULL) return 0;

    return max(height(root->left) + height(root->right) + 1, max(treeDiameterDFS(root->left), treeDiameterDFS(root->right)));
}

// approach 2
int treeDiameterBFS(TreeNode *root) {
    if (root == NULL) return 0;

    queue<TreeNode*> tq;
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode *front = NULL;
    
    tq.push(root);
    parent[root] = new TreeNode(INT_MIN);

    while(!tq.empty()) {
        front = tq.front();
        tq.pop();

        if (front->left) {
            tq.push(front->left);
            parent[front->left] = front;
        }

        if (front->right) {
            tq.push(front->right);
            parent[front->right] = front;
        }
    }

    unordered_map<TreeNode*, bool> visited;

    tq.push(front);
    
    int size, diameter = 0;
    while(!tq.empty()) {
        size = tq.size();
        while(size-- > 0) {
            front = tq.front();
            tq.pop();

            if (front->left && visited.find(front->left) == visited.end()) tq.push(front->left);
            if (front->right && visited.find(front->right) == visited.end()) tq.push(front->right);

            if (parent[front]->data != INT_MIN && visited.find(parent[front]) == visited.end()) tq.push(parent[front]);

            visited[front] = 1;
            visited[parent[front]] = 1;
        }
        diameter++;
    }

    return diameter;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5);

    cout<<"Diameter of the tree using DFS is: "<<treeDiameterDFS(root)<<endl; 
    cout<<"Diameter of the tree using BFS is: "<<treeDiameterBFS(root)<<endl;
}
