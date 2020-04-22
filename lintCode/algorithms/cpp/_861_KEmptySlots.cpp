/* Source - https://www.lintcode.com/problem/k-empty-slots/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int earliestTimeKEmpty(vector<int> position, int k) {
    int n = position.size();
    vector<int> time(n);

    for (int i = 0; i < n; i++)
        time[position[i] - 1] = i + 1;

    int i = 0, right = 0, empty = -1, earliest = -1;

    for (int j = (k + 2) - 1; j < n; j++) {
        for (right = i + 1; right < j; right++) {
            if (time[right] < time[i] || time[right] < time[j]) {
                i = right;
                j = i + k;
                break;
            }
        }

        if (right == j) {
            empty = max(time[i], time[j]);
            earliest = (earliest == -1) ? empty : min(earliest, empty);
            i++;
        }
    }

    return earliest;
}

int main()
{
    int n;

    cout<<"Enter the number of slots: ";
    cin>>n;

    vector<int> position(n);
    
    cout<<"Enter the values of position array: ";
    for (int i = 0; i < n; i++) cin>>position[i];

    int k;

    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Earliest time when K empty slots appear: "<<earliestTimeKEmpty(position, k)<<endl;
}