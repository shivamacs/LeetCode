/* Source - https://leetcode.com/problems/lru-cache/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

struct DoublyNode {
    int data;
    DoublyNode *prev, *next;

    DoublyNode (int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

void add(DoublyNode **head, int x) {
    DoublyNode *ptr = new DoublyNode(x);
    ptr->next = *head;
    if (*head != NULL) (*head)->prev = ptr;
    *head = ptr;
}

class LRUCache {
    private:
        DoublyNode *head = NULL, *tail = NULL;
        map<DoublyNode*, int> nodeKey;
        map<int, DoublyNode*> keyNode;
        int k, count;

    public:
        LRUCache(int capacity) {
            k = capacity;
            count = 0;
            add(&head, -2);
            add(&head, -1);
            tail = head->next;  
        }
        void recentlyUsed (int key);
        int get(int key);
        void put(int key, int value);
        DoublyNode *getCache() { return head; }
};

void LRUCache :: recentlyUsed (int key) {
    keyNode[key]->prev->next = keyNode[key]->next;
    keyNode[key]->next->prev = keyNode[key]->prev;
    tail->prev->next = keyNode[key];
    keyNode[key]->next = tail;
    keyNode[key]->prev = tail->prev;
    tail->prev = keyNode[key];
}

int LRUCache :: get (int key) {

    if (keyNode.find(key) == keyNode.end()) return -1;

    if (tail->prev != keyNode[key]) recentlyUsed(key);

    return keyNode[key]->data;
}

void LRUCache :: put (int key, int value) {
    if (!(keyNode.find(key) == keyNode.end())) { keyNode[key]->data = value; recentlyUsed(key); }

    else {
        if (count >= k) {
            keyNode.erase(nodeKey[head->next]);
            nodeKey.erase(head->next);
            head->next->next->prev = head;
            head->next = head->next->next;
            count--;
        }

        DoublyNode* newNode = new DoublyNode(value);
        tail->prev->next = newNode;
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        count++;
        keyNode[key] = newNode;
        nodeKey[newNode] = key;
    }
}

void displayCache(DoublyNode *l) {
    if (l == NULL) { cout<<"NULL"<<endl; return; }
    
    DoublyNode *temp = l;

    while (temp->next != NULL) {
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    
    cout<<temp->data<<endl;
}

int main()
{
    LRUCache cache(2);

    cache.put(2, 1);
    displayCache(cache.getCache());
    cache.put(1, 1);
    displayCache(cache.getCache());
    cache.put(2, 3);
    displayCache(cache.getCache());
    cache.put(4, 1);
    displayCache(cache.getCache());
    cout<<cache.get(1)<<endl;
    displayCache(cache.getCache());
    cout<<cache.get(2)<<endl;
    displayCache(cache.getCache());
}