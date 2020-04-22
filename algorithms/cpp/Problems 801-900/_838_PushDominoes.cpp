/* Source - https://leetcode.com/problems/push-dominoes/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string pushDominoes(string dominoes) {
    dominoes = 'L' + dominoes + 'R';

    int n = dominoes.length(), i, j, k;

    i = 0, j = i + 1;

    while (j < n) {
        while (dominoes[j] != 'L' && dominoes[j] != 'R')
            j++;

        if (dominoes[i] == 'L' && dominoes[j] == 'L') {
            for (k = i + 1; k < j; k++)
                dominoes[k] = 'L';
        }

        else if (dominoes[i] == 'R' && dominoes[j] == 'R') {
            for (k = i + 1; k < j; k++)
                dominoes[k] = 'R';
        }

        else if (dominoes[i] == 'R' && dominoes[j] == 'L') {
            for (k = i + 1; k < (i + j + 1) / 2; k++)
                dominoes[k] = 'R';

            for (k = j - 1; k > (i + j) / 2; k--)
                dominoes[k] = 'L';
        }

        i = j;
        j = i + 1;
    }
    
    return dominoes.substr(1, dominoes.length() - 2);
}

int main()
{
    string dominoes;

    cout<<"Enter domino string: ";
    cin>>dominoes;

    cout<<"String in final state: "<<pushDominoes(dominoes)<<endl;
}