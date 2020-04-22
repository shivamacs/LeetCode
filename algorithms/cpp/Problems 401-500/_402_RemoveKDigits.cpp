/* Source - https://leetcode.com/problems/remove-k-digits/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

string removeKDigits (string num, int k) {
    int i = 0, bk = k, n = num.size();
    deque<char> q;

    q.push_back(num[i]);
    i++;

    while (i < n) {
        while (!q.empty() && num[i] < q.back() && k > 0) { q.pop_back(); k--; }
        q.push_back(num[i]); 
        i++;
    }

    while (!q.empty() && q.size() > n - bk) q.pop_back();
    while (!q.empty() && q.front() == '0') q.pop_front();
    
    if (q.empty()) return "0";
    
    string result = "";
    while (!q.empty()) {
        result += q.front();
        q.pop_front();
    }

    return result;
}

int main()
{
    int k;
    string num;

    cout<<"Enter a non-negative number: ";
    getline(cin, num);

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Smallest possible number after removing k digits: "<<removeKDigits(num, k)<<endl;
}