/* Source - https://leetcode.com/problems/validate-stack-sequences/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

bool validateStackSequences (vector<int>& pushed, vector<int>& popped) {
    int i = 0, j = 0, n = pushed.size();
    stack<int> s;

    while (i<n && j<n) {
        if (pushed[i] != popped[j]) {
            if (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
            else {
                s.push(pushed[i]);
                i++;
            }
        }

        else if (pushed[i] == popped[j]) {
            i++;
            j++;
        }
    }

    while (j<n) {
        if (s.top() == popped[j]) {
            s.pop();
            j++;
        }
        else break;
    }

    if (s.empty() && j == n) return true;
    else return false;

}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> pushed(n), popped(n);

    cout<<"Enter pushed sequence: ";
    for (int i=0;i<n;i++) cin>>pushed[i];

    cout<<"Enter popped sequence: ";
    for (int i=0;i<n;i++) cin>>popped[i];

    cout<<"Sequence validation: "<<validateStackSequences(pushed, popped)<<endl;
}