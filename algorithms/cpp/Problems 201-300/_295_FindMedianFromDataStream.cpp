/* Source - https://leetcode.com/problems/find-median-from-data-stream/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;
    
    public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(right.size() > 0 && num > right.top())
            right.push(num);
        else
            left.push(num);
        
        if(left.size() - right.size() == 2) {
            int l = left.top();
            left.pop();
            right.push(l);
        } else if(right.size() - left.size() == 2) {
            int r = right.top();
            right.pop();
            left.push(r);
        }
    }
    
    double findMedian() {
        if(left.size() == right.size())
            return (left.top() + right.top()) / 2;
        else if(left.size() > right.size())
            return left.top();
        else
            return right.top();
    }
};


int main()
{
    int n;

    cout<<"Enter size of input: ";
    cin>>n;

    vector<string> operations(n);

    cout<<"Enter operations (for addNum, write 'addNum <value>'): "<<endl;
    for(int i = 0; i < n; i++)
        getline(cin>>ws, operations[i]);

    MedianFinder obj;
    vector<string> result;

    for(int i = 0; i < n; i++) {
        if(operations[i].find("addNum") != string::npos) {
            string token = operations[i].substr(operations[i].find(" ") + 1);
            obj.addNum(stoi(token));
            result.push_back("null");
        } else if(operations[i].find("findMedian") != string::npos) {
            result.push_back(to_string(obj.findMedian()));
        } else 
            result.push_back("null");           
    }

    cout<<"Output: ";
    for(int i = 0; i < n; i++)
        cout<<result[i]<<" ";
    cout<<endl;
}