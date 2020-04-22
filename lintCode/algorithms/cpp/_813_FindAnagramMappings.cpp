/* Source - https://www.lintcode.com/problem/find-anagram-mappings/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

 vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> mapping;
    vector<int> result;
    
    for (int i = 0; i < B.size(); i++)
        mapping[B[i]] = i;
        
    for (int i = 0; i < A.size(); i++)
        result.push_back(mapping[A[i]]);
        
    return result;
}

int main()
{
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> A(n), B(n);

    cout<<"Enter elements for first array: ";
    for (int i = 0; i < A.size(); i++) cin>>A[i];

    cout<<"Enter elements for second array: ";
    for (int i = 0; i < B.size(); i++) cin>>B[i];

    vector<int> result = anagramMappings(A, B);

    cout<<"Anagram mapping from A to B: ";
    for (int i = 0; i < result.size(); i++) cout<<result[i]<<" ";
    cout<<endl;
}