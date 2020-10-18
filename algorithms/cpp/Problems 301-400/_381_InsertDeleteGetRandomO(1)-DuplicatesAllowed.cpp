/* Source - https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> map;
    vector<int> list;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool contains = map.find(val) == map.end();
        
        list.push_back(val);
        map[val].insert(list.size() - 1);
        
        return contains;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool contains = map.find(val) != map.end();
        
        if(contains == false)
            return false;
        
        int idx = *(map[val].begin());
        map[val].erase(idx);
        
        if(idx < list.size() - 1) {
            int last = list[list.size() - 1];
            list[idx] = last;
            map[last].erase(list.size() - 1);
            map[last].insert(idx);
        }
        
        list.pop_back();
        
        if(map[val].size() == 0)
            map.erase(val);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int random = rand() % list.size();
        return list[random];
    }
};

int main()
{
    RandomizedCollection obj;
    bool ins, del;

    ins = obj.insert(1);
    if (ins == true) cout<<"Inserted";
    else cout<<"Already present, inserted again.";
    cout<<endl;

    ins = obj.insert(1);
    if (ins == true) cout<<"Inserted";
    else cout<<"Already present, inserted again.";
    cout<<endl;

    ins = obj.insert(2);
    if (ins == true) cout<<"Inserted";
    else cout<<"Already present, inserted again.";
    cout<<endl;

    cout<<"Random: "<<obj.getRandom()<<endl;

    del = obj.remove(1);
    if (del == true) cout<<"Removed";
    else cout<<"Not present";
    cout<<endl;

    cout<<"Random: "<<obj.getRandom()<<endl;
}