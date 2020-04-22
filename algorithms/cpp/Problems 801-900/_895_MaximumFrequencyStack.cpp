/* Source - https://leetcode.com/problems/maximum-frequency-stack/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    unordered_map<int, int> freqMap;
    map<int, stack<int>> freqStackMap;
    int maxFrequency;
    
    FreqStack() {
        freqMap.clear();
        freqStackMap.clear();
        maxFrequency = 0;
    }
    
    void push(int x) {
        freqMap[x]++;
        freqStackMap[freqMap[x]].push(x);
        
        if (freqMap[x] >= maxFrequency)
            maxFrequency = freqMap[x];
    }
    
    int pop() {
        stack<int> *temp = &freqStackMap[maxFrequency];
        
        int element = temp->top();
        temp->pop();
        
        if (--freqMap[element] == 0) freqMap.erase(element);
        
        if (temp->empty()) {
            freqStackMap.erase(maxFrequency);
            
            if (!freqStackMap.empty())
                maxFrequency--;
        }
                
        return element;
    }
};

int main()
{
    FreqStack f;
    f.push(5);
    f.push(7);
    f.push(5);
    f.push(7);
    f.push(4);
    f.push(5);
    cout<<"Most frequent element popped: "<<f.pop()<<endl;
    cout<<"Most frequent element popped: "<<f.pop()<<endl;
    cout<<"Most frequent element popped: "<<f.pop()<<endl;
    cout<<"Most frequent element popped: "<<f.pop()<<endl;
}