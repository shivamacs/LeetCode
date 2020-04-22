/* Source - https://leetcode.com/problems/sort-array-by-parity/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortArrayByParity(vector<int>& A) {
    int start = 0, end = 0, n = A.size();
    
    while (end < n) {
        if (A[end] % 2 == 0) {
            swap(A[start], A[end]);
            start++;
            end++;
        }
        
        else end++;
    }
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> A(n);

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++)
        cin>>A[i];

    sortArrayByParity(A);

    cout<<"Array sorted by parity(even first): ";
    for (int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}