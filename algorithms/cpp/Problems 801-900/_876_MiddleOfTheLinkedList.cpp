/* Source - https://leetcode.com/problems/middle-of-the-linked-list/
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

int findMiddle (Node *head) {
    Node *slow, *fast;
    slow = fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
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
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout<<"Original Linked list: ";
    display(head);

    cout<<"Middle element of the linked list: ["<<findMiddle(head)<<"]"<<endl;
}