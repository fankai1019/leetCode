#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

// Boyer-Moore majority vote algorithm;
// This algorithm is an algorithm for finding the majority of a sequence of
// elements using linear time and constant space;

class Solution {
   public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0;
        int result;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                result = nums[i];
                count++;
            } else if (result == nums[i])
                count++;
            else
                count--;
        }
        return result;
    }
};

class Solution2 {
   public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int> mymap;
        int max = 0;
        for (int i = 0; i < nums.size(); ++i)
            max = std::max(max, ++mymap[nums[i]]);

        for (auto& i : mymap)
            if (i.second == max) return i.first;
        return 0;
    }
};

int main() {
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution a;
    std::cout << a.majorityElement(nums);
    return 0;
}
