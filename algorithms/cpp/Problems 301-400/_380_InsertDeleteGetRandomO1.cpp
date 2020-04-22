/* Source - https://leetcode.com/problems/insert-delete-getrandom-o1/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> indexMap;
    vector<int> data;
    int index;
    
    public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        indexMap.clear();
        data.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (indexMap.find(val) == indexMap.end()) {
            data.push_back(val);
            indexMap[val] = data.size() - 1;
            return true;
        }
        
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (indexMap.find(val) != indexMap.end()) {
            int lastIndex = data.size() - 1;
            
            if (data[lastIndex] != val) {
                int temp = data[indexMap[val]];
                data[indexMap[val]] = data[lastIndex];
                data[lastIndex] = temp;

                indexMap[data[indexMap[val]]] = indexMap[val];
            }

            data.pop_back();
            indexMap.erase(val);
            
            return true;
        }
        
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % data.size();
                
        return data[random];
    }
};

int main()
{
    RandomizedSet obj;
    bool ins, del;

    ins = obj.insert(1);
    if (ins == true) cout<<"Inserted";
    else cout<<"Already present";
    cout<<endl;

    del = obj.remove(2);
    if (del == true) cout<<"Removed";
    else cout<<"Not present";
    cout<<endl;

    ins = obj.insert(2);
    if (ins == true) cout<<"Inserted";
    else cout<<"Already present";
    cout<<endl;

    cout<<"Random: "<<obj.getRandom()<<endl;

    del = obj.remove(1);
    if (del == true) cout<<"Removed";
    else cout<<"Not present";
    cout<<endl;

    ins = obj.insert(2);
    if (ins == true) cout<<"Inserted";
    else cout<<"Already present";
    cout<<endl;

    cout<<"Random: "<<obj.getRandom()<<endl;
}