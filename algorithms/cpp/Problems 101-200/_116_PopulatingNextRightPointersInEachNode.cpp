/* Source - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right, *next;

    Node(int v) {
        val = v;
        left = right = next = NULL;
    }  
};

// O(n) space
Node* connectApproach1(Node* root) {
    if(root == NULL)
        return NULL;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        
        while(size--) {
            Node* rnext = q.front();
            q.pop();
            
            if(rnext->left)
                q.push(rnext->left);
            if(rnext->right)
                q.push(rnext->right);
            
            if(size == 0)
                rnext->next = NULL;
            else
                rnext->next = q.front();
        }
    }
    
    return root;
}

// O(1) space
Node* connectApproach2(Node* root) {
    if(root == NULL)
        return NULL;
    
    Node* perm = root;
    
    while(perm->left != NULL) {
        Node* curr = perm;
        
        while(curr != NULL) {
            curr->left->next = curr->right;

            if(curr->next)
                curr->right->next = curr->next->left;
            
            curr = curr->next;
        }    
        
        perm = perm->left;
    }
    
    return root;
}

void printLevelOrder(Node* root) {
    cout<<"[";

    while(root != NULL) {
        Node* curr = root;

        while(curr != NULL) {
            cout<<curr->val<<", ";
            curr = curr->next;
        }

        cout<<"#, ";
        root = root->left;
    }

    cout<<"]"<<endl;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // cout<<"Level order of modified tree (using approach 1): ";
    // root = connectApproach1(root);
    // printLevelOrder(root);

    cout<<"Level order of modified tree (using approach 2): ";
    root = connectApproach2(root);
    printLevelOrder(root);
}