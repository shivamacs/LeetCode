/* Source - https://leetcode.com/problems/fraction-to-recurring-decimal/
   Author - Shivam Arora
*/
#include<bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    unordered_map<int, int> modMap;
        string str1 = "", str2 = "";
        
    long n = long(numerator), d = long(denominator);
    
    if (float(n) / float(d) < 0 && float(n) / float(d) > -1)
        str1 += "-";
    
    str1 += to_string(n / d);
            
    if (n % d == 0) return str1;
    
    int i = 0;
    long mod, quotient;
    
    n = abs(n), d = abs(d);
    str1 += ".";
    mod = n % d;

    do {
        modMap[mod] = i++;
        mod *= 10;

        quotient = mod / d;
        str2 += to_string(quotient);

        mod = mod % d;

    } while (mod != 0 && modMap.find(mod) == modMap.end());

    if (mod != 0) {
        str1 += str2.substr(0, modMap[mod]);
        str2 = str2.substr(modMap[mod]);

        return str1 + (str2.length() == 0 ? "" : "(" + str2 + ")");
    }

    else return str1 + str2;
}

int main()
{
    int n, d;
    
    cout<<"Enter numerator and denominator: ";
    cin>>n>>d;
    
    cout<<"Decimal: "<<fractionToDecimal(n, d)<<endl;
}