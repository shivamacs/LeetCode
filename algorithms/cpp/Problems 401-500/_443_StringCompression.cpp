/*  Source - https://leetcode.com/problems/string-compression/
    Author - Shivam Arora
*/
#include <iostream>
#include <vector>
#include <string>

int compress(std::vector<char>& chars) {
    int n = chars.size();
    int curr = 0;
    int index = 0;

    while(curr < n) {
        char currChar = chars[curr];
        int currCount = 0;

        while(curr < n && chars[curr] == currChar) {
            curr++;
            currCount++;
        }

        chars[index++] = currChar;

        if(currCount > 1) {
            std::string digits = "";

            while(currCount) {
                int digit = currCount % 10;
                digits += std::to_string(digit);
                currCount /= 10;
            }

            for(int i = digits.size() - 1; i >= 0; i--)
                chars[index + i] = digits[digits.size() - i - 1];

            index += digits.size();
        }
    }

    return index;
}

int main() {
    int n;
    std::cout<<"Enter the length of the string: ";
    std::cin>>n;

    std::vector<char> chars(n);
    std::cout<<"Enter the string you want to compress: ";
    for(int i = 0; i < chars.size(); i++)
        std::cin>>chars[i];

    int index = compress(chars);
    std::cout<<"Compressed string: ";
    for(int i = 0; i < index; i++)
        std::cout<<chars[i];
    std::cout<<std::endl;
}