/* Source - https://leetcode.com/problems/linked-list-cycle-ii/
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

void push(Node **head, int x) {
    Node *ptr = new Node(x);
    ptr->next = *head;
    *head = ptr;
}

int detectLoop (Node *head) {
    Node *slow, *fast;
    slow = fast = head;
    int m = 0;
    bool flag = 0;
    
    while (slow && fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { flag = 1; break; }
    }

    if (flag == 1) {
        slow = head;
        // finding the starting index of loop
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
            m++;
        }
        delete(slow);
        delete(fast);
        return m;
    }

    return -1;
}

int main()
{
    Node *head = NULL;
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
    head->next->next->next->next = head;

    int meetingIndex = detectLoop(head);
    if (meetingIndex == -1) cout<<"No loop found.";
    else cout<<"Loop is found at node index "<<meetingIndex<<".";
    cout<<endl;

    delete(head);
}