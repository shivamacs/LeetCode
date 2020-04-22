/* Source - https://www.lintcode.com/problem/paint-fence/description/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numWays(int n, int k) {
    int s = 0, d = k, t = s + d;
    
    for (int i = 2; i <= n; i++) {
        s = d;
        d = t * (k - 1);
        t = s + d;
    }
    
    return t;
}

int main()
{
    int n, k;
    
    cout<<"Enter number of fences: ";
    cin>>n;

    cout<<"Enter number of colors: ";
    cin>>k;

    cout<<"Number of ways the fences can be painted with k colors such that atmost two fences are consecutive: "<<numWays(n, k)<<endl;
}