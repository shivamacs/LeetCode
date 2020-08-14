/* Source - https://leetcode.com/problems/k-similar-strings/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

string swap(int i, int j, string s) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    
    return s;
}

int kSimilarity(string A, string B) {
    deque<pair<string, int>> dq;
    unordered_set<string> set;

    set.insert(A);
    dq.push_back(make_pair(A, 0));
    
    while(!dq.empty()) {
        pair<string, int> front = dq.front();
        dq.pop_front();
        
        string s = front.first;
        int K = front.second;
                                        
        if(s.compare(B) == 0)
            return K;
        
        int i = 0, pushed = 0;
        bool flag = false;
        
        while(s[i] == B[i])
            i++;
                                            
        for(int j = i + 1; j < s.length(); j++) {
            if(s[j] == B[i]) {
                string res = swap(i, j, s);
                            
                if(set.find(res) == set.end()) {                        
                    if(res[j] == B[j]) {
                        while(pushed > 0) {
                            dq.pop_back();
                            pushed--;
                        }
                        
                        flag = true;
                    } else
                        pushed++;
                    
                    set.insert(res);
                    dq.push_back(make_pair(res, K + 1));
                }
                
                if(flag)
                    break;
            }
        }
    }
    
    return 0;
}

int main()
{
    string A, B;

    cout<<"Enter string A: ";
    cin>>A;

    cout<<"Enter string B: ";
    cin>>B;

    cout<<"Minimum swaps through which A can be converted to B: "<<kSimilarity(A, B)<<endl;
}