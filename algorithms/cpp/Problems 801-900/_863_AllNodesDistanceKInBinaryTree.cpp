/* Source - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode (int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> distanceK (TreeNode *root, TreeNode* target, int k) {
    if (root == NULL) return {};
    
    vector<int> result;
    queue<TreeNode*> lq;
    TreeNode *front = NULL;
    map<TreeNode*, TreeNode*> parents;

    parents[root] = new TreeNode(-1);
    lq.push(root);

    while (!lq.empty()) {
        int size = lq.size();
        while (size-- > 0) {
            front = lq.front();
            lq.pop();
            if (front->left) { lq.push(front->left); parents[front->left] = front; }
            if (front->right) { lq.push(front->right); parents[front->right] = front;}
        }
    }

    queue<pair<TreeNode*, int>> tq;
    map<TreeNode*, bool> visited;
    pair<TreeNode*, int> f;

    visited[parents[root]] = 1;
    tq.push(make_pair(target, k));

    while (!tq.empty()) {
        f = tq.front();
        front = f.first;
        
        if (f.second == 0) break;
        
        k = f.second;
        
        tq.pop();

        if (front->left != NULL && visited.find(front->left) == visited.end()) tq.push(make_pair(front->left, k-1));
        if (front->right != NULL && visited.find(front->right) == visited.end()) tq.push(make_pair(front->right, k-1));
        if (visited.find(parents[front]) == visited.end()) tq.push(make_pair(parents[front], k-1));
        
        visited[front] = 1;
    }

    while (!tq.empty()) {
        result.push_back(tq.front().first->data);
        tq.pop();
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    int k;
    cout<<"Enter the value of K: ";
    cin>>k;

    vector<int> result = distanceK(root, root->left, k);

    for (int i=0;i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
}