/* Source - https://leetcode.com/problems/copy-list-with-random-pointer/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *random;

    Node (int x) {
        data = x;
        next = random = NULL;
    }
};

void push (Node **head, int x) {
    Node *ptr = new Node(x);
    ptr->next = *head;
    *head = ptr;
}

// approach 1
Node *cloneListWithSpace(Node *head) {
    Node *original = head, *cloneCurr = NULL;
    unordered_map<Node*, Node*> cloneMap;
    
    while (original != NULL) {
        cloneMap[original] = new Node(original->data);
        original = original->next;
    }

    original = head;

    while (original != NULL) {
        cloneCurr = cloneMap[original];
        cloneCurr->next = cloneMap[original->next];
        cloneCurr->random = original->random;
        original = original->next;
    }

    delete(original);

    return cloneMap[head];
}

// approach 2
Node *cloneListWithoutSpace(Node *head) {
    Node *current = head, *temp = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = new Node(current->data);
        current->next->next = temp;
        current = temp;
    }

    current = head;

    while (current != NULL) {
        if (current->next) current->next->random = current->random ? current->random->next : current->random;
        current = current->next ? current->next->next : current->next;
    }

    current = head;
    temp = head ? head->next : head;
    Node *clone = temp;

    while (current != NULL && temp != NULL) {
        current->next = current->next ? current->next->next : current->next;
        temp->next = temp->next ? temp->next->next : temp->next;
        current = current->next;
        temp = temp->next;
    }

    delete(temp);
    delete(current);

    return clone;
}

void display (Node **head) {
    Node *temp = *head;

    while (temp->next != NULL) {
        cout<<temp->data<<"("<<temp->random->data<<")"<<" <- ";
        temp = temp->next;
    }
    cout<<temp->data<<"("<<temp->random->data<<")"<<endl;
}

int main()
{
    Node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    head->random = head->next->next;
    head->next->random = head; 
    head->next->next->random = head->next->next->next->next; 
    head->next->next->next->random = head->next->next->next->next; 
    head->next->next->next->next->random = head->next;

    cout<<"Original list: ";
    display(&head);

    Node *clone = cloneListWithSpace(head);
    cout<<"Cloned list using space(hashmap): ";
    display(&clone);

    clone = cloneListWithoutSpace(head);
    cout<<"Cloned list without using space: ";
    display(&clone);
}