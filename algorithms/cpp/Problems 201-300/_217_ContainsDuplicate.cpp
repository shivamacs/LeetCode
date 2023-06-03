/*  Source - https://leetcode.com/problems/contains-duplicate/
    Author - Shivam Arora
*/
#include <vector>
#include <iostream>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> unique;
    
    for(int num : nums) {
        if (unique.find(num) != unique.end())
            return true;
        
        unique.insert(num);
    }
    
    return false;
}

int main() {
    int n;
    std::cout<<"Enter number of elements: ";
    std::cin>>n;

    std::vector<int> nums(n);

    std::cout<<"Enter elements: "<<std::endl;
    for(int i = 0; i < n; i++)
        std::cin>>nums[i];

    std::cout<<"Contains duplicate? "<<std::boolalpha<<containsDuplicate(nums)<<std::endl;
}