/* Source - https://leetcode.com/problems/russian-doll-envelopes/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

struct Envelope {
int w, h;

    Envelope(int a = 0, int b = 0) {
        w = a;
        h = b;
    }

};

static bool comparator(Envelope e1, Envelope e2) {
    if (e1.w == e2.w)
        return e1.h > e2.h;

    return e1.w < e2.w;
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.size() == 0)
        return 0;
    
    int n = envelopes.size();
    
    vector<Envelope> en;
    
    for (int i = 0; i < n; i++)
        en.push_back(Envelope(envelopes[i][0], envelopes[i][1]));

    sort(en.begin(), en.end(), comparator);

    vector<int> dp(n);

    dp[0] = 1;

    int longIncSub = 1;

    for (int i = 1; i < n; i++) {
        int subLen = 0;

        for (int j = i - 1; j >= 0; j--) {
            if (en[i].h > en[j].h)
                subLen = max(subLen, dp[j]);
        }

        dp[i] = subLen + 1;

        longIncSub = max(longIncSub, dp[i]);
    }

    return longIncSub;
}

int main()
{
    int n;

    cout<<"Enter number of envelopes: ";
    cin>>n;
    
    vector<vector<int>> envelopes(n, vector<int> (2));
    int a, b;
    
    cout<<"Enter width and height of each envelope: "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>envelopes[i][0];
        cin>>envelopes[i][1];
    }
    
    cout<<"Maximum number of envelopes that can be put one inside other: "<<maxEnvelopes(envelopes)<<endl;
}