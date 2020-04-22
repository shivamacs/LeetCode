/* Source - https://leetcode.com/problems/remove-duplicates-from-sorted-list/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node (int x) {
        data = x;
        next = NULL;
    }
};

void push (Node **head_ref, int x) {
    Node *ptr = new Node(x);
    ptr->next = *head_ref;
    *head_ref = ptr;
}

Node* removeDuplicatesSortedLL (Node *head) {
    if (head == NULL) return head;
    Node *prev = head, *curr = head->next;

    while (curr != NULL) {
        if (prev->data == curr->data) prev->next = curr->next;
        else prev = curr;

        curr = curr->next;
    }

    delete(curr);

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

    push(&head, 20);  
    push(&head, 13);  
    push(&head, 13);  
    push(&head, 12);  
    push(&head, 11);  
    push(&head, 11);

    cout<<"Original Linked List: ";
    display(head);

    head = removeDuplicatesSortedLL(head);
    cout<<"Linked list after removing duplicates: ";
    display(head);
}