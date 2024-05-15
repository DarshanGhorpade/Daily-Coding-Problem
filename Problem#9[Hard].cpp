
/*
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>
#include <algorithm>

int largestSumNonAdjacent(std::vector<int>& nums) {
    if(nums.empty()) return 0;
    
    int include = 0, exclude = 0;
    
    for(int num : nums) {
        int new_exclude = std::max(include, exclude);
        include = exclude + num;
        exclude = new_exclude;
    }
    
    return std::max(include, exclude);
}


int main() {
    std::vector<int> nums1 = { 2, 4, 6, 2, 5 };
    std::vector<int> nums2 = { 5, 1, 1, 5 };
    
    std::cout << "Largest sum of non-adjacent numbers in [2, 4, 6, 2, 5]: " << largestSumNonAdjacent(nums1) << std::endl;
    std::cout << "Largest sum of non-adjacent numbers in [5, 1, 1, 5]: " << largestSumNonAdjacent(nums2) << std::endl;
    return 0;
}
