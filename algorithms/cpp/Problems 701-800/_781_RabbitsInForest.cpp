/* Source - https://leetcode.com/problems/rabbits-in-forest/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int>& answers) {
    map<int, int> answersCount;
    map<int, int>::iterator iter;

    int rabbits = 0, groupCount = 0;

    for (int i = 0; i < answers.size(); i++) answersCount[answers[i]]++;

    for (iter = answersCount.begin(); iter != answersCount.end(); ++iter) {
        if (iter->first + 1 >= iter->second) groupCount = 1;
        if (iter->first + 1 < iter->second) groupCount = ceil(float(iter->second)/float(iter->first + 1));
        
        rabbits += groupCount * (iter->first + 1);
    }

    return rabbits;
}

int main()
{
    int n;
    cout<<"Enter the number of answers: ";
    cin>>n;

    vector<int> answers(n);
    cout<<"Enter answers: ";
    for (int i = 0; i < n; i++) cin>>answers[i];

    cout<<"Number of rabbits in forests: "<<numRabbits(answers)<<endl;
}