/* Source - https://www.lintcode.com/problem/boolean-parenthesization/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int countParenth(string &symb, string &oper) {
    int n = symb.length();
    pair<int, int> dp[n][n];
    
    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(k == 0)
                dp[i][j] = symb[i] == 'T' ? make_pair(1, 0) : make_pair(0, 1);
            else {
                pair<int, int> ways;
                
                for(int cut = i; cut < j; cut++) {
                    pair<int, int> left = dp[i][cut];
                    pair<int, int> right = dp[cut + 1][j];
                    
                    if(oper[cut] == '&') {
                        ways.first += left.first * right.first;
                        ways.second += left.first * right.second + left.second * right.first + left.second * right.second;
                    } else if(oper[cut] == '|') {
                        ways.first += left.first * right.first + left.first * right.second + left.second * right.first;
                        ways.second += left.second * right.second;
                    } else {
                        ways.first += left.first * right.second + left.second * right.first;
                        ways.second += left.first * right.first + left.second * right.second;
                    }
                }
                
                dp[i][j] = ways;
            }
        }
    }
    
    return dp[0][n - 1].first;
}

int main()
{
    string symb, oper;

    cout<<"Enter the expression in 2 parts,"<<endl;
    cout<<"I. Enter the string of symbols (T, F): ";
    cin>>symb;

    cout<<"II. Enter the string of operators (&, |, ^): ";
    cin>>oper;

    cout<<"Number of ways of parenthesization so that the value of expression evaluates to true: "<<countParenth(symb, oper)<<endl;
}