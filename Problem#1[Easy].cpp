/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/


#include <iostream>
#include <vector>
#include <unordered_set>

bool hasPairWithSum(std::vector<int>& nums, int k) {
    std::unordered_set<int> seen;
    for(int num : nums){
        if(seen.count(k - num)){
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {10, 15, 3, 7};
    int k1 = 17;

    std::vector<int> nums2 = {1, 2, 3, 4};
    int k2 = 8;

    std::cout << "List [10, 15, 3, 7] with k = 17: " << (hasPairWithSum(nums1, k1) ? "True" : "False") << std::endl;
    std::cout << "List [1, 2, 3, 4] with k = 8: " << (hasPairWithSum(nums2, k2) ? "True" : "False") << std::endl;

    return 0;
}
