/* Source - https://leetcode.com/problems/array-of-doubled-pairs/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool canReorderDoubled(vector<int>& A) {
    map<int, int> freqMap;
    map<int, int>::iterator iter;
    bool flag = 1;
    
    for (int i = 0; i < A.size(); i++) freqMap[A[i]]++;

    for (iter = freqMap.begin(); iter != freqMap.end(); ++iter) {
        if (!(freqMap.find(iter->first/2) == freqMap.end()) && freqMap[iter->first] > 0 && freqMap[iter->first/2] > 0) {
            freqMap[iter->first/2]--;
            freqMap[iter->first]--;
        }
        if (freqMap[iter->second] != 0 && freqMap[iter->second/2] != 0) flag = 0;
        else flag = 1;
    }

    return flag;
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) cin>>A[i];

    if (canReorderDoubled(A) == true) cout<<"The given array can form doubled pairs.";
    else cout<<"The given array can not form doubled pairs.";
    cout<<endl;
}