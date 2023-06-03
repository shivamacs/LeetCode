/* Source - https://leetcode.com/problems/gray-code/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
    if(n == 0)
        return {0};
    
    vector<int> codes = grayCode(n - 1);
    vector<int> result(codes);
    
    for(int i = codes.size() - 1; i >= 0; i--)
        result.push_back((1<<(n - 1)) + codes[i]);
    
    return result;
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    vector<int> result = grayCode(n);
    cout<<n<<"-bit gray code sequence: ";
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
}