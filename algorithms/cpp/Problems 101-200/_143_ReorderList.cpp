/* Source - https://leetcode.com/problems/reorder-list/
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

ListNode* reverse(ListNode* head) {
    ListNode *prev = NULL;
    
    while(head != NULL) {
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    
    return prev;
}

void reorderList(ListNode* head) {
    ListNode* slow = head, *fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
            
    ListNode* revSecond = reverse(slow);
    ListNode* temp = head;
    
    while(temp != NULL && revSecond != NULL) {
        ListNode* t1 = temp->next;
        ListNode* t2 = revSecond->next;
        temp->next = revSecond;
        revSecond->next = t1;
        temp = t1;
        revSecond = t2;
    }
    
    if(temp != NULL)
        temp->next = NULL;
}

int main()
{
    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    int a;
    ListNode *head = NULL;

    cout<<"Enter values of nodes: ";
    for(int i = 0; i < n; i++) {
        cin>>a;
        add(&head, a);
    }

    reorderList(head);

    cout<<"List after reordering: ";
    while(head->next != NULL) {
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<head->val<<endl;
}