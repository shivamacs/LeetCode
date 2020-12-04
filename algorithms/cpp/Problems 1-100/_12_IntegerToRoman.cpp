/* Source - https://leetcode.com/problems/integer-to-roman/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    int range = num / 10;
    string ans = "";
            
    if(range == 0) {
        if(num < 4) {
            while(num--)
                ans += "I";
            
            return ans;
        } else if(num == 4)
            ans = "IV";
        else if(num < 9)
            ans = "V" + intToRoman(num - 5);
        else
            ans = "IX";
    } else if(range >= 1 && range < 5) {
        if(num >= 40)
            ans = "XL" + intToRoman(num - 40);
        else 
            ans = "X" + intToRoman(num - 10);
    } else if(range >= 5 && range < 10) {
        if(num >= 90)
            ans = "XC" + intToRoman(num - 90);
        else
            ans = "L" + intToRoman(num - 50);
    } else if(range >= 10 && range < 50) {
        if(num >= 400)
            ans = "CD" + intToRoman(num - 400);
        else
            ans = "C" + intToRoman(num - 100);
    } else if(range >= 50 && range < 100) {
        if(num >= 900)
            ans = "CM" + intToRoman(num - 900);
        else
            ans = "D" + intToRoman(num - 500);
    } else if(range >= 100)
        ans = "M" + intToRoman(num - 1000);
    
    return ans;
}

int main()
{
    int num;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<num<<" to roman numeral: "<<intToRoman(num)<<endl;
}