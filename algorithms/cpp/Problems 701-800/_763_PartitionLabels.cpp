/* Source - https://leetcode.com/problems/partition-labels/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string S) {
    int n = S.length();
    unordered_map<char, int> lastOccur;
    
    for (int i = 0; i < n; i++)
        lastOccur[S[i]] = i;
    
    vector<int> result;
    
    int start = 0, i = 0, maxIndex = 0;
    
    while (i < n) {
        maxIndex = max(maxIndex, lastOccur[S[i]]);
        
        if (i == maxIndex) {
            result.push_back(i - start + 1);
            i++;
            start = i;
        }
        
        else i++;
    }
    
    return result;
}

int main()
{
    string S;

    cout<<"Enter a string: ";
    cin>>S;

    vector<int> result = partitionLabels(S);

    cout<<"Length of partitions such that each character appears in atmost one part: ";
    for (int i = 0; i < result.size() - 1; i++)
        cout<<result[i]<<", ";
    cout<<result[result.size() - 1]<<endl;
}