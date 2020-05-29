/* Source - https://leetcode.com/problems/palindrome-linked-list/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int v) {
        val = v;
        next = NULL;
    }
};

void add(ListNode **node_ref, int data) {
    ListNode *newNode = new ListNode(data);

    if(*node_ref == NULL) {
        *node_ref = newNode;
        return;
    }

    ListNode *temp = *node_ref;
    
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int size = 0;
ListNode *start = NULL;

bool _isPalindrome(ListNode *node, int n) {
    if(node == NULL)
        return true;
    
    bool answer = _isPalindrome(node->next, n + 1);
    
    if(answer == false)
        return false;
    
    if(n >= (size / 2)) {
        if(node->val != start->val)
            return false;
        
        start = start->next;
    }
    
    return true;
}

bool isPalindrome(ListNode* head) {
    start = head;
    ListNode *temp = head;
    
    while(temp != NULL) {
        size++;
        temp = temp->next;
    }
    
    return _isPalindrome(head, 0);
}

int main() {
    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    int a;
    ListNode *head;

    cout<<"Enter values of nodes: ";
    for(int i = 0; i < n; i++) {
        cin>>a;
        add(&head, a);
    }

    cout<<"Is linked list a palindrome? "<<boolalpha<<isPalindrome(head)<<endl;
}