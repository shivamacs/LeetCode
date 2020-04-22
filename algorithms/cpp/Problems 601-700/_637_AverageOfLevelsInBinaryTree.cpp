/* Source - https://leetcode.com/problems/average-of-levels-in-binary-tree/
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

vector<double> averageOfLevels (TreeNode* root) {
    queue<TreeNode*> tq;
    TreeNode *front = NULL;
    int size, sum, count;
    vector<double> avgs;

    tq.push(root);

    while (!tq.empty()) {
        size = tq.size();
        sum = count = 0;
        while (size-- > 0) {
            front = tq.front();
            tq.pop();
            sum += front->data;
            count++;
            if (front->left) tq.push(front->left);
            if (front->right) tq.push(front->right);
        }
        avgs.push_back(double(sum)/double(count));
    }

    return avgs;
}

int main()
{
    TreeNode* root = NULL; 
    root = new TreeNode(4); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(9); 
    root->left->left = new TreeNode(3); 
    root->left->right = new TreeNode(5); 
    root->right->right = new TreeNode(7);

    vector<double> avgs = averageOfLevels(root);

    for (int i=0;i<avgs.size();i++) cout<<avgs[i]<<" ";
    cout<<endl;
}