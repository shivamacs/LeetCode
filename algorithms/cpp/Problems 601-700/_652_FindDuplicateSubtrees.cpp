/* Source - https://leetcode.com/problems/find-duplicate-subtrees/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode (int x) {
        data = x;
        left = right = NULL;
    }
};

string findDuplicateSubtreesUtil(TreeNode* root, unordered_map<string, int>& subtrees) {
    if (root == NULL) return "#";

    string left = findDuplicateSubtreesUtil(root->left, subtrees);
    string right = findDuplicateSubtreesUtil(root->right, subtrees);

    string subtree = to_string(root->data) + "," + left + right;

    if (subtrees.find(subtree) == subtrees.end()) subtrees[subtree] = 1;
    else if (subtrees[subtree] < 2) subtrees[subtree]++;

    return subtree;
}

TreeNode* deserialize(string data, int& i) {
    if (data[i] == '#') {
        i++;
        return NULL;
    }

    string val = "";
    while (data[i] != ',') {
        val += string(1, data[i]);
        i++;
    }
    i++;

    TreeNode* root = new TreeNode(stoi(val));

    root->left = deserialize(data, i);
    root->right = deserialize(data, i);

    return root;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> subtrees;
    int i;
    vector<TreeNode*> duplicates;

    findDuplicateSubtreesUtil(root, subtrees);

    unordered_map<string, int>::iterator iter;
    for (iter = subtrees.begin(); iter != subtrees.end(); iter++) {
        i = 0;
        if (iter->second == 2) duplicates.push_back(deserialize(iter->first, i));
    }
    
    return duplicates;
}

void printPreorder(TreeNode* root) {
    if (root == NULL) return;

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->right->left = new TreeNode(2); 
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    vector<TreeNode*> result = findDuplicateSubtrees(root);

    for (int i = 0; i < result.size(); i++) {
        printPreorder(result[i]);
        cout<<endl;
    }
}