/* Source - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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

string serialize (TreeNode* root) {
    if (root == NULL) return "#";

    string left = serialize(root->left);
    string right = serialize(root->right);

    return to_string(root->data) + "*" + left + right;
}

TreeNode* deserializeUtil (string serialized, int &i) {
    if (serialized[i] == '#') {
        i++;
        return NULL;
    }

    string val = "";
        
    while(serialized[i] != '*') {
        val += string(1, serialized[i]);
        i++;
    }
    i++;

    TreeNode* root = new TreeNode(stoi(val));
    
    root->left = deserializeUtil(serialized, i);
    root->right = deserializeUtil(serialized, i);

    return root;
}

TreeNode* deserialize (string serialized) {
    int i = 0;

    return deserializeUtil(serialized, i);
}

void printInorder (TreeNode *root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9); 
    root->right->right = new TreeNode(7);

    string serialized = serialize(root);
    cout<<"Tree serialized in a string: "<<serialized<<endl;
    cout<<"Inorder of deserialized tree: ";
    printInorder(deserialize(serialized));
    cout<<endl;
}