/* Source - https://leetcode.com/problems/reverse-linked-list/
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

class LinkedList {
    private:
        Node *head = NULL;

    public:
        Node* list() { return head; }
        void push(int x);
        Node* reverse();
        Node* reverseUsingStack();
};

void LinkedList :: push (int x) {
    Node *newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

// approach 1
Node* LinkedList :: reverse() {
    Node *prev = NULL, *current = head, *temp = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
    delete(temp);
    delete(current);

    return head;
}

// approach 2
Node* LinkedList :: reverseUsingStack() {
    stack<int> s;
    Node *temp = head;

    while (temp) {
        s.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    
    while (temp) {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    
    return head;
}

void display(Node *head) {
    Node *temp = head;
    
    while (temp->next != NULL) {
        cout<<temp->data<<" <- ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main()
{
    LinkedList ll; 
    ll.push(20); 
    ll.push(4); 
    ll.push(15); 
    ll.push(85);

    cout<<"Original list: ";
    display(ll.list());
    
    cout<<"Reverse using Node reversal: ";
    display(ll.reverse());
    
    cout<<"Reverse the list back using stack: ";
    display(ll.reverseUsingStack());
}