/* Source - https://leetcode.com/problems/maximum-swap/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num) {
    string number = to_string(num);
    int n = number.length();
    
    vector<int> index(10, -1);
    
    for (int i = 0; i < n; i++)
        index[number[i] - '0'] = i;
    
    bool flag = 0;
    
    for (int i = 0; i < n; i++) {
        int digit = number[i] - '0';
        
        for (int j = 9; j >= 0; j--) {
            if (digit < j && i < index[j]) {
                char temp = number[i];
                number[i] = number[index[j]];
                number[index[j]] = temp;
                
                flag = 1;
                break;
            }
        }
        
        if (flag == 1) break;
    }
    
    return stoi(number);
}

int main()
{
    int num;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<"Maximum possible number after one swap: "<<maximumSwap(num)<<endl;
}