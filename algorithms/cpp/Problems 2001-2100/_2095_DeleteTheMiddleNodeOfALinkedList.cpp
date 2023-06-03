/*  Source - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
    Author - Shivam Arora
*/
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if(head->next == NULL)
        return NULL;

    ListNode* slow = head;
    ListNode* fast = head->next->next;
    
    while(fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow->next = slow->next->next;

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    head = deleteMiddle(head);

    if (head) {
        std::cout<<"List after deleting middle node: ";
        while(head and head->next) {
            std::cout<<head->val<<" -> ";
            head = head->next;
        }
        std::cout<<head->val<<std::endl;
    } else
        std::cout<<"NULL"<<std::endl;
}