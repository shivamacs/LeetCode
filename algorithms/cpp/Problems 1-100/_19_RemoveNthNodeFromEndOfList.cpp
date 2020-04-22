/* Source - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node (int x) {
        data = x;
    }
};

void push (Node **head_ref, int x) {
    Node *ptr = new Node(x);
    ptr->next = *head_ref;
    *head_ref = ptr;
}

int findNthNodeFromEnd (Node *head, int n) {
    Node *slow, *fast;
    slow = fast = head;
    int ntemp = n, count = 1;
    
    while (ntemp-- > 1 && fast->next != NULL) {
        fast = fast->next;
        count++;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
        count++;
    }
    
    return (n <= count) ? slow->data : -1;
}

Node* removeNthNodeFromEnd (Node *head, int n) {
    if (head == NULL) return head;
        
    Node *slow, *fast, *prev = NULL;
    slow = fast = head;

    while (n-- > 1 && fast->next != NULL) fast = fast->next;

    while (fast->next != NULL) {
        prev = slow; 
        fast = fast->next;
        slow = slow->next;
    }

    if (prev) prev->next = slow->next;
    else head = slow->next;
    
    return head; 
}

void display (Node *head) {
    Node *temp = head;

    while (temp->next != NULL) {
        cout<<temp->data<<" <- ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main()
{
    Node *head = NULL;
    int n = 0;

    push(&head, 20); 
    push(&head, 12); 
    push(&head, 15); 
    push(&head, 35);
    push(&head, 25);
    push(&head, 16);
    push(&head, 40);

    cout<<"Original Linked list: ";
    display(head);

    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"Nth node from the end: "<<findNthNodeFromEnd(head, n)<<endl;
    
    head = removeNthNodeFromEnd(head, n);
    cout<<"List after removing Nth node from the end: ";
    display(head);
}