// Two Sum – LeetCode Problem #1
// --------------------------------
// Problem:
// Given an array of integers nums and an integer target, return the indices of
// the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not
// use the same element twice.
//
// Example:
// Input: nums = [2, 7, 11, 15], target = 9
// Output: [0, 1]
//
// Approach:
// - Use a hash map to store the difference (target - current number).
// - If the current number exists in the map, we found the pair.
// Time Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
