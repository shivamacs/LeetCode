/* Source - https://leetcode.com/problems/next-greater-element-iii/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

void swap (char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

static bool comparator(char a, char b) {
    return (a - '0') < (b - '0');
}

int nextGreaterElement(int n) {
    string num = to_string(n);
    int l = num.length();
    int i = l - 1;
    
    while (i > 0) {
        if ((num[i] - '0') > (num[i - 1] - '0')) {
            int next = i;
            
            for (int k = i + 1; k < l; k++)
                if ((num[k] - '0') > (num[i - 1] - '0') && (num[k] - '0') < (num[next] - '0'))
                    next = k;
                            
            swap(num[i - 1], num[next]);                
            sort(num.begin() + i, num.end(), comparator);
            
            break;
        }
        
        i--;
    }
    
    int result;
    
    try {
        result = stoi(num);
    }
    
    catch(out_of_range& e) {
        return -1;
    }
    
    return result == n ? -1 : result;
}

int main()
{
    int n;

    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Next greater integer: "<<nextGreaterElement(n)<<endl;
}