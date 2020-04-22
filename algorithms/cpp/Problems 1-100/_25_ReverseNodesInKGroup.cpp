/* Source - https://leetcode.com/problems/reverse-nodes-in-k-group/
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

void push(Node **head_ref, int x) {
    Node *ptr = new Node(x);
    ptr->next = *head_ref;
    *head_ref = ptr;
}

Node* reverseInKGroups (Node *head, int k) {
    Node *prev = NULL, *current = head, *temp = NULL;
    int count = 0;

    while (current != NULL && count < k) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }

    if (temp != NULL) head->next = reverseInKGroups(temp, k);

    return prev;
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
    Node* head = NULL;  
    /* Linked list is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);  
    push(&head, 8);  
    push(&head, 7);  
    push(&head, 6);  
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);

    cout<<"Original linked list: ";
    display(head);

    int k;
    cout<<"Enter value of k: ";
    cin>>k;

    Node *result = reverseInKGroups(head, k);
    cout<<"Linked list reversed in k groups: ";
    display(result);

    delete(head);
    delete(result);
}