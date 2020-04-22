/* Source - https://leetcode.com/problems/decode-ways/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int countEncodings(string s) {
    if (s.length() == 1)
        return 1;
    
    int n = s.length();
        
    int asf = 0, asfm1 = 1, asfm2 = 0; 
    
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            if (s[i - 1] != '0' && (s[i - 1] - '0') <= 2)
                asf = (i == 1) ? 1 : asfm2;
                
            else return 0;
        }
        
        else {
            int another = stoi(string(1, s[i - 1]) + string(1, s[i]));
    
            if (another >= 10 && another <= 26)
                asf = (i == 1) ? 2 : asfm1 + asfm2;
    
            else asf = asfm1;
        }
        
        asfm2 = asfm1;
        asfm1 = asf;
    }
    
    return asf;
}

int main()
{
    string s;

    cout<<"Enter encoded string: ";
    cin>>s;
    
    cout<<"Total possible decoding messages: "<<countEncodings(s)<<endl;
}