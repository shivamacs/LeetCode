/*  Source - https://leetcode.com/problems/rotate-string/
    Author - Shivam Arora
*/
#include <iostream>
#include <string>

bool rotateString(std::string& s, std::string& goal) {
    return s.length() == goal.length() && (s + s).find(goal) != std::string::npos;
}

int main() {
    std::string s, goal;
    std::cout<<"Enter original string: ";
    std::cin>>s;
    std::cout<<"Enter goal string after some shifts: ";
    std::cin>>goal;

    std::cout<<"Can the original string become goal string? "<<std::boolalpha<<rotateString(s, goal)<<std::endl;
}