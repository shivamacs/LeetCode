/* Source - https://leetcode.com/problems/binary-search-tree-iterator/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;

    TreeNode(int v) {
        val = v;
        left = right = NULL;
    }
};

class BSTIterator {
    stack<TreeNode*> st;
    TreeNode* curr;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        int return_val = -1;
        
        while(curr != NULL || !st.empty()) {
            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            return_val = curr->val;
            curr = curr->right;
            break;
        }
        
        return return_val;
    }
    
    bool hasNext() {
        return curr != NULL || !st.empty();
    }
};

int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* bstIterator = new BSTIterator(root);
    cout<<"Sample operations: "<<endl;
    cout<<"Next: "<<bstIterator->next()<<endl;
    cout<<"Next: "<<bstIterator->next()<<endl;
    cout<<"Has next: "<<boolalpha<<bstIterator->hasNext()<<endl;
    cout<<"Next: "<<bstIterator->next()<<endl;
    cout<<"Has next: "<<boolalpha<<bstIterator->hasNext()<<endl;
    cout<<"Next: "<<bstIterator->next()<<endl;
    cout<<"Has next: "<<boolalpha<<bstIterator->hasNext()<<endl;
    cout<<"Next: "<<bstIterator->next()<<endl;
    cout<<"Has next: "<<boolalpha<<bstIterator->hasNext()<<endl;
}