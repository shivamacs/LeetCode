/* Source - https://leetcode.com/problems/lru-cache/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    public:
        struct DoublyNode {
            int key, val;
            DoublyNode *prev, *next;
            
            DoublyNode(int k, int v) {
                key = k;
                val = v;
                prev = next = NULL;
            }
        };
        
        unordered_map<int, DoublyNode*> nodeMap;
        DoublyNode *head, *tail;
        int capacity;
        
        LRUCache(int capacity) {
            this->capacity = capacity;
            
            head = new DoublyNode(-1, -1);
            tail = new DoublyNode(-1, -1);
            
            head->next = tail;
            tail->prev = head;
        }
        
        void insert(DoublyNode *curr) {
            DoublyNode *tailM1 = tail->prev;
            tailM1->next = curr;
            curr->prev = tailM1;
            curr->next = tail;
            tail->prev = curr;
        }
        
        void remove(DoublyNode *curr) {
            DoublyNode *currM1 = curr->prev;
            DoublyNode *currP1 = curr->next;
            
            currM1->next = currP1;
            currP1->prev = currM1;
            curr->prev = curr->next = NULL;
        }

        void display() {
            DoublyNode *temp = head->next;

            while(temp != tail) {
                cout<<temp->key<<","<<temp->val<<" --> ";
                temp = temp->next;
            }
            cout<<endl;
        }
        
        int get(int key) {
            if(nodeMap.find(key) == nodeMap.end())
                return -1;
            
            DoublyNode *curr = nodeMap[key];
            
            remove(curr);
            insert(curr);
            
            return curr->val;
        }
        
        void put(int key, int value) {
            if(nodeMap.find(key) != nodeMap.end()) {
                nodeMap[key]->val = value;
                get(key);
            } else {
                DoublyNode *newNode = new DoublyNode(key, value);
                
                if(nodeMap.size() == capacity) {
                    nodeMap.erase(head->next->key);
                    remove(head->next);
                }
                
                insert(newNode);
                nodeMap[key] = newNode;
            }
        }
};

int main()
{
    LRUCache cache(2);

    cache.put(2, 1);
    cache.display();
    cache.put(1, 1);
    cache.display();
    cache.put(2, 3);
    cache.display();
    cache.put(4, 1);
    cache.display();
    cout<<cache.get(1)<<endl;
    cache.display();
    cout<<cache.get(2)<<endl;
    cache.display();
}