/* Source - https://leetcode.com/problems/multiply-strings/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string multiplyStrings(string s1, string s2) {
    if (s1 == "0" || s2 == "0")
        return "0";
        
    string result;

    int m = s1.length(), n = s2.length();
    vector<int> product(m + n);
        
    int index1 = 0, index2 = 0, neg1 = 0, neg2 = 0;
    
    if (s1[0] == '-' && s2[0] != '-') {
        result += "-";
        neg1 = 1;
    } else if (s1[0] != '-' && s2[0] == '-') {
        result += "-";
        neg2 = 1;
    } else if (s1[0] == '-' && s2[0] == '-')
        neg1 = neg2 = 1;
    
    for (int j = n - 1; j >= neg2; j--) {
        for (int i = m - 1; i >= neg1; i--) {
            int val = (s1[i] - '0') * (s2[j] - '0') + product[i + j + 1];
            index1 = val / 10;
            index2 = val % 10;
            
            product[i + j] += index1;
            product[i + j + 1] = index2;
        }
    }
        
    int i = 0;
    while (i < product.size() && product[i] == 0) {
        i++;
    }
    
    if (i == product.size())
        i = 1;

    for (i; i < product.size(); i++)
        result += to_string(product[i]);
    
    return result;
}

int main() {
    string num1, num2;
    cout<<"Enter two strings (representing numbers) to multiply: "<<endl;
    cin>>num1>>num2;

    cout<<"Product of strings: "<<multiplyStrings(num1, num2)<<endl;
}