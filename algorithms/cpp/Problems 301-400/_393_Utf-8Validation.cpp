/* Source - https://leetcode.com/problems/utf-8-validation/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

bool validUtf8(vector<int>& data) {
    int count = 0;
    
    for(int i = 0; i < data.size(); i++) {
        if(count != 0) {
            if((data[i] >> 6) == 0b10)
                count--;
            else
                return false;
        } else {
            if((data[i] >> 7) == 0b0)
                count = 0;
            else if((data[i] >> 5) == 0b110)
                count = 1;
            else if((data[i] >> 4) == 0b1110)
                count = 2;
            else if((data[i] >> 3) == 0b11110)
                count = 3;
            else
                return false;
        }
    }
    
    return count == 0;
}

int main()
{
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    cout<<"Does the array represent a valid sequence of UTF-8 characters? "<<boolalpha<<validUtf8(arr)<<endl;
}