/* Source - https://leetcode.com/problems/boats-to-save-people/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int i = 0, j = people.size() - 1, boats = 0;

    sort(people.begin(), people.end());
    
    while (i <= j) {
        if (people[j] == limit)
            boats++;
        
        else if (people[i] + people[j] <= limit) {
            boats++;
            i++;
        }
        
        else boats++;
        
        j--;
    }
    
    return boats;
}

int main()
{
    int n, limit;

    cout<<"Enter number of people: ";
    cin>>n;

    vector<int> people(n);

    cout<<"Enter weights of people: ";
    for (int i = 0; i < n; i++)
        cin>>people[i];

    cout<<"Enter weight limit: ";
    cin>>limit;

    cout<<"Boats required to save people: "<<numRescueBoats(people, limit)<<endl;
}